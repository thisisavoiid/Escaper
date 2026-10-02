#pragma once

#include <unordered_map>
#include "ItemData.hpp"
#include "ItemKey.hpp"

class ItemLibrary {
public:
	static const inline std::unordered_map<ItemKey, ItemData> ItemKeyDataPairs{
	{ItemKey::Glass_Shard, {"Glass Shard", "A sharp piece of broken mirror. Strange numbers flicker across its surface when the light hits it just right."}},
	{ItemKey::Notebook, {"Notebook", "A yellowed notebook. The entries speak of a Keeper and three lost vinyl records."}},
	{ItemKey::Gas_Key, {"Gas Key", "An old, heavy key for the gas valve. It smells faintly of metal and dust."}},
	{ItemKey::Attic_Code, {"Attic Code", "A sequence of numbers that became visible on the fogged bathroom mirror."}},
	{ItemKey::Rusty_Knife, {"Rusty Knife", "Dull and covered in rust, but the blade is still sharp enough to cut through a cable."}},
	{ItemKey::Lantern, {"Lantern", "An old oil lantern. It only gives off a weak, flickering light. But it's better than nothing."}},
	{ItemKey::Record_01, {"First Record", "A dusty vinyl record. The grooves are deep and dark."}},
	{ItemKey::Record_02, {"Second Record", "The second record. It softly crackles when touched."}},
	{ItemKey::Record_03, {"Third Record", "The final record. It feels strangely warm to the touch."}}
	};

	static ItemData GetDataFromKey(ItemKey key);
};