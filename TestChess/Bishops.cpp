#include "Bishops.h"

std::vector<DoublePair>		Bishops::GetPossitionToGo(
	std::vector<DoublePair>& Friendly, std::vector<DoublePair>& Enemy,
	DoublePair Target, DoublePair Map[8][8])
{
	Uint8 TempVarible = 0;

	std::vector<DoublePair> Move = CanMove(Map, Target);
	std::vector<DoublePair> Attack = CanAttack();
	std::vector<DoublePair> Buffer;

	for (auto i : Move)
	{
		bool EBT = true;//FindTurn(Enemy, i);

		if (EBT)
		{
			Buffer.push_back((DoublePair(
				i.x, i.y))
			);
		}

	}

	return Buffer;
}

bool Bishops::FindTurn(std::vector<DoublePair>& ObjectVector, DoublePair i)
{
	bool EBV;
	bool Side = this->Side;
	int h = 30, w = 30;

	std::find_if(ObjectVector.begin(), ObjectVector.end(),
		[&i, &h, &w, &EBV, &Side](const DoublePair& E) {
			if (Side)
			{
				if (i.y >= E.y && i.y - (2 * h) <= E.y)
				{
					if (E.x >= i.x && E.x <= i.x + w)
					{
						EBV = true; return EBV;
					}
				} EBV = false; return false;
			}
			else
			{
				if (i.y + h >= E.y && i.y <= E.y)
				{
					if (E.x >= i.x && E.x <= i.x + (2 * w))
					{
						EBV = true; return EBV;
					}
				} EBV = false; return false;
			}
		});
	return EBV;
}

std::vector<DoublePair> Bishops::CanAttack()
{
	std::vector<DoublePair> Buffer;

	return Buffer;
}

std::vector<DoublePair> Bishops::CanMove(DoublePair Map[8][8], DoublePair Poss)
{
	std::vector<DoublePair> Buffer;

	int PossitonI; int PossitonJ;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (Poss.x + 24 == Map[i][j].x
				&& Poss.y + 24 == Map[i][j].y)
			{
				PossitonI = i;
				PossitonJ = j;
			}
		}
	}

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (i == (j + (PossitonI - PossitonJ)) ||
				(i + j) == (PossitonI + PossitonJ))
			{
				Buffer.push_back(
					DoublePair(Map[i][j].x, Map[i][j].y));
			}

		}
	}

	return Buffer;
}