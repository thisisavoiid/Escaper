#include "NarrativeSetEvent.hpp"
#include "NarrativeManager.hpp"

NarrativeSetEvent::NarrativeSetEvent(const std::vector<std::string>& lines)
{
	this->lines = lines;
}

void NarrativeSetEvent::Invoke()
{
	NarrativeManager::Set(this->lines);
}

bool NarrativeSetEvent::IsAllowed()
{
	return true;
}
