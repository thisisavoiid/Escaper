#include "ChangeRoomEvent.hpp"
#include "RoomManager.hpp"
#include <iostream>

ChangeRoomEvent::ChangeRoomEvent(Room* a_targetRoom)  
{
	this->m_target = a_targetRoom;          
}

void ChangeRoomEvent::Invoke()
{
	if (!m_target)                          
		return;

	RoomManager::ChangeRoom(m_target);      
}

bool ChangeRoomEvent::IsAllowed()
{
	return (m_target != nullptr);           
}