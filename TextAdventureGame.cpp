#include "TextAdventureGame.hpp"
#include "ItemLibrary.hpp"
#include "InventoryManager.hpp"
#include "ItemData.hpp";
#include "NarrativeManager.hpp"

TextAdventureGame::TextAdventureGame()
{

}

TextAdventureGame::~TextAdventureGame()
{
	m_app.ExitLoopClosure();
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
		bool available = state.index < (int)m_optionsAvailable.size() ? m_optionsAvailable[state.index] : true;

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
		&m_options,
		&m_selection,
		menuOption
	);

	Component narrativeRenderer = Renderer([&] {return RenderNarrativeSection();});
	Component inventoryRenderer = Renderer([&] {return RenderInventorySection();});

	Component useButton = Button("PERFORM ACTION", [&] {ProcessSelection();}) | xflex;
	Component backButton = Button("GO BACK", [&] {GoBack();}) | xflex;

	Component topButtons = Container::Horizontal({ useButton, backButton }) | xflex;
	Component rightColumn = Container::Vertical({ inventoryRenderer | xflex, topButtons, menu });
	Component mainContainer = Container::Horizontal({ narrativeRenderer, rightColumn });

	Component appLayout = Renderer(mainContainer, [&] {
		return hbox(
			narrativeRenderer->Render() | xflex_grow,
			separator(),
			rightColumn->Render() | size(WIDTH, EQUAL, 32)
		);
		});

	m_app.Loop(appLayout);
}

void TextAdventureGame::ProcessSelection()
{
	Room* activeRoom = RoomManager::m_activeRoom;
	Area* activeArea = RoomManager::m_activeArea;

	switch (m_selectionState) {
	case E_SELECTION_STATE::SS_AREA:
		if (activeRoom == nullptr)
			break;

		RoomManager::ChangeArea(&activeRoom->m_areas[m_selection]);
		m_selectionState = E_SELECTION_STATE::SS_ACTION;

		break;

	case E_SELECTION_STATE::SS_ACTION:
		if (activeArea == nullptr)
			break;

		Action target = activeArea->m_actions[m_selection];

		if (!target.IsAllowed())
			break;

		target.Invoke();

		m_selectionState = E_SELECTION_STATE::SS_AREA;

		break;
	}

	RefreshOptions();
}

void TextAdventureGame::RefreshOptions()
{
	Room* activeRoom = RoomManager::m_activeRoom;
	Area* activeArea = RoomManager::m_activeArea;

	m_options.clear();
	m_optionsAvailable.clear();

	m_selection = 0;

	switch (m_selectionState) {
	case E_SELECTION_STATE::SS_AREA:
		if (activeRoom == nullptr)
			break;

		for (const Area& area : activeRoom->m_areas) {
			bool isAvailable = true;
			m_options.push_back(area.m_name);
			m_optionsAvailable.push_back(isAvailable);
		}

		break;

	case E_SELECTION_STATE::SS_ACTION:
		if (activeArea == nullptr)
			break;

		for (Action& action : activeArea->m_actions) {
			bool isAvailable = action.IsAllowed();
			m_options.push_back(action.m_name);
			m_optionsAvailable.push_back(isAvailable);
		}

		break;
	}
}

void TextAdventureGame::GoBack()
{
	switch (m_selectionState) {
	case E_SELECTION_STATE::SS_ACTION:
		RoomManager::ChangeArea(nullptr);
		m_selectionState = E_SELECTION_STATE::SS_AREA;
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
		{
			content.push_back(text("- " + data.m_name) | color(Color::Yellow) | italic);
		}
	}
	else {
		content.push_back(paragraph("No items in inventory.") | dim | italic);
	}

	Element inventoryWindow = window(
		text("Inventory"),
		vbox(std::move(content))
	) | yframe | size(HEIGHT, EQUAL, 15);

	return inventoryWindow;
}

Element TextAdventureGame::RenderNarrativeSection()
{
	std::vector<std::string> narrativeLog = NarrativeManager::GetLog();

	int logSize = static_cast<int>(narrativeLog.size() - 1);

	Elements content;

	if (!narrativeLog.empty())
	{
		for (int i = logSize; i >= 0; i--) {
			Decorator colorDecorator = i == logSize ? (color(Color::Yellow)) : (color(Color::Orange1) | dim);

			content.push_back(
				paragraph(narrativeLog[i]) | borderEmpty | colorDecorator
			);
		}
	}
	else {
		content.push_back(paragraph("No actions performed yet.") | dim | italic);
	}

	Element narrativeWindow = window(
		text("Narrative"),
		vbox(std::move(content))
	) | yframe | flex | size(HEIGHT, EQUAL, 25);

	return narrativeWindow;
}