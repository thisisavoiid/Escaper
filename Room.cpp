#include "Room.hpp"

Room::Room() {
	this->name = "Unnamed Room";
	this->description = "No description set!";
}

//Room::~Room()
//{
//	for (const Area& area : areas) {
//		if (&area != nullptr)
//			delete &area;
//	}
//}

Room::Room(std::string roomName, std::string roomDescription, std::vector<Area> areas)
{
	this->name = std::move(roomName);
	this->description = std::move(roomDescription);
	this->areas = std::move(areas);
}

void Room::AddArea(Area area)
{
	this->areas.push_back(std::move(area));
}
