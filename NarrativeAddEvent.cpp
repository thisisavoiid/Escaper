#include "NarrativeAddEvent.hpp"
#include "NarrativeManager.hpp"

NarrativeAddEvent::NarrativeAddEvent(const std::string& a_line)  
{
	this->m_line = a_line;                      
}

void NarrativeAddEvent::Invoke()
{
	NarrativeManager::Add(this->m_line);        
}

bool NarrativeAddEvent::IsAllowed()
{
	return true;
}