#include "ItemLibrary.hpp"

ItemData ItemLibrary::GetDataFromKey(E_ITEM_KEY a_key)  
{
    if (ItemKeyDataPairs.empty())
        return ItemData();

    return ItemKeyDataPairs.at(a_key);                  
}