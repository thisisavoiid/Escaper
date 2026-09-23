#include "TextAdventureGame.hpp"
#include "ItemLibrary.hpp"
#include "InventoryManager.hpp"
#include "ItemData.hpp";

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
	auto& rooms = RoomManager::GetRooms();

	if (rooms.empty())
		return;

	RoomManager::ChangeRoom(rooms[0].get());

	RefreshOptions();

	MenuOption menuOption;
	menuOption.entries_option.transform = [&](EntryState state) {
		bool available = state.index < (int)optionsAvailable.size() ? optionsAvailable[state.index] : true;

		Element e = paragraph((state.active ? "▶ " : "  ") + state.label);

		if (!available) {
			if (state.active)
				e = e | color(Color::White) | bgcolor(Color::RGB(191, 0, 0));
			else
				e = e | color(Color::RGB(230, 150, 150)) | bgcolor(Color::RGB(77, 0, 0));
		}
		else {
			if (state.active)
				e = e | color(Color::White) | bgcolor(Color::RGB(20, 120, 60)) | bold;
			else
				e = e | color(Color::RGB(150, 220, 180));
		}

		return e;
		};

	Component menu = Menu(
		&options,
		&selection,
		menuOption
	);

	Component roomRenderer = Renderer([&] {return RenderRoomSection();});
	Component inventoryRenderer = Renderer([&] {return RenderInventorySection();});

	Component useButton = Button("PERFORM ACTION", [&] {ProcessSelection();}) | xflex;
	Component backButton = Button("GO BACK", [&] {GoBack();}) | xflex;

	Component topButtons = Container::Horizontal({ useButton, backButton }) | xflex;
	Component rightColumn = Container::Vertical({ inventoryRenderer, topButtons, menu });
	Component mainContainer = Container::Horizontal({ roomRenderer, rightColumn });

	Component appLayout = Renderer(mainContainer, [&] {
		return hbox(
			roomRenderer->Render() | xflex_grow,
			separator(),
			rightColumn->Render() | size(WIDTH, EQUAL, 32)
		);
		});

	app.Loop(appLayout);
}

void TextAdventureGame::ProcessSelection()
{
	Room* activeRoom = RoomManager::ActiveRoom;
	Area* activeArea = RoomManager::ActiveArea;

	switch (selectionState) {
	case SelectionState::Area:
		if (activeRoom == nullptr)
			break;

		//bool isAllowed = true;

		//if (!isAllowed)
		//	break;

		RoomManager::ChangeArea(&activeRoom->areas[selection]);
		selectionState = SelectionState::Action;

		break;

	case SelectionState::Action:
		if (activeArea == nullptr)
			break;

		Action target = activeArea->actions[selection];

		if (!target.IsAllowed())
			break;

		target.Invoke();

		selectionState = SelectionState::Area;

		break;
	}

	RefreshOptions();
}

void TextAdventureGame::RefreshOptions()
{
	Room* activeRoom = RoomManager::ActiveRoom;
	Area* activeArea = RoomManager::ActiveArea;

	options.clear();
	optionsAvailable.clear();

	selection = 0;

	switch (selectionState) {
	case SelectionState::Area:
		if (activeRoom == nullptr)
			break;

		for (const Area& area : activeRoom->areas) {
			bool isAvailable = true;
			options.push_back(area.name);
			optionsAvailable.push_back(isAvailable);
		}

		break;

	case SelectionState::Action:
		if (activeArea == nullptr)
			break;

		for (Action& action : activeArea->actions) {
			bool isAvailable = action.IsAllowed();
			options.push_back(action.name);
			optionsAvailable.push_back(isAvailable);
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

Element TextAdventureGame::RenderInventorySection()
{
	std::vector<ItemData> itemDataCollection = InventoryManager::GetInventory();

	Elements content;

	if (!itemDataCollection.empty()) {
		for (const ItemData& data : itemDataCollection)
			content.push_back(text("- " + data.Name) | color(Color::Yellow) | italic);
	}
	else {
		content.push_back(paragraph("No items in inventory.") | dim | italic);
	}

	Element inventoryWindow = window(
		text("Inventory"),
		vbox(std::move(content))
	) | frame | size(HEIGHT, EQUAL, 15);

	return inventoryWindow;
}

Element TextAdventureGame::RenderRoomSection()
{
	Room* activeRoom = RoomManager::ActiveRoom;
	Area* activeArea = RoomManager::ActiveArea;

	Elements content;

	content.push_back(paragraph(activeRoom->description) | dim | italic);
	content.push_back(separator());

	for (const Area& area : activeRoom->areas)
	{
		content.push_back(separator());
		content.push_back(text(area.name) | bold);
		for (const Action& action : area.actions) {
			std::string actionDisplayName = "- " + action.name;
			content.push_back(paragraph(actionDisplayName) | italic | dim);
		}
		content.push_back(separator());
	}

	Element roomWindow = window(
		text(activeRoom->name) | bold,
		vbox(std::move(content)) | frame
	) | size(HEIGHT, EQUAL, 25);

	return roomWindow;
}

