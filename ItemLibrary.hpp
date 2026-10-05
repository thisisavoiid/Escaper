#pragma once

#include <unordered_map>
#include "ItemData.hpp"
#include "ItemKey.hpp"

class ItemLibrary {
public:
	static const inline std::unordered_map<E_ITEM_KEY, ItemData> ItemKeyDataPairs{ 
	{E_ITEM_KEY::IK_GLASS_SHARD, {"Glass Shard", "A sharp piece of broken mirror. Strange numbers flicker across its surface when the light hits it just right."}}, 
	{E_ITEM_KEY::IK_NOTEBOOK, {"Notebook", "A yellowed notebook. The entries speak of a Keeper and three lost vinyl records."}},
	{E_ITEM_KEY::IK_ATTIC_CODE, {"Attic Code", "A sequence of numbers that became visible on the fogged bathroom mirror."}},  
	{E_ITEM_KEY::IK_LANTERN, {"Lantern", "An old oil lantern. It only gives off a weak, flickering light. But it's better than nothing."}},
	{E_ITEM_KEY::IK_FRIDGE_HANDLE, {"Fridge Handle", "A dusty fridge handle. Maybe this one could be useful..."}},  
	{E_ITEM_KEY::IK_LIBRARY_KEY, {"Heavy Key", "A rusty key which grants access to the library."}}, 
	{E_ITEM_KEY::IK_RECORD_01, {"First Record", "A dusty vinyl record. The grooves are deep and dark."}},  
	{E_ITEM_KEY::IK_RECORD_02, {"Second Record", "The second record. It softly crackles when touched."}}, 
	{E_ITEM_KEY::IK_RECORD_03, {"Third Record", "The final record. It feels strangely warm to the touch."}} 
	};

	static ItemData GetDataFromKey(E_ITEM_KEY a_key);  
};