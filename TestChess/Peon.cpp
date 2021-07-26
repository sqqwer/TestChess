#include "Peon.h"

std::vector<DoublePair>		Peon::GetPossitionToGo(
	std::vector<DoublePair>& Friendly, std::vector<DoublePair>& Enemy,
	DoublePair Target)
{
	Uint8 TempVarible = 0;

	std::vector<DoublePair> Move = CanMove();
	std::vector<DoublePair> Attack = CanAttack();
	std::vector<DoublePair> Buffer;

	for (auto i : Attack)
	{
		bool EBV = FindTurn(Enemy, i);
		if (EBV)
			Buffer.push_back((DoublePair(
				i.x + 24, (Side) ? i.y - 30 : i.y + 30))
			);
	}

	for (auto i : Move)
	{
		bool EBV, FBV;

		EBV = FindTurn(Enemy, i);
		FBV = FindTurn(Friendly, i);

		if (!EBV && !FBV)
			Buffer.push_back((DoublePair(
				i.x + WIDHT_AND_HIGHT_OF_FIGURE_SPRITE,
				(Side) ? i.y - 30 : i.y + 30 ))
			);
	}
	return Buffer;
}

bool Peon::FindTurn(std::vector<DoublePair>& ObjectVector, DoublePair i)
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
					if (E.x >= i.x && E.x <= i.x + (2*w))
					{
						EBV = true; return EBV;
					}
				} EBV = false; return false;
			}
		});
	return EBV;
}

std::vector<DoublePair>	Peon::CanAttack()
{
	std::vector<DoublePair> Buffer;
	
	const int x = GetRect()->x;
	const int y = GetRect()->y;
	
	if (Side)
	{
		Buffer.push_back(DoublePair((x - 30) - 30, (y + 24) - 30));
		Buffer.push_back(DoublePair((x + 30) + 30, (y + 24) - 30));
	}
	else
	{
		Buffer.push_back(DoublePair((x - 30) - 30, (y + 24) + 30));
		Buffer.push_back(DoublePair((x + 30) + 30, (y + 24) + 30));
	}
	return Buffer;
}

std::vector<DoublePair> Peon::CanMove()
{
	std::vector<DoublePair> Buffer;

	const int x = GetRect()->x;
	const int y = GetRect()->y;

	if (((y ) - 30) < 0 || ((y) + 30) > 480)
		return Buffer;

	if (Side)
	{
		if (CountTurn == 0)
			Buffer.push_back(DoublePair(x, (y + 24) - 90));
		
		Buffer.push_back(DoublePair(x, (y + 24) - 30));
	}
	else
	{
		if (CountTurn == 0)
			Buffer.push_back(DoublePair(x, (y + 24) + 90));

		Buffer.push_back(DoublePair(x, (y + 24) + 30));
	}

	return Buffer;
}