#ifndef BattelGroundMap
#define BattelGroundMap

#include "Object.h"
#include "General.h"
#include "Struc.h"

class BattelGround : public Object
{
public:
	bool InitBattelGround(
		const My_Str Name,
		const  SDL_PixelFormat* Fmt,
		SDL_Renderer* Renderer, int x, int y
	);
	DoublePair MapSection[8][8];
};


#endif // !BattelGroundMap
