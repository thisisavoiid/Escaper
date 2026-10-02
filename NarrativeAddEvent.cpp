#include "NarrativeAddEvent.hpp"
#include "NarrativeManager.hpp"

NarrativeAddEvent::NarrativeAddEvent(const std::string& line)
{
	this->line = line;
}

void NarrativeAddEvent::Invoke()
{
	NarrativeManager::Add(this->line);
}

bool NarrativeAddEvent::IsAllowed()
{
	return true;
}
