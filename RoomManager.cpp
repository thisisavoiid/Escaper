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
	auto kitchen = std::make_unique<Room>("Kitchen", "A lovely kitchen smelling faintly of ozone and old stew.", std::vector<Area>{});

	Room* livingRoomRawPtr = livingRoom.get();
	Room* kitchenRawPtr = kitchen.get();

	// LIVING ROOM
	livingRoom->AddArea(Area(
		"Kitchen Door",
		std::vector<Action>{
		Action("Enter kitchen", std::make_shared<ChangeRoomEvent>(kitchenRawPtr))
	}
	));
	
	livingRoom->AddArea(Area(
		"Shelf with keylock",
		std::vector<Action>{
		Action("Unlock shelf and grab whats inside", 
			std::vector<std::shared_ptr<ActionEvent>>{
				std::make_shared<ConsumeItemEvent>(ItemKey::Key_01),
				std::make_shared<PickupItemEvent>(ItemKey::Treasure_01)
			},
			ItemKey::Key_01
		)}
	));

	livingRoom->AddArea(Area(
		"Treasure trader",
		std::vector<Action>{
		Action("Trade treasure against key",
			std::vector<std::shared_ptr<ActionEvent>>{
				std::make_shared<ConsumeItemEvent>(ItemKey::Treasure_01),
				std::make_shared<PickupItemEvent>(ItemKey::Key_01)
			},
			ItemKey::Treasure_01
		),
		Action("this action will give you a treasure!",
			std::make_shared<PickupItemEvent>(ItemKey::Treasure_01)
		)
	}
	));

	livingRoom->AddArea(Area(
		"Treasure trader",
		std::vector<Action>{
		Action("Trade treasure against key",
			std::vector<std::shared_ptr<ActionEvent>>{
			std::make_shared<ConsumeItemEvent>(ItemKey::Treasure_01),
				std::make_shared<PickupItemEvent>(ItemKey::Key_01)
		},
			ItemKey::Treasure_01
		),
			Action("this action will give you a treasure!",
				std::make_shared<PickupItemEvent>(ItemKey::Treasure_01)
			)
	}
	));

	livingRoom->AddArea(Area(
		"Treasure trader",
		std::vector<Action>{
		Action("Trade treasure against key",
			std::vector<std::shared_ptr<ActionEvent>>{
			std::make_shared<ConsumeItemEvent>(ItemKey::Treasure_01),
				std::make_shared<PickupItemEvent>(ItemKey::Key_01)
		},
			ItemKey::Treasure_01
		),
			Action("this action will give you a treasure!",
				std::make_shared<PickupItemEvent>(ItemKey::Treasure_01)
			)
	}
	));

	livingRoom->AddArea(Area(
		"Treasure trader",
		std::vector<Action>{
		Action("Trade treasure against key",
			std::vector<std::shared_ptr<ActionEvent>>{
			std::make_shared<ConsumeItemEvent>(ItemKey::Treasure_01),
				std::make_shared<PickupItemEvent>(ItemKey::Key_01)
		},
			ItemKey::Treasure_01
		),
			Action("this action will give you a treasure!",
				std::make_shared<PickupItemEvent>(ItemKey::Treasure_01)
			)
	}
	));

	livingRoom->AddArea(Area(
		"Treasure trader",
		std::vector<Action>{
		Action("Trade treasure against key",
			std::vector<std::shared_ptr<ActionEvent>>{
			std::make_shared<ConsumeItemEvent>(ItemKey::Treasure_01),
				std::make_shared<PickupItemEvent>(ItemKey::Key_01)
		},
			ItemKey::Treasure_01
		),
			Action("this action will give you a treasure!",
				std::make_shared<PickupItemEvent>(ItemKey::Treasure_01)
			)
	}
	));

	livingRoom->AddArea(Area(
		"Treasure trader",
		std::vector<Action>{
		Action("Trade treasure against key",
			std::vector<std::shared_ptr<ActionEvent>>{
			std::make_shared<ConsumeItemEvent>(ItemKey::Treasure_01),
				std::make_shared<PickupItemEvent>(ItemKey::Key_01)
		},
			ItemKey::Treasure_01
		),
			Action("this action will give you a treasure!",
				std::make_shared<PickupItemEvent>(ItemKey::Treasure_01)
			)
	}
	));

	livingRoom->AddArea(Area(
		"Treasure trader",
		std::vector<Action>{
		Action("Trade treasure against key",
			std::vector<std::shared_ptr<ActionEvent>>{
			std::make_shared<ConsumeItemEvent>(ItemKey::Treasure_01),
				std::make_shared<PickupItemEvent>(ItemKey::Key_01)
		},
			ItemKey::Treasure_01
		),
			Action("this action will give you a treasure!",
				std::make_shared<PickupItemEvent>(ItemKey::Treasure_01)
			)
	}
	));
	// KITCHEN
	kitchen->AddArea(Area(
		"Shelf",
		std::vector<Action>{
		Action("Grab Key", std::make_shared<PickupItemEvent>(ItemKey::Key_01))
	}
	));

	kitchen->AddArea(Area(
		"Living Room Door",
		std::vector<Action>{
		Action("Enter living room", std::make_shared<ChangeRoomEvent>(livingRoomRawPtr))
	}
	));

	rooms.push_back(std::move(livingRoom));
	rooms.push_back(std::move(kitchen));
}