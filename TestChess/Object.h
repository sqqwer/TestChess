#ifndef GeneralObject
#define GeneralObject

#include "Sprite.h"
#include "General.h"

class Object
{
public:
	Object() {};
	bool InitAll(
		const My_Str Name, const  SDL_PixelFormat* Fmt,
		SDL_Renderer* Renderer, const int x, const int y
	);
	bool InitTexture(
		const My_Str Name,
		const  SDL_PixelFormat* Fmt,
		SDL_Renderer* Renderer
	);
	Sprite* GetSprite()
	{
		return &sprite;
	}
	SDL_Rect* GetRect()
	{
		return  &Dest;
	}
	bool GetActive() const
	{
		return Active;
	}
	void MultiHigthAndWight(int w, int h)
	{
		Dest.w = Dest.w * w; Dest.h = Dest.h * h;
	}

private:
	bool Active = false;
	SDL_Rect Dest;
	Sprite sprite;
};

#endif // !GeneralObject
