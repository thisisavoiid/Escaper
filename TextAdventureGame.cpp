#include "TextAdventureGame.hpp"

TextAdventureGame::TextAdventureGame()
{

}

TextAdventureGame::~TextAdventureGame()
{
	app.ExitLoopClosure();
}

void TextAdventureGame::Run()
{
	RoomManager::CreateRooms();
	auto rooms = RoomManager::GetRooms();
	RoomManager::ChangeRoom(rooms[0]);

	RefreshOptions();

	Component menu = Menu(
		&options,
		&selection
	);

	Component roomRenderer = Renderer([&] {return RenderRoomSection();});

	Component useButton = Button("PERFORM ACTION", [&] {ProcessSelection();});
	Component backButton = Button("GO BACK", [&] {GoBack();});

	Component screenContainer = Container::Horizontal({
		roomRenderer,
		menu,
		useButton,
		backButton
		});

	app.Loop(screenContainer);
}

void TextAdventureGame::ProcessSelection()
{
	Room* activeRoom = RoomManager::ActiveRoom;
	Area* activeArea = RoomManager::ActiveArea;

	switch (selectionState) {
	case SelectionState::Area:
		if (activeRoom != nullptr) {
			RoomManager::ChangeArea(&activeRoom->areas[selection]);
			selectionState = SelectionState::Action;
		}
		break;
	case SelectionState::Action:
		if (activeArea != nullptr) {
			activeArea->actions[selection].Invoke();
		}
		break;
	}

	RefreshOptions();
}

void TextAdventureGame::RefreshOptions()
{
	Room* activeRoom = RoomManager::ActiveRoom;
	Area* activeArea = RoomManager::ActiveArea;

	options.clear();

	selection = 0;

	switch (selectionState) {
	case SelectionState::Area:
		if (activeRoom != nullptr) {
			for (const Area& area : activeRoom->areas) {
				options.push_back(area.name);
			}
		}
		break;
	case SelectionState::Action:
		if (activeArea != nullptr) {
			for (const Action& action : activeArea->actions) {
				options.push_back(action.name);
			}
		}
		break;
	}
}

void TextAdventureGame::GoBack()
{
	switch (selectionState) {
		case SelectionState::Action:
			RoomManager::ChangeArea(nullptr);
			selectionState = SelectionState::Area;
			break;
	}

	RefreshOptions();
}

Element TextAdventureGame::RenderRoomSection()
{
	Room* activeRoom = RoomManager::ActiveRoom;
	Area* activeArea = RoomManager::ActiveArea;

	Elements content;

	content.push_back(text(activeRoom->description));
	content.push_back(separator());

	for (const Area& area : activeRoom->areas)
	{
		content.push_back(separator());
		content.push_back(text(area.name) | bold);
		for (const Action& action : area.actions) {
			content.push_back(text("- " + action.name) | italic);
		}
		content.push_back(separator());
	}

	Element roomWindow = window(
		text(activeRoom->name),
		vbox(std::move(content))
	);

	return roomWindow;
}

