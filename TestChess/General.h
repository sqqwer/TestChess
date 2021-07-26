#ifndef MainHeader
#define MainHeader

// SDL Library
#include <SDL.h>

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <utility>
#include <tuple>
#include <algorithm>

// Define 

using std::cout;
using std::endl;
using My_Str = std::string;

 // Constans

const Uint8 SIZE_OF_ARRAY_ONBATTELGROUND = 8;
const Uint8 MULTI_CONST_FOR_BATTELGROUND = 10;

const Uint8 MAX_TYPES_OF_FIGURE = 16;
const Uint8	WIDHT_AND_HIGHT_OF_FIGURE_SPRITE = 24;
const Uint8 SHIFT_ON_BATELLGROUND_STRIP = 60;
const Uint8 START_POSSITION_ON_GROUND_STRIP = 30;
const Uint8 All_LENGHT_OF_SPRITE = 48;

// Type, Enum, Struct

enum NumberOfElementTuple
{
	First = 0,
	Second = 1,
	Third = 2
};

enum TypesFigurs
{
	PAWN,
	KHIGHT,
	BISHOP,
	ROOK,
	QUEEN,
	KING
};

typedef struct DoublePair
{
	DoublePair() {};
	DoublePair(int x, int y)
		: x(x), y(y) {};

	bool operator==(DoublePair Temp)
	{
		if (this->x == Temp.x && this->y == Temp.y)
			return true;
		else
			return false;
	}

	int x;
	int y;
} Pair;

#endif // !MainHeader