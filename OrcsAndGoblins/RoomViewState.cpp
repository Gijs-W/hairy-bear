#include "stdafx.h"
#include "RoomViewState.h"

RoomViewState::RoomViewState(Room* room) {
	m_room = room;
	m_room->setVisited(true);
}

void RoomViewState::handle(Engine* context) {
	std::cout << m_room->getDescription() << std::endl;

	vector<string> *expectedAnswers = new vector < string >;
	expectedAnswers->push_back("vechten");
	expectedAnswers->push_back("verlaten");
	expectedAnswers->push_back("zoeken");
	expectedAnswers->push_back("blijven");
	expectedAnswers->push_back("inventory");

	string action = InputManager::getInstance()->requestInput("Wat doe je?", expectedAnswers);
	
	if (action == "vechten") {
		// Hier een check of er vijanden zijn
		printf("Er zijn op dit moment geen vijanden om tegen te vechten.\n");
	}
	else if (action == "zoeken") {
		if (m_room->lookForItems(context->getHero())) {
			printf("Je hebt spullen gevonden welke aan je inventory zijn toegevoegd.\n");
		}
		else {
			printf("Niets gevonden.\n");
		}
	}
	else if (action == "blijven") {
		if (context->getHero()->regenerateHealth()) {
			printf("Je hebt levens bijgekregen\n");
		}
		else {
			printf("Je hebt al het maximaal aantal levens.\n");
		}
	
	}
	else if (action == "verlaten") {
		printf("Je hebt de kamer verlaten.\n");
		context->setState(new HeroWalkState());
	}
	else if (action == "inventory") {
		context->setState(new InventoryViewState(m_room));
	}
	
	
	delete expectedAnswers;


}