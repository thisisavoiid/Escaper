#pragma once

#include <vector>
#include "Room.hpp"

class RoomManager {
public:
	static Room* ActiveRoom;
	static Area* ActiveArea;
	static void ChangeRoom(Room* room);
	static void ChangeArea(Area* area);
	static void CreateRooms();
	static std::vector<Room*>& GetRooms();
private:
	static std::vector<Room*> rooms;
};