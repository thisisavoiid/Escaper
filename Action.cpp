#include "Action.hpp"
#include <iostream>

void Action::Invoke()
{
	if (events.empty())
		return;

	for (const std::shared_ptr<ActionEvent>& eventPtr : events) {
		ActionEvent* event = eventPtr.get();

		if (event == nullptr)
			continue;

		event->Invoke();
	}
}

bool Action::IsAllowed()
{
	bool isAllowed = true;

	for (std::shared_ptr<ActionEvent> eventPtr : events) {
		ActionEvent* event = eventPtr.get();
		isAllowed = (event != nullptr) && (event->IsAllowed());

		if (!isAllowed)
			break;
	}

	return isAllowed;
}

Action::Action(std::string name, std::vector<std::shared_ptr<ActionEvent>> events, ItemKey itemRequired)
{
	this->name = std::move(name);
	this->events = std::move(events);
	this->showItem = itemRequired;
}

Action::Action(std::string name, std::shared_ptr<ActionEvent> event, ItemKey itemRequired)
{
	this->name = std::move(name);
	this->events.push_back(event);
	this->showItem = itemRequired;
}

//Action::~Action()
//{
//	if (event != nullptr)
//		delete event;
//}
