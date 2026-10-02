#pragma once

#include "ActionEvent.hpp"
#include "Room.hpp"
#include <memory>

class NarrativeClearEvent : public ActionEvent {
public:
	void Invoke() override;
	bool IsAllowed() override;
};