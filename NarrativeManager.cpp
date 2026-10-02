#include "NarrativeManager.hpp"
#include <string>
#include <vector>

std::vector<std::string> NarrativeManager::log;

void NarrativeManager::Add(const std::string line)
{
	NarrativeManager::log.push_back(line);

	//todo add buffer cap
}

void NarrativeManager::Set(const std::vector<std::string> lines)
{
	NarrativeManager::log.clear();

	for (const std::string& line : lines) {
		NarrativeManager::log.push_back(line);
	}
}

void NarrativeManager::Clear()
{
	NarrativeManager::log.clear();
}

std::vector<std::string> NarrativeManager::GetLog()
{
	return NarrativeManager::log;
}
