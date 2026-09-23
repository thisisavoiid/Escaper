#pragma once

#include "Room.hpp"
#include "InventoryManager.hpp"

class PickupItemEvent : public ActionEvent {
public:
	ItemKey item;
	PickupItemEvent(ItemKey item, bool allowMultiPickup = false);
	void Invoke() override;
	bool IsAllowed() override;
private:
	bool multiTriggerAllowed;
	bool hasBeenInvoked = false;
};
