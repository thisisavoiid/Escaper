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
	auto suiteRoom = std::make_unique<Room>(
		"Suite 217",
		"A dark, dusty hotel suite. The air smells of mold and old carpet. The curtains hang in tatters.",
		std::vector<Area>{}
	);

	auto corridorRoom = std::make_unique<Room>(
		"Corridor",
		"A long, cold hallway. Doors line both sides. Somewhere in the walls a faint crackling can be heard.",
		std::vector<Area>{}
	);

	auto bathroomRoom = std::make_unique<Room>(
		"Bathroom",
		"Water drips in irregular intervals. The air is heavy and unsettingly cool. An old towel hangs over part of the wall.",
		std::vector<Area>{}
	);

	auto kitchenRoom = std::make_unique<Room>(
		"Kitchen",
		"The kitchen is silent. An old refrigerator stands in the corner, its handle missing.",
		std::vector<Area>{}
	);

	auto libraryRoom = std::make_unique<Room>(
		"Library",
		"Dust dances in the weak light. Tall bookshelves line the walls. An old gramophone sits in the corner.",
		std::vector<Area>{}
	);

	auto atticRoom = std::make_unique<Room>(
		"Attic",
		"The attic is narrow and full of shadows. Cobwebs hang like grey curtains from the beams.",
		std::vector<Area>{}
	);

	auto basementRoom = std::make_unique<Room>(
		"Basement",
		"The basement is dark and damp. Without light the corridors all look the same.",
		std::vector<Area>{}
	);

	auto ballroomRoom = std::make_unique<Room>(
		"Ballroom",
		"A vast, decaying hall. Broken chandeliers hang from the ceiling. In the center stands an old record player.",
		std::vector<Area>{}
	);

	Room* suiteRoomRawPtr = suiteRoom.get();
	Room* corridorRoomRawPtr = corridorRoom.get();
	Room* bathroomRoomRawPtr = bathroomRoom.get();
	Room* kitchenRoomRawPtr = kitchenRoom.get();
	Room* libraryRoomRawPtr = libraryRoom.get();
	Room* atticRoomRawPtr = atticRoom.get();
	Room* basementRoomRawPtr = basementRoom.get();
	Room* ballroomRoomRawPtr = ballroomRoom.get();

#pragma region SUITE ROOM

	suiteRoom->AddArea(
		Area(
			"Broken Mirror",
			std::vector<Action>{
		Action(
			"Take the glass shard",
			std::vector<std::shared_ptr<ActionEvent>>{
			std::make_shared<PickupItemEvent>(ItemKey::Glass_Shard),
				std::make_shared<NarrativeAddEvent>("You carefully pick up a sharp piece of the broken mirror. Strange reflections flicker across its surface.")
		}
		)
	}
		)
	);

	suiteRoom->AddArea(
		Area(
			"Bedside Table",
			std::vector<Action>{
		Action(
			"Take the notebook",
			std::vector<std::shared_ptr<ActionEvent>>{
			std::make_shared<PickupItemEvent>(ItemKey::Notebook),
				std::make_shared<NarrativeAddEvent>("You pick up the yellowed notebook. The hurried writing speaks of a Keeper and three lost vinyl records.")
		}
		)
	}
		)
	);

	suiteRoom->AddArea(
		Area(
			"Corridor door",
			std::vector<Action>{
		Action(
			"Enter the corridor",
			std::vector<std::shared_ptr<ActionEvent>>{
			std::make_shared<ChangeRoomEvent>(corridorRoomRawPtr),
				std::make_shared<NarrativeAddEvent>("You step into the long, cold corridor. The air feels heavier here.")
		}
		)
	}
		)
	);

#pragma endregion

#pragma region CORRIDOR

	corridorRoom->AddArea(
		Area(
			"Bathroom door",
			std::vector<Action>{
		Action(
			"Enter the bathroom",
			std::vector<std::shared_ptr<ActionEvent>>{
			std::make_shared<ChangeRoomEvent>(bathroomRoomRawPtr),
				std::make_shared<NarrativeAddEvent>("You push the door open. The smell of mildew grows stronger.")
		}
		)
	}
		)
	);

	corridorRoom->AddArea(
		Area(
			"Kitchen door",
			std::vector<Action>{
		Action(
			"Enter the kitchen",
			std::vector<std::shared_ptr<ActionEvent>>{
			std::make_shared<ChangeRoomEvent>(kitchenRoomRawPtr),
				std::make_shared<NarrativeAddEvent>("You enter the silent kitchen. An old refrigerator stands in the corner.")
		}
		)
	}
		)
	);

	corridorRoom->AddArea(
		Area(
			"Library door",
			std::vector<Action>{
		Action(
			"Enter the library",
			std::vector<std::shared_ptr<ActionEvent>>{
			std::make_shared<ChangeRoomEvent>(libraryRoomRawPtr),
				std::make_shared<NarrativeAddEvent>("The heavy door opens with a low creak. Dust hangs in the air.")
		},
			{ ItemKey::Library_Key }
		)
	}
		)
	);

	corridorRoom->AddArea(
		Area(
			"Attic door",
			std::vector<Action>{
		Action(
			"Enter the attic",
			std::vector<std::shared_ptr<ActionEvent>>{
			std::make_shared<ChangeRoomEvent>(atticRoomRawPtr),
				std::make_shared<NarrativeAddEvent>("You climb the narrow stairs into the attic. Shadows cling to every corner.")
		},
			{ ItemKey::Attic_Code }
		)
	}
		)
	);

	corridorRoom->AddArea(
		Area(
			"Basement door",
			std::vector<Action>{
		Action(
			"Enter the basement",
			std::vector<std::shared_ptr<ActionEvent>>{
			std::make_shared<ChangeRoomEvent>(basementRoomRawPtr),
				std::make_shared<NarrativeAddEvent>("You descend into the damp darkness of the basement.")
		}
		)
	}
		)
	);

	corridorRoom->AddArea(
		Area(
			"Ballroom door",
			std::vector<Action>{
		Action(
			"Enter the ballroom",
			std::vector<std::shared_ptr<ActionEvent>>{
			std::make_shared<ChangeRoomEvent>(ballroomRoomRawPtr),
				std::make_shared<NarrativeAddEvent>("You step into the vast, decaying ballroom. An old record player stands in the center.")
		}
		)
	}
		)
	);

	corridorRoom->AddArea(
		Area(
			"Suite 217 door",
			std::vector<Action>{
		Action(
			"Enter Suite 217",
			std::vector<std::shared_ptr<ActionEvent>>{
			std::make_shared<ChangeRoomEvent>(suiteRoomRawPtr),
				std::make_shared<NarrativeAddEvent>("You return to the dusty suite.")
		}
		)
	}
		)
	);

#pragma endregion

#pragma region BATHROOM

	bathroomRoom->AddArea(
		Area(
			"Old Towel",
			std::vector<Action>{
		Action(
			"Cut the towel with the glass shard",
			std::vector<std::shared_ptr<ActionEvent>>{
			std::make_shared<PickupItemEvent>(ItemKey::Attic_Code),
				std::make_shared<NarrativeAddEvent>("You slice through the rotting towel. Behind it, scratched into the wall, is a sequence of numbers.")
		},
			{ ItemKey::Glass_Shard }
		)
	}
		)
	);

	bathroomRoom->AddArea(
		Area(
			"Corridor door",
			std::vector<Action>{
		Action(
			"Return to the corridor",
			std::vector<std::shared_ptr<ActionEvent>>{
			std::make_shared<ChangeRoomEvent>(corridorRoomRawPtr),
				std::make_shared<NarrativeAddEvent>("You leave the bathroom and step back into the corridor.")
		}
		)
	}
		)
	);

#pragma endregion

#pragma region KITCHEN

	kitchenRoom->AddArea(
		Area(
			"Refrigerator",
			std::vector<Action>{
		Action(
			"Attach the fridge handle",
			std::vector<std::shared_ptr<ActionEvent>>{
			std::make_shared<ConsumeItemEvent>(ItemKey::Fridge_Handle),
				std::make_shared<PickupItemEvent>(ItemKey::Library_Key),
				std::make_shared<NarrativeAddEvent>("You attach the handle. The refrigerator door opens with a soft click. Inside lies a heavy key.")
		},
			{ ItemKey::Fridge_Handle }
		)
	}
		)
	);

	kitchenRoom->AddArea(
		Area(
			"Corridor door",
			std::vector<Action>{
		Action(
			"Return to the corridor",
			std::vector<std::shared_ptr<ActionEvent>>{
			std::make_shared<ChangeRoomEvent>(corridorRoomRawPtr),
				std::make_shared<NarrativeAddEvent>("You leave the kitchen.")
		}
		)
	}
		)
	);

#pragma endregion

#pragma region LIBRARY

	libraryRoom->AddArea(
		Area(
			"Bookshelf",
			std::vector<Action>{
		Action(
			"Search the shelves",
			std::vector<std::shared_ptr<ActionEvent>>{
			std::make_shared<PickupItemEvent>(ItemKey::Record_01),
				std::make_shared<NarrativeAddEvent>("Between the yellowed books you find a dusty vinyl record. Record 1.")
		}
		)
	}
		)
	);

	libraryRoom->AddArea(
		Area(
			"Corridor door",
			std::vector<Action>{
		Action(
			"Return to the corridor",
			std::vector<std::shared_ptr<ActionEvent>>{
			std::make_shared<ChangeRoomEvent>(corridorRoomRawPtr),
				std::make_shared<NarrativeAddEvent>("You leave the library.")
		}
		)
	}
		)
	);

#pragma endregion

#pragma region ATTIC

	atticRoom->AddArea(
		Area(
			"Old Chest",
			std::vector<Action>{
		Action(
			"Open the chest",
			std::vector<std::shared_ptr<ActionEvent>>{
			std::make_shared<PickupItemEvent>(ItemKey::Record_02),
				std::make_shared<NarrativeAddEvent>("Inside the chest lies a warm vinyl record. Record 2.")
		}
		)
	}
		)
	);

	atticRoom->AddArea(
		Area(
			"Workbench",
			std::vector<Action>{
		Action(
			"Take the lantern",
			std::vector<std::shared_ptr<ActionEvent>>{
			std::make_shared<PickupItemEvent>(ItemKey::Lantern),
				std::make_shared<NarrativeAddEvent>("You pick up the old oil lantern. Its light is weak, but better than nothing.")
		}
		)
	}
		)
	);

	atticRoom->AddArea(
		Area(
			"Corridor door",
			std::vector<Action>{
		Action(
			"Return to the corridor",
			std::vector<std::shared_ptr<ActionEvent>>{
			std::make_shared<ChangeRoomEvent>(corridorRoomRawPtr),
				std::make_shared<NarrativeAddEvent>("You climb back down to the corridor.")
		}
		)
	}
		)
	);

#pragma endregion

#pragma region BASEMENT

	basementRoom->AddArea(
		Area(
			"Dark Corridor",
			std::vector<Action>{
		Action(
			"Search with the lantern",
			std::vector<std::shared_ptr<ActionEvent>>{
			std::make_shared<PickupItemEvent>(ItemKey::Fridge_Handle),
				std::make_shared<PickupItemEvent>(ItemKey::Record_03),
				std::make_shared<NarrativeAddEvent>("The lantern reveals old marks on the walls. You find a broken fridge handle and a heavy vinyl record. Record 3.")
		},
			{ ItemKey::Lantern }
		)
	}
		)
	);

	basementRoom->AddArea(
		Area(
			"Corridor door",
			std::vector<Action>{
		Action(
			"Return to the corridor",
			std::vector<std::shared_ptr<ActionEvent>>{
			std::make_shared<ChangeRoomEvent>(corridorRoomRawPtr),
				std::make_shared<NarrativeAddEvent>("You climb back up to the corridor.")
		}
		)
	}
		)
	);

#pragma endregion

#pragma region BALLROOM

	ballroomRoom->AddArea(
		Area(
			"Record Player",
			std::vector<Action>{
		Action(
			"Place the three records",
			std::vector<std::shared_ptr<ActionEvent>>{
			std::make_shared<ConsumeItemEvent>(ItemKey::Record_01),
				std::make_shared<ConsumeItemEvent>(ItemKey::Record_02),
				std::make_shared<ConsumeItemEvent>(ItemKey::Record_03),
				std::make_shared<NarrativeAddEvent>("You place the three records on the player. A soft crackling fills the hall. The music begins to play. The Keeper appears. He looks tired yet relieved. \"Finally,\" he whispers. \"You may leave.\" The locked doors open.")
		},
			{ ItemKey::Record_01, ItemKey::Record_02, ItemKey::Record_03 }
		)
	}
		)
	);

	ballroomRoom->AddArea(
		Area(
			"Corridor door",
			std::vector<Action>{
		Action(
			"Return to the corridor",
			std::vector<std::shared_ptr<ActionEvent>>{
			std::make_shared<ChangeRoomEvent>(corridorRoomRawPtr),
				std::make_shared<NarrativeAddEvent>("You leave the ballroom.")
		}
		)
	}
		)
	);

#pragma endregion

	rooms.push_back(std::move(suiteRoom));
	rooms.push_back(std::move(corridorRoom));
	rooms.push_back(std::move(bathroomRoom));
	rooms.push_back(std::move(kitchenRoom));
	rooms.push_back(std::move(libraryRoom));
	rooms.push_back(std::move(atticRoom));
	rooms.push_back(std::move(basementRoom));
	rooms.push_back(std::move(ballroomRoom));
}