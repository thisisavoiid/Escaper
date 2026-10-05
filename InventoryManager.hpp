#pragma once

#include <vector>
#include "ItemKey.hpp"
#include "ItemData.hpp"

class InventoryManager {
public:
	static bool ContainsItem(E_ITEM_KEY a_itemKey);     
	static void AddItem(E_ITEM_KEY a_itemKey);          
	static void RemoveItem(E_ITEM_KEY a_itemKey);       
	static std::vector<ItemData> GetInventory();

private:
	static std::vector<E_ITEM_KEY> m_items;             
};