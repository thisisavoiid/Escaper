#pragma once

#include <string>
#include "Area.hpp"
#include <vector>

class Room {
public:
    std::string name;
    std::string description;
    std::vector<Area> areas;

    Room();
    Room(std::string roomName, std::string roomDescription, std::vector<Area> areas);
    void AddArea(Area area);

//~Room();
};