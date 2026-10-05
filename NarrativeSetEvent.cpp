#include "NarrativeSetEvent.hpp"
#include "NarrativeManager.hpp"

NarrativeSetEvent::NarrativeSetEvent(const std::vector<std::string>& a_lines)  
{
	this->m_lines = a_lines;                    
}

NarrativeSetEvent::NarrativeSetEvent(const std::string& a_line)  
{
	this->m_lines.push_back(a_line);            
}

void NarrativeSetEvent::Invoke()
{
	NarrativeManager::Set(this->m_lines);       
}

bool NarrativeSetEvent::IsAllowed()
{
	return true;
}