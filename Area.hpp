#pragma once

#include "Action.hpp"
#include <string>
#include <vector>

class Area {
public:
	std::string m_name;                    
	std::vector<Action> m_actions;         

	Area(std::string a_name, std::vector<Action> a_actions);
};