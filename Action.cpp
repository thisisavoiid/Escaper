#include "Action.hpp"
#include <iostream>

void Action::Invoke()
{
	if (event != nullptr)
		event->Invoke();
}

Action::Action(std::string name, ActionEvent* event)
{
	this->name = name;
	this->event = event;
}

//Action::~Action()
//{
//	if (event != nullptr)
//		delete event;
//}
