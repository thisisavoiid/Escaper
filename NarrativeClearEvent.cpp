#include "NarrativeClearEvent.hpp"
#include "NarrativeManager.hpp"

void NarrativeClearEvent::Invoke()
{
    NarrativeManager::Clear();
}

bool NarrativeClearEvent::IsAllowed()
{
    return true;
}