#ifndef WindowSetup
#define WindowSetup

#include "General.h"


class Window
{
public:
	Window();
	Window(int w, int h);
	bool Init();
	SDL_Surface* GetSurface() const
	{
		return winSurface;
	}
	SDL_Window* GetWindow() const
	{
		return window;
	}
private:
	int h{ 480 };
	int w{ 640 };

	SDL_Window* window;
	SDL_Surface* winSurface;

};


#endif // !WindowSetup