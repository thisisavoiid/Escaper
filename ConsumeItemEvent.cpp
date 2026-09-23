#include "ConsumeItemEvent.hpp"
#include "InventoryManager.hpp"
#include "ItemKey.hpp"

ConsumeItemEvent::ConsumeItemEvent(ItemKey item, bool allowMultiTrigger)
{
	this->item = item;
	this->multiTriggerAllowed = allowMultiTrigger;
}

void ConsumeItemEvent::Invoke()
{
	if (!InventoryManager::ContainsItem(item))
		return;
	
	InventoryManager::RemoveItem(item);

	this->hasBeenInvoked = true;
}

bool ConsumeItemEvent::IsAllowed()
{
	bool multiTriggerGuard = !this->multiTriggerAllowed && this->hasBeenInvoked; // Returns true if multi trigger is disabled AND event has been invoked before!
	bool hasRequiredItem = InventoryManager::ContainsItem(item);
	bool isSpecifiedItemValid = item != ItemKey::Any;

	return isSpecifiedItemValid && hasRequiredItem && !multiTriggerGuard;
}
