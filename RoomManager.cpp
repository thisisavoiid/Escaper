#include "RoomManager.hpp"
#include "ChangeRoomEvent.hpp"

Room* RoomManager::ActiveRoom = nullptr;
Area* RoomManager::ActiveArea = nullptr;

std::vector<Room*> RoomManager::rooms;

void RoomManager::ChangeRoom(Room* room)
{
	RoomManager::ActiveRoom = room;

	if (room->areas.size() < 1)
		return;

	RoomManager::ActiveArea = &room->areas[0];
}

void RoomManager::ChangeArea(Area* area)
{
	RoomManager::ActiveArea = area;
}

std::vector<Room*>& RoomManager::GetRooms()
{
	return RoomManager::rooms;
}

void RoomManager::CreateRooms()
{
	Room* livingRoom = new Room(
		"Living room",
		"A cozy living room",
		{}
	);

	Room* kitchen = new Room(
		"Kitchen",
		"A lovely kitchen",
		{}
	);

	livingRoom->AddArea(
		Area(
			"Kitchen Door",
			{
				Action("Enter kitchen", new ChangeRoomEvent(kitchen))
			}
		)
	);

	livingRoom->AddArea(
		Area(
			"TV",
			{
				Action("Watch TV", new ChangeRoomEvent(kitchen)),
				Action("Smash TV", new ChangeRoomEvent(kitchen)),
				Action("Sell TV", new ChangeRoomEvent(kitchen))
			}
		)
	);

	livingRoom->AddArea(
		Area(
			"Shelf",
			{
				Action("Search", new ChangeRoomEvent(kitchen)),
				Action("Eat", new ChangeRoomEvent(kitchen)),
				Action("Set on Fire", new ChangeRoomEvent(kitchen))
			}
		)
	);

	kitchen->AddArea(
		Area(
			"Living Room Door",
			{
				Action("Enter living room", new ChangeRoomEvent(livingRoom))
			}
		)
	);

	kitchen->AddArea(
		Area(
			"Oven",
			{
				Action("Bake a cake!", new ChangeRoomEvent(livingRoom)),
				Action("Set the house on fire!", new ChangeRoomEvent(livingRoom)),
				Action("Clean the oven!", new ChangeRoomEvent(livingRoom))
			}
		)
	);

	RoomManager::rooms.push_back(kitchen);
	RoomManager::rooms.push_back(livingRoom);
}
