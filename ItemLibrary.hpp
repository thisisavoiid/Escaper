#pragma once

#include <unordered_map>
#include "ItemData.hpp"
#include "ItemKey.hpp"

class ItemLibrary {
public:
	static const inline std::unordered_map<ItemKey, ItemData> ItemKeyDataPairs{
		{ItemKey::Key_01, {"Key", "Rusty, old key!"}},
		{ItemKey::Treasure_01, {"Treasure", "A treasure with massive value!"}},
		{ItemKey::NamaEggPlushie, {"Nama Tama Plushie", "Undefined"}},
		{ItemKey::WolfFigurine, {"Wolf Figure (For furries!)", "Undefined"}},
		{ItemKey::LegoPlane, {"9/11 ahh plane (lego)", "Undefined"}},
		{ItemKey::CartonBox, {"Box made of carton", "Undefined"}}
	};

	static ItemData GetDataFromKey(ItemKey key);
};