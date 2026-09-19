#pragma once

#include "ActionEvent.hpp"
#include "Room.hpp"

class ChangeRoomEvent : public ActionEvent {
public:
	Room* target = nullptr;
	ChangeRoomEvent(Room* targetRoom);
	void Invoke() override;
};