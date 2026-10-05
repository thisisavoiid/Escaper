#pragma once

#include "ActionEvent.hpp"
#include "Room.hpp"
#include <memory>
#include <vector>
#include <string>

class NarrativeAddEvent : public ActionEvent {
public:
	NarrativeAddEvent(const std::string& a_line); 
	void Invoke() override;
	bool IsAllowed() override;
private:
	std::string m_line;                        
};