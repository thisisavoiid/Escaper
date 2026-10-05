#pragma once

#include <vector>
#include "Room.hpp"
#include <memory>

class RoomManager {
public:
	static Room* m_activeRoom;              
	static Area* m_activeArea;              

	static void ChangeRoom(Room* a_room);   
	static void ChangeArea(Area* a_area);   
	static void CreateRooms();
	static std::vector<std::unique_ptr<Room>>& GetRooms();
private:
	static std::vector<std::unique_ptr<Room>> m_rooms; 
};