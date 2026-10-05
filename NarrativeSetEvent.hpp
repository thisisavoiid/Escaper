#pragma once

#include "ActionEvent.hpp"
#include "Room.hpp"
#include <memory>
#include <vector>
#include <string>

class NarrativeSetEvent : public ActionEvent {
public:
	NarrativeSetEvent(const std::vector<std::string>& a_lines); 
	NarrativeSetEvent(const std::string& a_line);               
	void Invoke() override;
	bool IsAllowed() override;
private:
	std::vector<std::string> m_lines;        
};