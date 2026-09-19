#include "Area.hpp"

Area::Area(std::string name, std::vector<Action> actions)
{
	this->name = std::move(name);
	this->actions = std::move(actions);
}

//Area::~Area()
//{
//	for (const Action& action : actions) {
//		if (&action != nullptr)
//			delete &action;
//	}
//}
