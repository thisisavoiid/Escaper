#pragma once

#include <string>
#include <vector>
#include "ActionEvent.hpp"

class Action {
public:
	std::string name;
	ActionEvent* event = nullptr;
	void Invoke();
	Action(std::string name, ActionEvent* event);
};