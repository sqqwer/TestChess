#ifndef PlayerControl
#define PlayerControl

#include "General.h"
#include "Peon.h"
#include "Struc.h"
#include "General.h"

class Player
{
public:
	Player() {};
	Player(DoublePair AllSet[8][8], bool Side);
	bool InitAllFigure(SDL_PixelFormat* Fmt, SDL_Renderer* Renderer);
	std::vector<std::tuple< TypesFigurs, Types, bool >>& GetAllFigures()
	{
		return AllFigure;
	}
private:
	void InitArray();

private:
	bool SideOfPlayer;

	DoublePair AllTurnPosiition[8][8];

	std::vector<DoublePair>	CanTurn;

	std::vector<std::tuple< TypesFigurs, Types, bool >> AllFigure;
	std::pair<TypesFigurs, Types>	AllFigures[16];
};

#endif // !PlayerControl