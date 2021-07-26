#include "Controll.h"

void Controll::SetPossition(std::vector<DoublePair> FindPoint)
{
	if (!ObjectChossed() && !Control && FindPoint.size() > 0)
	{
		FindChoosedPoint(FindPoint);
		cout << "Set possition : " << x << '\t' << y << endl;
		//Turn = (Turn) ? false : true;
	}
}

void Controll::MoveObject(bool& Turn)
{
	if (!ObjectChossed() && Control)
	{
		if ( TempChossedObject->Pen->GetRect()->x == x &&
			TempChossedObject->Pen->GetRect()->y == y )
		{
			switch (ChossedType)
			{
			case PAWN:
				TempChossedObject->Pen->UpdateCount();
				break;
			case KHIGHT:
				TempChossedObject->Kni->UpdateCount();
				break;
			case BISHOP:
				TempChossedObject->Bish->UpdateCount();
				break;
			case ROOK:
				TempChossedObject->Rooks->UpdateCount();
				break;
			case QUEEN:
				TempChossedObject->Que->UpdateCount();
				break;
			case KING:
				TempChossedObject->Kin->UpdateCount();
				break;
			}
			
			TempChossedObject = nullptr; Control = false;
			this->x = 0; this->y = 0;
			Turn = (Turn) ? false : true;
		}
		else
		{
			
			//if (((TempChossedObject->GetRect()->x - x) < y &&
			//	TempChossedObject->GetRect()->x != x))
			{
				if (TempChossedObject->Pen->GetRect()->x < x)
					TempChossedObject->Pen->GetRect()->x++;
				else if (TempChossedObject->Pen->GetRect()->x > x)
					TempChossedObject->Pen->GetRect()->x--;
			}
			//else
			{
				if (TempChossedObject->Pen->GetRect()->y < y)
					TempChossedObject->Pen->GetRect()->y++;
				else if (TempChossedObject->Pen->GetRect()->y > y)
					TempChossedObject->Pen->GetRect()->y--;
			}			
			//cout << "Possition : " << TempChossedObject->Pen->GetRect()->x
			//<< '\t' << TempChossedObject->Pen->GetRect()->y << endl;
		}
	}
}

void Controll::DiscardFigure()
{
	if (!ObjectChossed() && !Control)
	{
		TempChossedObject = nullptr; Control = false;
		cout << "discard unit" << endl;
		this->x = 0; this->y = 0;
	}
}

void Controll::FindChoosedPoint(std::vector<DoublePair> FindPoint)
{
	int x, y;
	SDL_GetMouseState(&x, &y);

	for (int i = 0; i < FindPoint.size(); i++)
	{
		if (x >= FindPoint[i].x - 20 && x <= FindPoint[i].x + 20)
		{
			if (y >= FindPoint[i].y - 20 && y <= FindPoint[i].y + 20)
			{
				this->x = FindPoint[i].x - 24;
				this->y = FindPoint[i].y - 24;
				Control = true;
				return;
			}
		}
	}
}

void Controll::SetControlFigure(
	std::vector<std::tuple< TypesFigurs, Types, bool >>& AllFigure)
{
	int x, y;
	SDL_GetMouseState(&x, &y);

	for (int i = 0; i < AllFigure.size(); i++)
	{
		switch (std::get<First>(AllFigure[i]))
		{
		case PAWN:
			if (FindPossition(
				std::get<Second>(AllFigure[i]).Pen->GetRect()->x,
				std::get<Second>(AllFigure[i]).Pen->GetRect()->y,
				std::get<Second>(AllFigure[i]).Pen->GetRect()->w,
				std::get<Second>(AllFigure[i]).Pen->GetRect()->h,
				x, y
			))
			{
				ChossedType = PAWN;
				TempChossedObject = &std::get<Second>(AllFigure[i]);

				Possition = DoublePair(
					std::get<Second>(AllFigure[i]).Pen->GetRect()->x,
					std::get<Second>(AllFigure[i]).Pen->GetRect()->y
				);

				cout << "Set Control : " <<  endl;
				return;
			}
			break;
		case KHIGHT:
			if (FindPossition(
				std::get<Second>(AllFigure[i]).Pen->GetRect()->x,
				std::get<Second>(AllFigure[i]).Pen->GetRect()->y,
				std::get<Second>(AllFigure[i]).Pen->GetRect()->w,
				std::get<Second>(AllFigure[i]).Pen->GetRect()->h,
				x, y
			))
			{
				ChossedType = KHIGHT;
				TempChossedObject = &std::get<Second>(AllFigure[i]);

				Possition = DoublePair(
					std::get<Second>(AllFigure[i]).Kni->GetRect()->x,
					std::get<Second>(AllFigure[i]).Kni->GetRect()->y
				);

				cout << "Set Control : " << endl;
				return;
			}
			break;
		case BISHOP:
			if (FindPossition(
				std::get<Second>(AllFigure[i]).Pen->GetRect()->x,
				std::get<Second>(AllFigure[i]).Pen->GetRect()->y,
				std::get<Second>(AllFigure[i]).Pen->GetRect()->w,
				std::get<Second>(AllFigure[i]).Pen->GetRect()->h,
				x, y
			))
			{
				ChossedType = BISHOP;
				TempChossedObject = &std::get<Second>(AllFigure[i]);

				Possition = DoublePair(
					std::get<Second>(AllFigure[i]).Bish->GetRect()->x,
					std::get<Second>(AllFigure[i]).Bish->GetRect()->y
				);

				cout << "Set Control : " << endl;
				return;
			}
			break;
		case ROOK:
			if (FindPossition(
				std::get<Second>(AllFigure[i]).Pen->GetRect()->x,
				std::get<Second>(AllFigure[i]).Pen->GetRect()->y,
				std::get<Second>(AllFigure[i]).Pen->GetRect()->w,
				std::get<Second>(AllFigure[i]).Pen->GetRect()->h,
				x, y
			))
			{
				ChossedType = ROOK;
				TempChossedObject = &std::get<Second>(AllFigure[i]);

				Possition = DoublePair(
					std::get<Second>(AllFigure[i]).Rooks->GetRect()->x,
					std::get<Second>(AllFigure[i]).Rooks->GetRect()->y
				);

				cout << "Set Control : " << endl;
				return;
			}
			break;
		case QUEEN:
			if (FindPossition(
				std::get<Second>(AllFigure[i]).Pen->GetRect()->x,
				std::get<Second>(AllFigure[i]).Pen->GetRect()->y,
				std::get<Second>(AllFigure[i]).Pen->GetRect()->w,
				std::get<Second>(AllFigure[i]).Pen->GetRect()->h,
				x, y
			))
			{
				ChossedType = QUEEN;
				TempChossedObject = &std::get<Second>(AllFigure[i]);

				Possition = DoublePair(
					std::get<Second>(AllFigure[i]).Que->GetRect()->x,
					std::get<Second>(AllFigure[i]).Que->GetRect()->y
				);

				cout << "Set Control : " << endl;
				return;
			}
			break;
		case KING:
			if (FindPossition(
				std::get<Second>(AllFigure[i]).Pen->GetRect()->x,
				std::get<Second>(AllFigure[i]).Pen->GetRect()->y,
				std::get<Second>(AllFigure[i]).Pen->GetRect()->w,
				std::get<Second>(AllFigure[i]).Pen->GetRect()->h,
				x, y
			))
			{
				ChossedType = KING;
				TempChossedObject = &std::get<Second>(AllFigure[i]);

				Possition = DoublePair(
					std::get<Second>(AllFigure[i]).Kin->GetRect()->x,
					std::get<Second>(AllFigure[i]).Kin->GetRect()->y
				);

				cout << "Set Control : " << endl;
				return;
			}
			break;
		}
	}
}

bool Controll::FindPossition(
	const int FigurPossX, const int FigurPossY,
	const int FigurPossW, const int FigurPossH,
	const int MousePossX, const int MousePossY
)
{
	if (MousePossX >= FigurPossX && 
		MousePossX <= FigurPossX + FigurPossW)
	{
		if (MousePossY >= FigurPossY && 
			MousePossY <= FigurPossY + FigurPossH)
		{
			return true;
		}
	}
	return false;
}