#ifndef ControlFigure
#define ControlFigure

#include "Object.h"
#include "General.h"
#include "BattelGround.h"

#include "Struc.h"

class Controll
{
public:
	bool ObjectChossed() const {
		return (TempChossedObject == nullptr) ? true : false;
	}
public:
	void MoveObject(bool& Turn);
	void DiscardFigure();
	void SetPossition(std::vector<DoublePair> FindPoint);
	void FindChoosedPoint(std::vector<DoublePair> FindPoint);
	void SetControlFigure(std::vector<Types>& Obj);
	void SetControlFigure(
		std::vector<std::tuple< TypesFigurs, Types, bool >>& AllFigure
	);

	Types* GetTempFigure() const
	{
		return TempChossedObject;
	}

	TypesFigurs GetTypesFigur() const
	{
		return ChossedType;
	}
	DoublePair	GetDoublePossition() const
	{
		return Possition;
	}
	void SetDoublePossition(const DoublePair Set[8][8])
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (Set[i][j].x >= Possition.x && Set[i][j].x <= Possition.x + 
					All_LENGHT_OF_SPRITE)
				{
					if (Set[i][j].y >= Possition.y && Set[i][j].y <= 
						Possition.y + All_LENGHT_OF_SPRITE)
					{
						Possition =  DoublePair(Set[i][j].x, Set[i][j].y);
					}
				}
			}
		}
	}
	int GetX() const
	{
		return x;
	}
	int GetY() const
	{
		return y;
	}
private:
	bool FindPossition(
		const int FigurPossX, const int FigurPossY,
		const int FigurPossW, const int FigurPossH,
		const int MousePossX, const int MousePossY
	);

	int x, y;
	bool Control = false;


	DoublePair	Possition;
	TypesFigurs	ChossedType;
	Types* TempChossedObject = nullptr;
};

#endif // !1
