#pragma once

#include <string>
#include <vector>

class NarrativeManager {
public:
	static void Add(const std::string line);
	static void Set(const std::vector<std::string> lines);
	static void Clear();
	static std::vector<std::string> GetLog();
private:
	static const int maxLines = 20;
	static std::vector<std::string> log;
};