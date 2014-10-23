#include "stdafx.h"
#include "RoomViewState.h"

RoomViewState::RoomViewState(Room* room) {
	m_room = room;
	m_room->setVisited(true);
}

void RoomViewState::handle(Engine* context) {
	InputManager::getInstance()->requestInput("Je staat in een kamer. Wat doe je?");
}