#include "Sprite.h"

Sprite::Sprite()
{}

Sprite::Sprite(const My_Str name, const SDL_PixelFormat* Fmt)
{
	Surface = (SDL_LoadBMP(name.c_str()));
	if (!Surface)
	{
		cout << "Error loading image: " << SDL_GetError() << endl;
		system("pause");
		Load = false;
		return;
	}
	else
	{
		Load = true;
	}
}