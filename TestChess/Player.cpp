#include "Player.h"

Player::Player(DoublePair AllSet[8][8], bool Side)
	: SideOfPlayer(Side)
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			AllTurnPosiition[i][j] = AllSet[i][j];
}

bool Player::InitAllFigure(SDL_PixelFormat* Fmt, SDL_Renderer* Renderer)
{
	int Possition = (SideOfPlayer) ? 6 : 0, XStart = 0;

	InitArray();

	for (int i = 0, PossOfFigure = 0; i < MAX_TYPES_OF_FIGURE; i++, XStart++)
	{
		if (i == SIZE_OF_ARRAY_ONBATTELGROUND) 
		{ Possition++; XStart = 0; }
		My_Str NameOfFigure;

		switch (AllFigures[i].first)
		{
		case PAWN:
			std::get<Second>(AllFigure[i]).Pen = new Peon(PAWN, SideOfPlayer);
			NameOfFigure = (SideOfPlayer) ? My_Str("Pawn.bmp") : My_Str("PawnB.bmp");

			if (!std::get<Second>(AllFigure[i]).Pen->InitAll(
				My_Str(NameOfFigure), Fmt, Renderer,
				AllTurnPosiition[Possition][XStart].x - WIDHT_AND_HIGHT_OF_FIGURE_SPRITE,
				AllTurnPosiition[Possition][XStart].y - WIDHT_AND_HIGHT_OF_FIGURE_SPRITE)
				) return false;

			break;
		case KHIGHT:
			std::get<Second>(AllFigure[i]).Kni = new Khights(KHIGHT, SideOfPlayer);
			NameOfFigure = (SideOfPlayer) ? My_Str("Khight.bmp") : My_Str("KhightB.bmp");

			if (!std::get<Second>(AllFigure[i]).Kni->InitAll(
				My_Str(NameOfFigure), Fmt, Renderer,
				AllTurnPosiition[Possition][XStart].x - WIDHT_AND_HIGHT_OF_FIGURE_SPRITE,
				AllTurnPosiition[Possition][XStart].y - WIDHT_AND_HIGHT_OF_FIGURE_SPRITE)
				) return false;

			break;
		case BISHOP:
			std::get<Second>(AllFigure[i]).Bish = new Bishops(BISHOP, SideOfPlayer);
			NameOfFigure = (SideOfPlayer) ? My_Str("Bishop.bmp") : My_Str("BishopB.bmp");

			if (!std::get<Second>(AllFigure[i]).Bish->InitAll(
				My_Str(NameOfFigure), Fmt, Renderer,
				AllTurnPosiition[Possition][XStart].x - WIDHT_AND_HIGHT_OF_FIGURE_SPRITE,
				AllTurnPosiition[Possition][XStart].y - WIDHT_AND_HIGHT_OF_FIGURE_SPRITE)
				) return false;

			break;
		case ROOK:
			std::get<Second>(AllFigure[i]).Rooks = new Rook(ROOK, SideOfPlayer);
			NameOfFigure = (SideOfPlayer) ? My_Str("Rook.bmp") : My_Str("RookB.bmp");

			if (!std::get<Second>(AllFigure[i]).Rooks->InitAll(
				My_Str(NameOfFigure), Fmt, Renderer,
				AllTurnPosiition[Possition][XStart].x - WIDHT_AND_HIGHT_OF_FIGURE_SPRITE,
				AllTurnPosiition[Possition][XStart].y - WIDHT_AND_HIGHT_OF_FIGURE_SPRITE)
				) return false;

			break;
		case QUEEN:
			std::get<Second>(AllFigure[i]).Que = new Queens(QUEEN, SideOfPlayer);
			NameOfFigure = (SideOfPlayer) ? My_Str("Queen.bmp") : My_Str("QueenB.bmp");

			if (!std::get<Second>(AllFigure[i]).Que->InitAll(
				My_Str(NameOfFigure), Fmt, Renderer,
				AllTurnPosiition[Possition][XStart].x - WIDHT_AND_HIGHT_OF_FIGURE_SPRITE,
				AllTurnPosiition[Possition][XStart].y - WIDHT_AND_HIGHT_OF_FIGURE_SPRITE)
				) return false;

			break;
		case KING:
			std::get<Second>(AllFigure[i]).Kin = new Kings(KING, SideOfPlayer);
			NameOfFigure = (SideOfPlayer) ? My_Str("King.bmp") : My_Str("KingB.bmp");

			if (!std::get<Second>(AllFigure[i]).Kin->InitAll(
				My_Str(NameOfFigure), Fmt, Renderer,
				AllTurnPosiition[Possition][XStart].x - WIDHT_AND_HIGHT_OF_FIGURE_SPRITE,
				AllTurnPosiition[Possition][XStart].y - WIDHT_AND_HIGHT_OF_FIGURE_SPRITE)
				) return false;

			break;
		}
	}
	return true;
}

void Player::InitArray()
{
	int i = 0;
	if (SideOfPlayer)
	{
		for (; i < SIZE_OF_ARRAY_ONBATTELGROUND; i++)
		{
			AllFigure.push_back(std::make_tuple(PAWN, Types(), true));
			AllFigures[i].first = PAWN;
		}
	}
	AllFigure.push_back(std::make_tuple(ROOK, Types(), true));
	AllFigures[i++].first = ROOK;
	AllFigure.push_back(std::make_tuple(KHIGHT, Types(), true));
	AllFigures[i++].first = KHIGHT;
	AllFigure.push_back(std::make_tuple(BISHOP, Types(), true));
	AllFigures[i++].first = BISHOP;
	AllFigure.push_back(std::make_tuple(QUEEN, Types(), true));
	AllFigures[i++].first = QUEEN;
	AllFigure.push_back(std::make_tuple(KING, Types(), true));
	AllFigures[i++].first = KING;
	AllFigure.push_back(std::make_tuple(BISHOP, Types(), true));
	AllFigures[i++].first = BISHOP;
	AllFigure.push_back(std::make_tuple(KHIGHT, Types(), true));
	AllFigures[i++].first = KHIGHT;
	AllFigure.push_back(std::make_tuple(ROOK, Types(), true));
	AllFigures[i++].first = ROOK;

	if (SideOfPlayer == false)
	{
		for ( ; i < MAX_TYPES_OF_FIGURE; i++)
		{
			AllFigure.push_back(std::make_tuple(PAWN, Types(), true));
			AllFigures[i].first = PAWN;
		}
	}

}