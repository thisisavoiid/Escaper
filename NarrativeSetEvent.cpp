#include "NarrativeSetEvent.hpp"
#include "NarrativeManager.hpp"

NarrativeSetEvent::NarrativeSetEvent(const std::vector<std::string>& lines)
{
	this->lines = lines;
}

NarrativeSetEvent::NarrativeSetEvent(const std::string& line)
{
	this->lines.push_back(line);
}

void NarrativeSetEvent::Invoke()
{
	NarrativeManager::Set(this->lines);
}

bool NarrativeSetEvent::IsAllowed()
{
	return true;
}
