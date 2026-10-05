#pragma once

#include <string>
#include <vector>

class NarrativeManager {
public:
	static void Add(const std::string a_line);                 
	static void Set(const std::vector<std::string> a_lines);   
	static void Clear();
	static std::vector<std::string> GetLog();
private:
	static const int MAX_LINES = 5;                            
	static std::vector<std::string> m_log;                     
};