#include "ConsumeItemEvent.hpp"
#include "InventoryManager.hpp"
#include "ItemKey.hpp"

ConsumeItemEvent::ConsumeItemEvent(E_ITEM_KEY a_item, bool a_allowMultiTrigger)  
{
	this->m_item = a_item;                             
	this->m_multiTriggerAllowed = a_allowMultiTrigger; 
}

void ConsumeItemEvent::Invoke()
{
	if (!InventoryManager::ContainsItem(m_item))       
		return;

	InventoryManager::RemoveItem(m_item);              

	this->m_hasBeenInvoked = true;                     
}

bool ConsumeItemEvent::IsAllowed()
{
	bool multiTriggerGuard = !this->m_multiTriggerAllowed && this->m_hasBeenInvoked;
	bool hasRequiredItem = InventoryManager::ContainsItem(m_item);               
	bool isSpecifiedItemValid = m_item != E_ITEM_KEY::IK_ANY;                    

	return isSpecifiedItemValid && hasRequiredItem && !multiTriggerGuard;
}