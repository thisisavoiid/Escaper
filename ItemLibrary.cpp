#include "ItemLibrary.hpp"

ItemData ItemLibrary::GetDataFromKey(ItemKey key)
{
    if (ItemKeyDataPairs.empty())
        return ItemData();

    //if (!ItemKeyDataPairs.count(key))
    //    return ItemData();

    return ItemKeyDataPairs.at(key);
}
