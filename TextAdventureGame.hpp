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
	App app = ScreenInteractive::TerminalOutput();
	RoomManager roomManager = RoomManager();

	SelectionState selectionState = SelectionState::Area;

	std::vector<std::string> options;
	std::vector<bool> optionsAvailable;

	int selection = 0;

	void ProcessSelection();
	void RefreshOptions();
	void GoBack();
	
	Element RenderRoomSection();
	Element RenderInventorySection();
};