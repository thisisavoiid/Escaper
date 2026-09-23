#include "PickupItemEvent.hpp"

PickupItemEvent::PickupItemEvent(ItemKey item, bool allowMultiTrigger)
{
	this->item = item;
	this->multiTriggerAllowed = allowMultiTrigger;
}

void PickupItemEvent::Invoke()
{
	InventoryManager::AddItem(item);

	this->hasBeenInvoked = true;
}

bool PickupItemEvent::IsAllowed()
{
	bool isValidItemType = this->item != ItemKey::Any; // Checks whether the item type selected is NOT ItemKey::Any (unexpected behaviour)
	bool multiTriggerGuard = !this->multiTriggerAllowed && this->hasBeenInvoked; // Returns true if multi trigger is disabled AND event has been invoked before!

	return isValidItemType && !multiTriggerGuard;
}
