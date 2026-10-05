#include "InventoryManager.hpp"
#include <vector>
#include "ItemLibrary.hpp"

std::vector<E_ITEM_KEY> InventoryManager::m_items;      

bool InventoryManager::ContainsItem(E_ITEM_KEY a_itemKey)  
{
    if (m_items.empty())                               
        return false;

    if (std::count(m_items.begin(), m_items.end(), a_itemKey)) { 
        return true;
    }

    return false;
}

void InventoryManager::AddItem(E_ITEM_KEY a_item)       
{
    m_items.push_back(a_item);                          
}

void InventoryManager::RemoveItem(E_ITEM_KEY a_itemKey) 
{
    if (m_items.empty())                                
        return;

    if (!ContainsItem(a_itemKey))                       
        return;

    std::erase(m_items, a_itemKey);                     
}

std::vector<ItemData> InventoryManager::GetInventory()
{
    std::vector<ItemData> itemDataCollection;

    for (E_ITEM_KEY itemKey : m_items) {                
        ItemData itemData = ItemLibrary::GetDataFromKey(itemKey);
        itemDataCollection.push_back(itemData);
    }

    return itemDataCollection;
}