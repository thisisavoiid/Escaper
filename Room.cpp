#include "Room.hpp"

Room::Room() {
	this->m_name = "Unnamed Room";              
	this->m_description = "No description set!";
}

Room::Room(std::string a_roomName, std::string a_roomDescription, std::vector<Area> a_areas)  
{
	this->m_name = std::move(a_roomName);               
	this->m_description = std::move(a_roomDescription); 
	this->m_areas = std::move(a_areas);                 
}

void Room::AddArea(Area a_area)                         
{
	this->m_areas.push_back(std::move(a_area));         
}