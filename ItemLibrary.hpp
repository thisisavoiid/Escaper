#pragma once

#include <unordered_map>
#include "ItemData.hpp"
#include "ItemKey.hpp"

class ItemLibrary {
public:
	static const inline std::unordered_map<ItemKey, ItemData> ItemKeyDataPairs{
	{ItemKey::Key_01, {"Key", "Rusty, old key!"}},
	{ItemKey::Treasure_01, {"Treasure", "A treasure with massive value!"}}
	};

	static ItemData GetDataFromKey(ItemKey key);
};