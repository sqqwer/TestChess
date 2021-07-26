#include "BattelGround.h"

bool BattelGround::InitBattelGround(
	const My_Str Name,
	const  SDL_PixelFormat* Fmt,
	SDL_Renderer* Renderer, int x, int y
)
{
	if (!InitAll(Name, Fmt, Renderer, x, y)) return false;
	MultiHigthAndWight(
		MULTI_CONST_FOR_BATTELGROUND, 
		MULTI_CONST_FOR_BATTELGROUND);

	MapSection[0][0] = struct DoublePair
	(START_POSSITION_ON_GROUND_STRIP, START_POSSITION_ON_GROUND_STRIP);
	int Xx = SHIFT_ON_BATELLGROUND_STRIP,
		Yy = SHIFT_ON_BATELLGROUND_STRIP;
	for (int i = 0; i < SIZE_OF_ARRAY_ONBATTELGROUND; i++)
	{
		MapSection[0][i].y = START_POSSITION_ON_GROUND_STRIP;
		MapSection[i][0].x = START_POSSITION_ON_GROUND_STRIP;
		if (i > 0) 
			MapSection[0][i].x = MapSection[0][i - 1].x + Xx;
	}
		
	for (int i = 1; i < SIZE_OF_ARRAY_ONBATTELGROUND; i++)
	{
		MapSection[i][0].y = MapSection[i - 1][0].y + Yy;
		for (int j = 1; j < SIZE_OF_ARRAY_ONBATTELGROUND; j++)
		{
			MapSection[i][j].x = MapSection[i][j - 1].x + Xx;
			MapSection[i][j].y = MapSection[i][j - 1].y;
		}
	}

	
	for (int i = 0; i < SIZE_OF_ARRAY_ONBATTELGROUND; i++)
	{
		for (int j = 0; j < SIZE_OF_ARRAY_ONBATTELGROUND; j++)
		{
			cout << "("
				<< MapSection[i][j].x << "," << MapSection[i][j].y << ")" << '\t';
		}
		cout << endl;
	}

	return true;
}