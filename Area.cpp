#include "Area.hpp"

Area::Area(std::string a_name, std::vector<Action> a_actions)
{
	this->m_name = std::move(a_name);      
	this->m_actions = std::move(a_actions);
}