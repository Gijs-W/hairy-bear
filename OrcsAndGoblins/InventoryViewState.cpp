#include "stdafx.h"
#include "InventoryViewState.h"
#include "Item.h"
#include "CupOfTea.h"
InventoryViewState::InventoryViewState(Room* room) {
	m_comingFromRoom = room;
}
void InventoryViewState::handle(Engine* context) {
	printf("Je hebt een aantal dingetjes in je inventory zitten.\n");

	vector<Item*>* itemList = context->getHero()->getInventoryList();
	itemList->push_back(new CupOfTea);
	for (auto &it : *itemList) {
		std::cout << "-" << it->getName() << std::endl;
	}

	vector<string>* expectedAnswers = new vector < string > ;
	expectedAnswers->push_back("niks");
	for (auto &it : *itemList) {
		expectedAnswers->push_back(it->getName());
	}

	string result = InputManager::getInstance()->requestInput("Wat wil je gebruiken?", expectedAnswers);
	delete expectedAnswers;

	if (result == "niks") {
		printf("OK, niets gedaan!\n");
	}
	else {
		for (auto &it : *itemList) {
			if (it->getName() == result) {
				std::cout << it->getName() << " is gebruikt!" << std::endl;
				it->use(context->getHero());
				context->getHero()->removeFromInventory(it);
				break;
			}
		}
	}

	context->setState(new RoomViewState(m_comingFromRoom));
}