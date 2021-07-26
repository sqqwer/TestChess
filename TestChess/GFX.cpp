#include "GFX.h"

void GFX::DrawPlayerTable(std::vector<std::tuple< TypesFigurs, Types, bool >>& AllFigure)
{
	for (auto i : AllFigure)
	{
		if (std::get<Third>(i))
		{
			switch (std::get<First>(i))
			{
			case PAWN:
				DrawTexture(
					std::get<Second>(i).Pen->GetSprite()->GetPtrTextrure(),
					std::get<Second>(i).Pen->GetRect()
					);
				break;
			case ROOK:
				DrawTexture(
					std::get<Second>(i).Rooks->GetSprite()->GetPtrTextrure(),
					std::get<Second>(i).Rooks->GetRect()
				);
				break;
			case BISHOP:
				DrawTexture(
					std::get<Second>(i).Bish->GetSprite()->GetPtrTextrure(),
					std::get<Second>(i).Bish->GetRect()
				);
				break;
			case KHIGHT:
				DrawTexture(
					std::get<Second>(i).Kni->GetSprite()->GetPtrTextrure(),
					std::get<Second>(i).Kni->GetRect()
				);
				break;
			case KING:
				DrawTexture(
					std::get<Second>(i).Kin->GetSprite()->GetPtrTextrure(),
					std::get<Second>(i).Kin->GetRect()
				);
				break;
			case QUEEN:
				DrawTexture(
					std::get<Second>(i).Que->GetSprite()->GetPtrTextrure(),
					std::get<Second>(i).Que->GetRect()
				);
				break;
			}
		}
	}
}

void GFX::DrawGreenBox(std::vector<Object>&	AllBox)
{
	if (!AllBox.empty())
	{
		for (auto i : AllBox)
		{
			DrawTexture(i.GetSprite()->GetPtrTextrure(), i.GetRect());
		}
	}

}

bool GFX::GraphicsInit(SDL_Window* window)
{
	if (Inited) return true;

	Renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!Renderer) {
		cout << "Error creating renderer: " << SDL_GetError() << endl;
		Inited = false;
		return false;
	}

	Inited = true;

	return Inited;
}

void GFX::DrawTexture(SDL_Texture* Texture, SDL_Rect* Rect)
{
	SDL_RenderCopy(Renderer, Texture, NULL, Rect);
}


void GFX::Draw(Sprite Sprt, SDL_Surface* surf, SDL_Rect* dest)
{
//	SDL_BlitScaled(Sprt.GetPointer(), NULL, surf, dest);
}

void GFX::DrawRect(SDL_Rect* Rect, SDL_Color color)
{
	SDL_SetRenderDrawColor(Renderer, 
		color.r, color.g, color.b, color.a
	);
	SDL_RenderFillRect(Renderer, Rect);
}

void GFX::ClearWindow()
{
	SDL_SetRenderDrawColor(Renderer, 0, 0, 155, 0);
	SDL_RenderClear(Renderer);
}

void GFX::UpdatWindow()
{
	SDL_RenderPresent(Renderer);
}
