#pragma once

#include <vector>
#include <string>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include "Room.hpp"
#include <iostream>
#include <utility>
#include "SelectionState.hpp"
#include "ChangeRoomEvent.hpp"
#include "RoomManager.hpp"

using namespace ftxui;

class TextAdventureGame {
public:
	TextAdventureGame();
	~TextAdventureGame();
	void Run();
private:
	App m_app = ScreenInteractive::TerminalOutput();       
	RoomManager m_roomManager = RoomManager();             

	E_SELECTION_STATE m_selectionState = E_SELECTION_STATE::SS_AREA;  

	std::vector<std::string> m_options;                     
	std::vector<bool> m_optionsAvailable;                   

	int m_selection = 0;                                    

	void ProcessSelection();
	void RefreshOptions();
	void GoBack();

	Element RenderNarrativeSection();
	Element RenderInventorySection();
};