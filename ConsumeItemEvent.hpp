#pragma once

#include "ActionEvent.hpp"
#include "ItemKey.hpp" 

class ConsumeItemEvent : public ActionEvent {
public:
	ItemKey item;
	ConsumeItemEvent(ItemKey item, bool allowMultiTrigger=false);
	void Invoke() override;
	bool IsAllowed() override;
private:
	bool multiTriggerAllowed;
	bool hasBeenInvoked = false;
};