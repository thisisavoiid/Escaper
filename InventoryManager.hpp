#pragma once

#include <vector>
#include "ItemKey.hpp"
#include "ItemData.hpp"

class InventoryManager {
public:
	static bool ContainsItem(ItemKey itemKey);
	static void AddItem(ItemKey itemKey);
	static void RemoveItem(ItemKey itemKey);
	static std::vector<ItemData> GetInventory();

private:
	static std::vector<ItemKey> items;
};