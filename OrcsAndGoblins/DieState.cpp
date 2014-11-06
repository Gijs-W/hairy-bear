#include "stdafx.h"
#include "DieState.h"


DieState::DieState()
{
}


DieState::~DieState()
{
}

void DieState::handle(Engine* context)
{
	//clear maps
	context->initMap();

	//set health back to 100 hp
	context->getHero()->setHealth(100);


}
