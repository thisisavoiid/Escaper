#pragma once

#include "Action.hpp"
#include <string>
#include <vector>

class Area {
public:
	std::string name;
	std::vector<Action> actions;

	Area(std::string name, std::vector<Action> actions);
};