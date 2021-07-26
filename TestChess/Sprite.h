#ifndef TextureSprite
#define TextureSprite

#include "General.h"

class Sprite
{
public:
	Sprite();
	Sprite(const My_Str name, const SDL_PixelFormat* Fmt);

	void	SetNewPtrTexture(SDL_Texture* Texture)
	{
		this->Texture = Texture;
	}

	void	SetNULLPtrSurface()
	{
		this->Surface = NULL;
	}

	SDL_Surface* GetPtrSurface() const
	{
		return Surface;
	}

	SDL_Texture* GetPtrTextrure() const
	{
		return Texture;
	}

	bool GetLoad() const
	{
		return Load;
	}

private:
	bool Load = false;

	SDL_Texture* Texture;
	SDL_Surface* Surface;
};

#endif // !TextureSprite