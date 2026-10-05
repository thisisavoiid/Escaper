#pragma once

#include "Room.hpp"
#include "InventoryManager.hpp"

class PickupItemEvent : public ActionEvent {
public:
	E_ITEM_KEY m_item;                      
	PickupItemEvent(E_ITEM_KEY a_item, bool a_allowMultiPickup = false); 
	void Invoke() override;
	bool IsAllowed() override;
private:
	bool m_multiTriggerAllowed;            
	bool m_hasBeenInvoked = false;         
};