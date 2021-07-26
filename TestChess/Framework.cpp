#include "Framework.h"

Framework::Framework(int i)
{
	if (!window.Init()) return;
	if (!gfx.GraphicsInit(window.GetWindow())) return;
	
	
	if (!Map.InitBattelGround("Map.bmp", window.GetSurface()->format,
		gfx.GetRenderer(), 0, 0
	)
		) return;
	PlayerTurnControl = Player(Map.MapSection, true);
	PlayerTurnControl.InitAllFigure(
		window.GetSurface()->format, gfx.GetRenderer());

	PlaterEnemyControl = Player(Map.MapSection, false);
	PlaterEnemyControl.InitAllFigure(
		window.GetSurface()->format, gfx.GetRenderer());

	Inited = true;
}

bool Framework::Events()
{
	SDL_Event Event;

	while (SDL_PollEvent(&Event) != 0)
	{
		switch (Event.type)
		{
		case SDL_MOUSEBUTTONDOWN:
			if (Event.button.button == SDL_BUTTON_LEFT)
			{
				if (Cntroler.ObjectChossed())
				{
					if (Turn)
						Cntroler.SetControlFigure(PlayerTurnControl.GetAllFigures());
					else
						Cntroler.SetControlFigure(PlaterEnemyControl.GetAllFigures());

					if (Cntroler.GetTempFigure() != nullptr)
					{
						if (Turn)
							PairShow = FindAllTurnToGo(Map.MapSection,
								PlayerTurnControl.GetAllFigures(),
								PlaterEnemyControl.GetAllFigures());
						else
							PairShow = FindAllTurnToGo(Map.MapSection,
								PlaterEnemyControl.GetAllFigures(),
								PlayerTurnControl.GetAllFigures());
						ShowTurn();
					}
				}
				else if (!Cntroler.ObjectChossed())
				{
					Cntroler.SetPossition(PairShow);
				}
			}
			else if (Event.button.button == SDL_BUTTON_RIGHT)
			{
				Cntroler.DiscardFigure();
			}
			break;
		case SDL_QUIT:
			return false;
		}
	}
	if (Turn)
	{		Attack(PlaterEnemyControl.GetAllFigures(), Cntroler.GetX(), Cntroler.GetY());
	}
	else
	{
		Attack(PlayerTurnControl.GetAllFigures(), Cntroler.GetX(), Cntroler.GetY());
	}

	Cntroler.MoveObject(Turn);

	if (Cntroler.ObjectChossed())
	{
		Show.clear();
	}


	return true;
}

void Framework::Graphics()
{
	gfx.ClearWindow();

	// Draw Map
	gfx.DrawTexture(Map.GetSprite()->GetPtrTextrure(), Map.GetRect());
	
	// Green Box

	gfx.DrawGreenBox(Show);

	// Draw Player 1 figure

	gfx.DrawPlayerTable(PlayerTurnControl.GetAllFigures());
	gfx.DrawPlayerTable(PlaterEnemyControl.GetAllFigures());

	gfx.UpdatWindow();
}

bool Framework::MainLoop()
{
	if (!Events()) return false;
	
	Graphics();
	
	return true;
}

void Framework::ShowTurn()
{
	for (int i = 0; i < PairShow.size(); i++)
	{
		Show.push_back(Object());
		Show[i].InitAll(My_Str("GreenCube.bmp"),window.GetSurface()->format,gfx.GetRenderer(),
			PairShow[i].x - START_POSSITION_ON_GROUND_STRIP, 
			PairShow[i].y - START_POSSITION_ON_GROUND_STRIP
		);
	}
}

std::vector<DoublePair> Framework::FindAllTurnToGo(DoublePair MapSec[8][8],
	std::vector<std::tuple< TypesFigurs, Types, bool >>& AllFriendlyFigure,
	std::vector<std::tuple< TypesFigurs, Types, bool >>& AllEnemyFigure
)
{
	std::vector<DoublePair> BufferGo;
	std::vector<DoublePair> EnemyBufeer = FigureMap(Map.MapSection ,AllEnemyFigure);
	std::vector<DoublePair> FriendlyBuffer = FigureMap(Map.MapSection, AllFriendlyFigure);

	DoublePair	CurrentPossition = Cntroler.GetDoublePossition();
	// Controler Change Possition
	Cntroler.SetDoublePossition(MapSec);

	for (int i = 0; i < FriendlyBuffer.size(); i++)
		if (FriendlyBuffer[i].x == CurrentPossition.x &&
			FriendlyBuffer[i].y == CurrentPossition.y)
				FriendlyBuffer.erase(FriendlyBuffer.begin() + i);

	switch (Cntroler.GetTypesFigur())
	{
	case PAWN:
		BufferGo = Cntroler.GetTempFigure()->Pen->
			 GetPossitionToGo(FriendlyBuffer, EnemyBufeer, CurrentPossition);
		break;
	case KHIGHT:
		BufferGo = Cntroler.GetTempFigure()->Kni->
			GetPossitionToGo(FriendlyBuffer, EnemyBufeer, CurrentPossition, Map.MapSection);
		break;
	case BISHOP:
		BufferGo = Cntroler.GetTempFigure()->Bish->
			GetPossitionToGo(FriendlyBuffer, EnemyBufeer, CurrentPossition, Map.MapSection);
		break;
	case ROOK:
		BufferGo = Cntroler.GetTempFigure()->Rooks->
			GetPossitionToGo(FriendlyBuffer, EnemyBufeer, CurrentPossition, Map.MapSection);
		break;
	case QUEEN:
		BufferGo = Cntroler.GetTempFigure()->Que->
			GetPossitionToGo(FriendlyBuffer, EnemyBufeer, CurrentPossition, Map.MapSection);
		break;
	case KING:
		BufferGo = Cntroler.GetTempFigure()->Kin->
			GetPossitionToGo(FriendlyBuffer, EnemyBufeer, CurrentPossition, Map.MapSection);
		break;
	}
	return BufferGo;
}

std::vector<DoublePair>	Framework::FigureMap(
	DoublePair ArrayOfMap[8][8],
	std::vector<std::tuple< TypesFigurs, Types, bool >>& Buffer)
{
	std::vector<DoublePair>	RetBuffer;
	
	for (auto i : Buffer)
	{
		switch (std::get<First>(i))
		{
		case PAWN:
			RetBuffer.push_back(
				FindMapPoss(ArrayOfMap, 
					std::get<Second>(i).Pen->GetRect()->x,
					std::get<Second>(i).Pen->GetRect()->y, 
					std::get<Second>(i).Pen->GetRect()->w,
					std::get<Second>(i).Pen->GetRect()->h ));
			break;
		case KHIGHT:
			RetBuffer.push_back(
				FindMapPoss(ArrayOfMap,
					std::get<Second>(i).Kni->GetRect()->x,
					std::get<Second>(i).Kni->GetRect()->y,
					std::get<Second>(i).Kni->GetRect()->w,
					std::get<Second>(i).Kni->GetRect()->h));
			break;
		case BISHOP:
			RetBuffer.push_back(
				FindMapPoss(ArrayOfMap,
					std::get<Second>(i).Bish->GetRect()->x,
					std::get<Second>(i).Bish->GetRect()->y,
					std::get<Second>(i).Bish->GetRect()->w,
					std::get<Second>(i).Bish->GetRect()->h));
			break;
		case ROOK:
			RetBuffer.push_back(
				FindMapPoss(ArrayOfMap,
					std::get<Second>(i).Rooks->GetRect()->x,
					std::get<Second>(i).Rooks->GetRect()->y,
					std::get<Second>(i).Rooks->GetRect()->w,
					std::get<Second>(i).Rooks->GetRect()->h));
			break;
		case QUEEN:
			RetBuffer.push_back(
				FindMapPoss(ArrayOfMap,
					std::get<Second>(i).Que->GetRect()->x,
					std::get<Second>(i).Que->GetRect()->y,
					std::get<Second>(i).Que->GetRect()->w,
					std::get<Second>(i).Que->GetRect()->h));
			break;
		case KING:
			RetBuffer.push_back(
				FindMapPoss(ArrayOfMap,
					std::get<Second>(i).Kin->GetRect()->x,
					std::get<Second>(i).Kin->GetRect()->y,
					std::get<Second>(i).Kin->GetRect()->w,
					std::get<Second>(i).Kin->GetRect()->h));
			break;
		}
	}
	return RetBuffer;
}

DoublePair Framework::FindMapPoss(DoublePair Map[8][8], 
	int x, int y, int w, int h)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (Map[i][j].x >= x && Map[i][j].x <= x + w)
			{
				if (Map[i][j].y >= y && Map[i][j].y <= y + h)
				{
					return DoublePair(Map[i][j].x, Map[i][j].y);
				}
			}
		}
	}
}

void Framework::Attack(std::vector<std::tuple< TypesFigurs, Types, bool >>& Enemy,
	int x, int y)
{
	if (!Cntroler.ObjectChossed() && (x != 0 && y != 0))
	{
		int Triger = -1; bool Clear = false;
		for (int i = 0; i < Enemy.size(); i++)
		{
			switch (std::get<First>(Enemy[i]))
			{
			case PAWN:
				if (std::get<Second>(Enemy[i]).Pen->GetRect()->x == x
					&& y == std::get<Second>(Enemy[i]).Pen->GetRect()->y)
				{
					Triger = i; Clear = true;
				}
				break;
			case KHIGHT:
				if (std::get<Second>(Enemy[i]).Kni->GetRect()->x == x
					&& y == std::get<Second>(Enemy[i]).Kni->GetRect()->y)
				{
					Triger = i; Clear = true;
				}
				break;
			case BISHOP:
				if (std::get<Second>(Enemy[i]).Bish->GetRect()->x == x
					&& y == std::get<Second>(Enemy[i]).Bish->GetRect()->y)
				{
					Triger = i; Clear = true;
				}
				break;
			case ROOK:
				if (std::get<Second>(Enemy[i]).Rooks->GetRect()->x == x
					&& y == std::get<Second>(Enemy[i]).Rooks->GetRect()->y)
				{
					Triger = i; Clear = true;
				}
				break;
			case QUEEN:
				if (std::get<Second>(Enemy[i]).Que->GetRect()->x == x
					&& y == std::get<Second>(Enemy[i]).Que->GetRect()->y)
				{
					Triger = i; Clear = true;
				}
				break;
			case KING:
				if (std::get<Second>(Enemy[i]).Kin->GetRect()->x == x
					&& y == std::get<Second>(Enemy[i]).Kin->GetRect()->y)
				{
					Triger = i; Clear = true;
				}
				break;
			}
		}
		if (Clear)	Enemy.erase(Enemy.begin() + Triger);
	}
}