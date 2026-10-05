#include "Action.hpp"
#include <iostream>
#include "InventoryManager.hpp"

void Action::Invoke()
{
	if (m_events.empty())                                   
		return;

	for (const std::shared_ptr<ActionEvent>& eventPtr : m_events) {  
		ActionEvent* event = eventPtr.get();

		if (event == nullptr)
			continue;

		event->Invoke();
	}
}

bool Action::IsAllowed()
{
	for (E_ITEM_KEY key : m_requiredItems) {                
		if (key == E_ITEM_KEY::IK_ANY)                      
			continue;

		if (!InventoryManager::ContainsItem(key))
			return false;
	}

	for (std::shared_ptr<ActionEvent> eventPtr : m_events) {
		ActionEvent* event = eventPtr.get();

		if (event == nullptr || !event->IsAllowed())
			return false;
	}

	return true;
}

Action::Action(std::string a_name, std::vector<std::shared_ptr<ActionEvent>> a_events, E_ITEM_KEY a_itemRequired)  
{
	this->m_name = std::move(a_name);                       
	this->m_events = std::move(a_events);                   
	this->m_requiredItems.push_back(a_itemRequired);        
}

Action::Action(std::string a_name, std::shared_ptr<ActionEvent> a_event, E_ITEM_KEY a_itemRequired)  
{
	this->m_name = std::move(a_name);                       
	this->m_events.push_back(a_event);                      
	this->m_requiredItems.push_back(a_itemRequired);        
}

Action::Action(std::string a_name, std::vector<std::shared_ptr<ActionEvent>> a_events, std::vector<E_ITEM_KEY> a_itemsRequired) 
{
	this->m_name = std::move(a_name);                       
	this->m_events = std::move(a_events);                   
	this->m_requiredItems = std::move(a_itemsRequired);     
}

Action::Action(std::string a_name, std::shared_ptr<ActionEvent> a_event, std::vector<E_ITEM_KEY> a_itemsRequired)
{
	this->m_name = std::move(a_name);                       
	this->m_events.push_back(a_event);                      
	this->m_requiredItems = std::move(a_itemsRequired);     
}