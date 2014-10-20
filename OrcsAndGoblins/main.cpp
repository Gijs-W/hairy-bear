#include "stdafx.h"
#include "Engine.h"
int main()
{
	Engine *engine = new Engine();
	engine->initHero();
	engine->loop();
	return 0;
}
