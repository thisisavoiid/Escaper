#include "Action.hpp"
#include <iostream>

void Action::Invoke()
{
	if (event != nullptr)
		event->Invoke();
}

Action::Action(std::string name, std::shared_ptr<ActionEvent> event)
{
	this->name = std::move(name);
	this->event = std::move(event);
}

//Action::~Action()
//{
//	if (event != nullptr)
//		delete event;
//}
