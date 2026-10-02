#pragma once

#include "ActionEvent.hpp"
#include "Room.hpp"
#include <memory>
#include <vector>
#include <string>

class NarrativeSetEvent : public ActionEvent {
public:
	NarrativeSetEvent(const std::vector<std::string>& lines);
	void Invoke() override;
	bool IsAllowed() override;
private:
	std::vector<std::string> lines;
};