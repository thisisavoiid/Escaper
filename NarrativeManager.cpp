#include "NarrativeManager.hpp"
#include <string>
#include <vector>

std::vector<std::string> NarrativeManager::m_log;               

void NarrativeManager::Add(const std::string a_line)            
{
	NarrativeManager::m_log.push_back(a_line);                  

	if (NarrativeManager::m_log.size() > NarrativeManager::MAX_LINES) {  
		NarrativeManager::m_log.erase(NarrativeManager::m_log.begin());  
	}
}

void NarrativeManager::Set(const std::vector<std::string> a_lines)  
{
	NarrativeManager::m_log.clear();                            

	for (const std::string& line : a_lines) {                   
		NarrativeManager::m_log.push_back(line);                
	}
}

void NarrativeManager::Clear()
{
	NarrativeManager::m_log.clear();                            
}

std::vector<std::string> NarrativeManager::GetLog()
{
	return NarrativeManager::m_log;                             
}