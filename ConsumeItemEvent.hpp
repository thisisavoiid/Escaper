#pragma once

#include "ActionEvent.hpp"
#include "ItemKey.hpp" 

class ConsumeItemEvent : public ActionEvent {
public:
	E_ITEM_KEY m_item;                     
	ConsumeItemEvent(E_ITEM_KEY a_item, bool a_allowMultiTrigger = false);  
	void Invoke() override;
	bool IsAllowed() override;
private:
	bool m_multiTriggerAllowed;             
	bool m_hasBeenInvoked = false;          
};