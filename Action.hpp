#pragma once

#include <memory>
#include <string>
#include <vector>
#include "ActionEvent.hpp"

class Action {
public:
	std::string name;
	std::shared_ptr<ActionEvent> event;
	void Invoke();
	Action(std::string name, std::shared_ptr<ActionEvent> event);
};