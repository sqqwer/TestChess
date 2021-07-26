#ifndef FigurePawn
#define FigurePawn

#include "Object.h"
#include "General.h"

class Peon : public Object
{
public:
	Peon() {};
	Peon(TypesFigurs Type, bool side)
		: Object(), TypeOfFigure(Type), Side(side) {};

	std::vector<DoublePair> GetPossitionToGo(
		std::vector<DoublePair>&, std::vector<DoublePair>&,
		DoublePair);


	void UpdateCount() { CountTurn++; }
	unsigned int GetCount() const { return CountTurn; }
private:
	std::vector<DoublePair>	CanAttack();
	std::vector<DoublePair> CanMove();
	bool FindTurn(std::vector<DoublePair>& ObjectVector, DoublePair i);
private:
	bool Side;
	unsigned int CountTurn = 0;
	TypesFigurs TypeOfFigure;
};

#endif // !FigurePawn