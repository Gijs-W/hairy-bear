#include "stdafx.h"
#include "RoomViewState.h"

RoomViewState::RoomViewState(Room* room) {
	m_room = room;
	m_room->setVisited(true);
}

void RoomViewState::handle(Engine* context) {
	std::cout << m_room->getDescription() << std::endl;

	vector<string> *expectedAnswers = new vector < string >;
	expectedAnswers->push_back("verlaten");
	expectedAnswers->push_back("blijven");


	string action = InputManager::getInstance()->requestInput("Wat doe je?", expectedAnswers);
	
	if (action == "verlaten") {
		printf("Je hebt de kamer verlaten.\n");
		context->setState(new HeroWalkState());
	}
	
	
	delete expectedAnswers;


}