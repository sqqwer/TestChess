#ifndef MainFramework
#define MainFramework

#include "General.h"
#include "GFX.h"
#include "Window.h"
#include "Object.h"
#include "Controll.h"
#include "BattelGround.h"

// Player

#include "Player.h"

// Game figure

#include "Peon.h"
#include "Struc.h"


class Framework
{
public:
	Framework(int i);
	bool MainLoop();

	bool Events();
	void Graphics();

	bool GetInited() const
	{
		return Inited;
	}

	void ShowTurn();

private:
	bool Inited = false;
	GFX gfx;
	Window window;
private:
	std::vector<DoublePair> FindAllTurnToGo(DoublePair Map[8][8],
		std::vector<std::tuple< TypesFigurs, Types, bool >>& AllFriendlyFigure,
		std::vector<std::tuple< TypesFigurs, Types, bool >>& AllEnemyFigure
	);
	std::vector<DoublePair>	FigureMap(
		DoublePair ArrayOfMap[8][8],
		std::vector<std::tuple< TypesFigurs, Types, bool >>& Buffer);
	DoublePair	FindMapPoss(DoublePair Map[8][8], int x, int y, int w, int h);
	void Attack(std::vector<std::tuple< TypesFigurs, Types, bool >>& Enemy,
		int x, int y);
	bool& GetTrur() 
	{
		return Turn;
	}

private:
	bool Turn = true;

	std::vector<DoublePair>		PairShow;
	std::vector<Object>			Show;

	Controll Cntroler;

	Player PlaterEnemyControl;
	Player PlayerTurnControl;

	BattelGround	Map;
	int x, y;
};

#endif // !MainFramework