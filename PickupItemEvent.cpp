#include "PickupItemEvent.hpp"

PickupItemEvent::PickupItemEvent(E_ITEM_KEY a_item, bool a_allowMultiPickup) 
{
	this->m_item = a_item;                              
	this->m_multiTriggerAllowed = a_allowMultiPickup;   
}

void PickupItemEvent::Invoke()
{
	InventoryManager::AddItem(m_item);                  

	this->m_hasBeenInvoked = true;                      
}

bool PickupItemEvent::IsAllowed()
{
	bool isValidItemType = this->m_item != E_ITEM_KEY::IK_ANY; 
	bool multiTriggerGuard = !this->m_multiTriggerAllowed && this->m_hasBeenInvoked; 

	return isValidItemType && !multiTriggerGuard;
}