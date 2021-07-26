#include "Object.h"

bool Object::InitAll(
	const My_Str Name, const  SDL_PixelFormat* Fmt,
	SDL_Renderer* Renderer, const int x, const int y
)
{
	InitTexture(Name, Fmt, Renderer);
	Dest.x = x;
	Dest.y = y;
	return true;
}

bool Object::InitTexture(
	const My_Str Name, 
	const  SDL_PixelFormat* Fmt, 
	SDL_Renderer* Renderer)
{
	sprite = Sprite(Name, Fmt);

	Dest.w = sprite.GetPtrSurface()->w;
	Dest.h = sprite.GetPtrSurface()->h;

	if (!sprite.GetLoad()) return false;

	sprite.SetNewPtrTexture(
		SDL_CreateTextureFromSurface(Renderer, sprite.GetPtrSurface())
	);
	SDL_FreeSurface(sprite.GetPtrSurface());
	sprite.SetNULLPtrSurface();
	if (!sprite.GetPtrTextrure()) {
		cout << "Error creating texture: " << SDL_GetError() << endl;
		return false;
	}
	Active = true;
	return Active;
}