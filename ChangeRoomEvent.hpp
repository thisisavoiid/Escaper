#pragma once

#include "ActionEvent.hpp"
#include "Room.hpp"
#include <memory>

class ChangeRoomEvent : public ActionEvent {
public:
	Room* m_target = nullptr;              
	ChangeRoomEvent(Room* a_targetRoom);   
	void Invoke() override;
	bool IsAllowed() override;
};