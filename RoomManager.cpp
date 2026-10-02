#include "RoomManager.hpp"
#include "ChangeRoomEvent.hpp"
#include "PickupItemEvent.hpp"	
#include "NarrativeAddEvent.hpp"
#include "NarrativeClearEvent.hpp"
#include "ConsumeItemEvent.hpp"
#include <memory>
#include <iostream>

Room* RoomManager::ActiveRoom = nullptr;
Area* RoomManager::ActiveArea = nullptr;

std::vector<std::unique_ptr<Room>> RoomManager::rooms;

void RoomManager::ChangeRoom(Room* room)
{
	if (room == ActiveRoom)
		return;

	ActiveRoom = room;
	ActiveArea = nullptr;

	if (!room || room->areas.empty())
		return;

	RoomManager::ActiveArea = &room->areas.front();
}

void RoomManager::ChangeArea(Area* area)
{
	ActiveArea = area;
}

std::vector<std::unique_ptr<Room>>& RoomManager::GetRooms()
{
	return RoomManager::rooms;
}

void RoomManager::CreateRooms()
{
	auto suiteRoom = std::make_unique<Room>("Suite 217", "Lorem ipsum...", std::vector<Area>{});
	auto corridorRoom = std::make_unique<Room>("Corridor", "Lorem Ipsum", std::vector<Area>{});

	Room* suiteRoomRawPtr = suiteRoom.get();
	Room* corridorRoomRawPtr = corridorRoom.get();

#pragma region SUITE ROOM
	suiteRoom->AddArea(
		Area(
			"Broken Mirror",
			std::vector<Action> {

			}
		)
	);

	suiteRoom->AddArea(
		Area(
			"Bedside Table",
			std::vector<Action> {

	}
		)
	);

	suiteRoom->AddArea(
		Area(
			"Corridor door",
			std::vector<Action> {
				{Action("Enter corridor", std::make_shared<ChangeRoomEvent>(corridorRoomRawPtr))}
		}
		)
	);
#pragma endregion

#pragma region CORRIDOR

	corridorRoom->AddArea(
		Area(
			"Bathroom door",
			std::vector<Action> {

	}
		)
	);

	corridorRoom->AddArea(
		Area(
			"Kitchen door",
			std::vector<Action> {

	}
		)
	);

	corridorRoom->AddArea(
		Area( 
			"Library door", 
			std::vector<Action> {

	}
		)
	);

	corridorRoom->AddArea(
		Area(
			"Basement door",
			std::vector<Action> {

	}
		)
	);

	corridorRoom->AddArea(
		Area(
			"Suite 217 door",
			std::vector<Action> {
		{Action("Enter Suite 217", std::make_shared<ChangeRoomEvent>(suiteRoomRawPtr))}
	}
		)
	);

#pragma endregion

	rooms.push_back(std::move(suiteRoom));
	rooms.push_back(std::move(corridorRoom));
}