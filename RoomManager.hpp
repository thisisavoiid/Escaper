#pragma once

#include <vector>
#include "Room.hpp"
#include <memory>

class RoomManager {
public:
	static Room* ActiveRoom;
	static Area* ActiveArea;

	static void ChangeRoom(Room* room);
	static void ChangeArea(Area* area);
	static void CreateRooms();
	static std::vector<std::unique_ptr<Room>>& GetRooms();
private:
	static std::vector<std::unique_ptr<Room>> rooms;
};