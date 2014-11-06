#include "stdafx.h"
#include "RoomViewState.h"

RoomViewState::RoomViewState(Room* room) {
	m_room = room;
	m_room->setVisited(true);
	std::vector<MapType*>* cor = m_room->getCorridors();
	for (int i = 0; i < cor->size(); i++)
	{
		cor->at(i)->setVisited(true);
	}
}

void RoomViewState::handle(Engine* context) {
	std::cout << m_room->getDescription() << std::endl;

	vector<string> *expectedAnswers = new vector < string >;

	if (m_room->getEnemies()->size() > 0)
	{
		expectedAnswers->push_back("vechten");
		expectedAnswers->push_back("vluchten");
	}
	else
	{
		expectedAnswers->push_back("verlaten");
		expectedAnswers->push_back("zoeken");
		expectedAnswers->push_back("blijven");
		expectedAnswers->push_back("kaart");
		expectedAnswers->push_back("inventory");
	}

	expectedAnswers->push_back("opslaan");

	string action = InputManager::getInstance()->requestInput("Wat doe je?", expectedAnswers);
	
	if (action == "vechten") {
		context->setState(new FightState(m_room));
	}
	else if (action == "vluchten")
	{
		context->setState(new FlightState(m_room));
	}
	else if (action == "zoeken") {

		std::vector<Item*>* items = m_room->getItems();
	
		if (items->size() > 0) {
			printf("Je hebt items gevonden:\n");

			for (auto &item : *items) {
				std::cout << "-" << item->getName() << std::endl;
			}
			m_room->lookForItems(context->getHero());
		}

		else {
			printf("Niets gevonden.\n");
		}

		std::vector<Trap*>* traps = m_room->getTraps();

		if (traps->size() > 0) {
			printf("Er zitten vallen in de kamer die je pijn gedaan hebben!:\n");

			for (auto &trap : *traps) {
				std::cout << "-" << trap->getName() << std::endl;
				trap->hurt(context->getHero());
			}

			m_room->dismantleTraps();
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
	else if (action == "kaart")
	{
		context->setState(new MapDrawState(m_room));
	}
	else if (action == "opslaan") {
		context->save();
	}
	
	delete expectedAnswers;


}