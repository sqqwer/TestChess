#include "General.h"
#include "Sprite.h"
#include "Framework.h"

int main(int argc, char* argv[])
{
	Framework* frm = new Framework(1);
	
	while (frm->MainLoop() && frm->GetInited()) {
		// wait before processing the next frame
		SDL_Delay(10);
	}
	delete frm;
	return 0;
}	

//void kill() {
//	// Free images
//	//  SDL_FreeSurface(image1);
//	//  SDL_FreeSurface(image2);
//
//	// Quit
//	SDL_DestroyWindow(window);
//	SDL_Quit();
//}