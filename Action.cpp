#include "Action.hpp"
#include <iostream>
#include "InventoryManager.hpp"

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
	for (ItemKey key : requiredItems) {
		if (key == ItemKey::Any)
			continue;

		if (!InventoryManager::ContainsItem(key))
			return false;
	}

	for (std::shared_ptr<ActionEvent> eventPtr : events) {
		ActionEvent* event = eventPtr.get();

		if (event == nullptr || !event->IsAllowed())
			return false;
	}

	return true;
}

Action::Action(std::string name, std::vector<std::shared_ptr<ActionEvent>> events, ItemKey itemRequired)
{
	this->name = std::move(name);
	this->events = std::move(events);
	this->requiredItems.push_back(itemRequired);
}

Action::Action(std::string name, std::shared_ptr<ActionEvent> event, ItemKey itemRequired)
{
	this->name = std::move(name);
	this->events.push_back(event);
	this->requiredItems.push_back(itemRequired);
}

Action::Action(std::string name, std::vector<std::shared_ptr<ActionEvent>> events, std::vector<ItemKey> itemsRequired)
{
	this->name = std::move(name);
	this->events = std::move(events);
	this->requiredItems = std::move(itemsRequired);
}

Action::Action(std::string name, std::shared_ptr<ActionEvent> event, std::vector<ItemKey> itemsRequired)
{
	this->name = std::move(name);
	this->events.push_back(event);
	this->requiredItems = std::move(itemsRequired);
}