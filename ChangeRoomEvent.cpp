#include "ChangeRoomEvent.hpp"
#include "RoomManager.hpp"
#include <iostream>

ChangeRoomEvent::ChangeRoomEvent(Room* targetRoom)
{
	this->target = targetRoom;
}

void ChangeRoomEvent::Invoke()
{
	if (!target)
		return;

	RoomManager::ChangeRoom(target);
}
