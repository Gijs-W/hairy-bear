#include "stdafx.h"
#include <windows.h>
#include <vld.h>
#include "Engine.h"

int main()
{

	
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); 

	MoveWindow(console, r.left, r.top, 1000, 600, TRUE); 


	Engine *engine = new Engine();
	engine->initHero();
	engine->initMap();
	engine->loop();
	delete engine;
	return 0;
}
