#pragma once

#include <string>
#include "Area.hpp"
#include <vector>

class Room {
public:
    std::string m_name;                
    std::string m_description;         
    std::vector<Area> m_areas;         

    Room();
    Room(std::string a_roomName, std::string a_roomDescription, std::vector<Area> a_areas);  
    void AddArea(Area a_area);        ´<

    //~Room();
};