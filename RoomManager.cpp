#include "RoomManager.hpp"
#include "ChangeRoomEvent.hpp"
#include "PickupItemEvent.hpp"	
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
	auto livingRoom = std::make_unique<Room>("Living Room", "A cozy living room with an eerie atmosphere.", std::vector<Area>{});

	Room* livingRoomRawPtr = livingRoom.get();

	livingRoom->AddArea(
		Area(
			"Test Area",
			std::vector<Action> {
				{Action("Gain Treasure!", std::make_shared<PickupItemEvent>(ItemKey::Treasure_01))},
				{ Action("Gain Key!", std::make_shared<PickupItemEvent>(ItemKey::Key_01)) },
				{ Action(
					"Test multiple items needed!",
					std::vector<std::shared_ptr<ActionEvent>> {
						{std::make_shared<ConsumeItemEvent>(ItemKey::Treasure_01)},
						{std::make_shared<ConsumeItemEvent>(ItemKey::Key_01)}
					},
					std::vector<ItemKey> {
						{ItemKey::Treasure_01}, {ItemKey::Key_01}
					}
				)
				}
			}
		)
	);


	rooms.push_back(std::move(livingRoom));
}