#include "InventoryManager.hpp"
#include <vector>
#include "ItemLibrary.hpp"

std::vector<ItemKey> InventoryManager::items;

bool InventoryManager::ContainsItem(ItemKey itemKey)
{
    if (items.empty())
        return false;
    
    if (std::count(items.begin(), items.end(), itemKey)) {
        return true;
    }

    return false;
}

void InventoryManager::AddItem(ItemKey item)
{
    items.push_back(item);
}

void InventoryManager::RemoveItem(ItemKey itemKey)
{
    if (items.empty())
        return;

    if (!ContainsItem(itemKey))
        return;

    std::erase(items, itemKey);
}

std::vector<ItemData> InventoryManager::GetInventory()
{
    std::vector<ItemData> itemDataCollection;

    for (ItemKey itemKey : items) {
        ItemData itemData = ItemLibrary::GetDataFromKey(itemKey);
        itemDataCollection.push_back(itemData);
    }

    return itemDataCollection;
}
