#include "Window.h"


Window::Window()
{}

Window::Window(int w, int h) :
	w(w), h(h)
{}

bool Window::Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		cout << "Error initializing SDL: " << SDL_GetError() << endl;
		system("pause");
		return false;
	}

	window = SDL_CreateWindow(
		"Test Chess Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		w, h, SDL_WINDOW_SHOWN
	);

	if (!window)
	{
		cout << "Error creating window: " << SDL_GetError() << endl;
		system("pause");
		return false;
	}

	winSurface = SDL_GetWindowSurface(window);
	if (!winSurface)
	{
		cout << "Error getting surface: " << SDL_GetError() << endl;
		system("pause");
		return false;
	}

	return true;
}