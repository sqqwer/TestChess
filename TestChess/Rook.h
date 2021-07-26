#ifndef FigureRook
#define FigureRook

#include "Object.h"
#include "General.h"

class Rook : public Object
{
public:
	Rook() {};
	Rook(TypesFigurs Type, bool side)
		: Object(), TypeOfFigure(Type), Side(side) {};

	std::vector<DoublePair> GetPossitionToGo(
		std::vector<DoublePair>&, std::vector<DoublePair>&,
		DoublePair, DoublePair Map[8][8]);

	void UpdateCount() { CountTurn++; }
	unsigned int GetCount() const { return CountTurn; }
private:
	std::vector<DoublePair>	CanAttack();
	std::vector<DoublePair> CanMove(DoublePair Map[8][8], DoublePair Poss);
	bool FindTurn(std::vector<DoublePair>& ObjectVector, DoublePair i);
private:
	bool Side;
	unsigned int CountTurn = 0;
	TypesFigurs TypeOfFigure;
};

#endif // !FigureRook
