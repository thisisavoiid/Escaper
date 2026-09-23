#pragma once

#include <memory>
#include <string>
#include <vector>
#include "ActionEvent.hpp"
#include "ItemKey.hpp"

class Action {
public:
	std::string name;
	std::vector<std::shared_ptr<ActionEvent>> events;
	ItemKey showItem = ItemKey::Any;

	void Invoke();
	bool IsAllowed();

	Action(
		std::string name, 
		std::vector<std::shared_ptr<ActionEvent>> events, 
		ItemKey itemRequired = ItemKey::Any
	);

	Action(
		std::string name,
		std::shared_ptr<ActionEvent> event,
		ItemKey itemRequired = ItemKey::Any
	);
};