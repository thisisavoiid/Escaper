#include "Area.hpp"

Area::Area(std::string name, std::vector<Action> actions)
{
	this->name = name;
	this->actions = actions;
}

//Area::~Area()
//{
//	for (const Action& action : actions) {
//		if (&action != nullptr)
//			delete &action;
//	}
//}
