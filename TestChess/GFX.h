#ifndef GraphicsX
#define GraphicsX

#include "Struc.h"
#include "General.h"
#include "Sprite.h"

class GFX
{

public:
	bool GraphicsInit(SDL_Window* window);

	void ClearWindow();
	void UpdatWindow();

	void Draw(Sprite Sprt, SDL_Surface* surf, SDL_Rect* dest);
	void DrawRect(SDL_Rect* Rect, SDL_Color cl);
	void DrawTexture(SDL_Texture* Texture, SDL_Rect* Rect);


	void DrawGreenBox(std::vector<Object>& AllBox);
	void DrawPlayerTable(std::vector<std::tuple< TypesFigurs, Types, bool >>& AllFigure);


	SDL_Renderer* GetRenderer() const
	{
		return Renderer;
	}

private:
	bool Inited = false;
	SDL_Renderer* Renderer;
};

#endif // !GraphicsX