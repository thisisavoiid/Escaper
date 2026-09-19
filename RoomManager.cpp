#include "RoomManager.hpp"
#include "ChangeRoomEvent.hpp"
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
	auto hospital = std::make_unique<Room>("Hospital Ward", "Smells like antiseptic, copper, and regret.", std::vector<Area>{});
	auto basement = std::make_unique<Room>("Pitch Black Basement", "You hear ominous skittering in the shadows.", std::vector<Area>{});
	auto sewer = std::make_unique<Room>("Sewer Line", "It's damp, freezing, and smells terrible.", std::vector<Area>{});
	auto shadowRealm = std::make_unique<Room>("The Shadow Realm", "A void of pure static and broken physics.", std::vector<Area>{});
	auto rustyPipe = std::make_unique<Room>("Claustrophobic Rusty Pipe", "A tight, slime-coated iron tube echoing with wet whispers.", std::vector<Area>{});
	auto attic = std::make_unique<Room>("Clockwork Attic", "Massive brass gears grind constantly around you.", std::vector<Area>{});
	auto mirrorMaze = std::make_unique<Room>("Infinite Mirror Maze", "Reflections stretch forever. None of them copy your movement accurately.", std::vector<Area>{});
	auto forgottenWell = std::make_unique<Room>("Bottom of the Forgotten Well", "Damp stonework reaches up into absolute darkness.", std::vector<Area>{});

	Room* livingRoomRawPtr = livingRoom.get();
	Room* kitchenRawPtr = kitchen.get();
	Room* hospitalRawPtr = hospital.get();
	Room* basementRawPtr = basement.get();
	Room* sewerRawPtr = sewer.get();
	Room* shadowRealmRawPtr = shadowRealm.get();
	Room* rustyPipeRawPtr = rustyPipe.get();
	Room* atticRawPtr = attic.get();
	Room* mirrorMazeRawPtr = mirrorMaze.get();
	Room* forgottenWellRawPtr = forgottenWell.get();
	
	// LIVING ROOM
	livingRoom->AddArea(Area(
		"Kitchen Door",
		std::vector<Action>{
		Action("Enter kitchen", std::make_shared<ChangeRoomEvent>(kitchenRawPtr))
	}
	));

	livingRoom->AddArea(Area(
		"Overpriced IKEA Bookshelf",
		std::vector<Action>{
		Action("Eat top shelf (Oak finish)", std::make_shared<ChangeRoomEvent>(hospitalRawPtr)),
			Action("Eat bottom shelf (Termite flavored)", std::make_shared<ChangeRoomEvent>(hospitalRawPtr)),
			Action("Lick the varnish", std::make_shared<ChangeRoomEvent>(shadowRealmRawPtr)),
			Action("Read 'How to Stop Eating Furniture'", std::make_shared<ChangeRoomEvent>(livingRoomRawPtr))
	}
	));

	livingRoom->AddArea(Area(
		"Flickering CRT Television",
		std::vector<Action>{
		Action("Falcon Punch the screen", std::make_shared<ChangeRoomEvent>(hospitalRawPtr)),
			Action("Crawl inside (Poltergeist style)", std::make_shared<ChangeRoomEvent>(shadowRealmRawPtr)),
			Action("Slap the side (Percussive maintenance)", std::make_shared<ChangeRoomEvent>(livingRoomRawPtr)),
			Action("Lick static electricity", std::make_shared<ChangeRoomEvent>(livingRoomRawPtr))
	}
	));

	livingRoom->AddArea(Area(
		"Wrinkled Persian Rug",
		std::vector<Action>{
		Action("Lift rug and jump into trapdoor", std::make_shared<ChangeRoomEvent>(basementRawPtr)),
			Action("Attempt to fly like Aladdin", std::make_shared<ChangeRoomEvent>(hospitalRawPtr)),
			Action("Sweep bad decisions under it", std::make_shared<ChangeRoomEvent>(livingRoomRawPtr))
	}
	));

	livingRoom->AddArea(Area(
		"Mysterious Brass Keyhole in Wall",
		std::vector<Action>{
		Action("Peep through keyhole", std::make_shared<ChangeRoomEvent>(mirrorMazeRawPtr)),
			Action("Force open secret panel", std::make_shared<ChangeRoomEvent>(atticRawPtr))
	}
	));

	// KITCHEN
	kitchen->AddArea(Area(
		"Living Room Door",
		std::vector<Action>{
		Action("Enter living room", std::make_shared<ChangeRoomEvent>(livingRoomRawPtr))
	}
	));

	kitchen->AddArea(Area(
		"Humming Refrigerator",
		std::vector<Action>{
		Action("Climb into vegetable crisper", std::make_shared<ChangeRoomEvent>(shadowRealmRawPtr)),
			Action("Eat 6-month-old mystery casserole", std::make_shared<ChangeRoomEvent>(hospitalRawPtr)),
			Action("Stare blankly hoping new food spawns", std::make_shared<ChangeRoomEvent>(kitchenRawPtr))
	}
	));

	kitchen->AddArea(Area(
		"Overflowing Garbage Can",
		std::vector<Action>{
		Action("Rummage like a frantic raccoon", std::make_shared<ChangeRoomEvent>(kitchenRawPtr)),
			Action("Dive headfirst into the trash choke", std::make_shared<ChangeRoomEvent>(sewerRawPtr))
	}
	));

	kitchen->AddArea(Area(
		"Choked Sink Drain",
		std::vector<Action>{
		Action("Pour boiling tea down drain", std::make_shared<ChangeRoomEvent>(kitchenRawPtr)),
			Action("Reach hand deep into garbage disposal", std::make_shared<ChangeRoomEvent>(rustyPipeRawPtr))
	}
	));

	// HOSPITAL
	hospital->AddArea(Area(
		"Emergency Room Bed",
		std::vector<Action>{
		Action("Discharge yourself and walk back to living room", std::make_shared<ChangeRoomEvent>(livingRoomRawPtr)),
			Action("Refuse treatment and stumble to kitchen", std::make_shared<ChangeRoomEvent>(kitchenRawPtr))
	}
	));

	hospital->AddArea(Area(
		"Humming MRI Machine",
		std::vector<Action>{
		Action("Crawl into scanner tube", std::make_shared<ChangeRoomEvent>(shadowRealmRawPtr)),
			Action("Press glowing emergency override button", std::make_shared<ChangeRoomEvent>(atticRawPtr))
	}
	));

	// BASEMENT
	basement->AddArea(Area(
		"Creaky Stairs",
		std::vector<Action>{
		Action("Run back upstairs to the living room", std::make_shared<ChangeRoomEvent>(livingRoomRawPtr)),
			Action("Embrace the darkness", std::make_shared<ChangeRoomEvent>(shadowRealmRawPtr))
	}
	));

	basement->AddArea(Area(
		"Breached Concrete Foundation",
		std::vector<Action>{
		Action("Squeeze through damp breach", std::make_shared<ChangeRoomEvent>(forgottenWellRawPtr)),
			Action("Whisper into the darkness", std::make_shared<ChangeRoomEvent>(basementRawPtr))
	}
	));

	// SEWER LINE
	sewer->AddArea(Area(
		"Drainage Pipe Junction",
		std::vector<Action>{
		Action("Crawl back up trash chute to kitchen", std::make_shared<ChangeRoomEvent>(kitchenRawPtr)),
			Action("Swim downstream into dark abyss", std::make_shared<ChangeRoomEvent>(shadowRealmRawPtr))
	}
	));

	sewer->AddArea(Area(
		"Corroded Flange",
		std::vector<Action>{
		Action("Wriggle through claustrophobic rust tube", std::make_shared<ChangeRoomEvent>(rustyPipeRawPtr)),
			Action("Dive into stagnant submerged trench", std::make_shared<ChangeRoomEvent>(forgottenWellRawPtr))
	}
	));

	// RUSTY PIPE
	rustyPipe->AddArea(Area(
		"Slimy Sludge Blockage",
		std::vector<Action>{
		Action("Dig through sludge barrier with hands", std::make_shared<ChangeRoomEvent>(sewerRawPtr)),
			Action("Inhale strange sulfur fumes", std::make_shared<ChangeRoomEvent>(hospitalRawPtr))
	}
	));

	rustyPipe->AddArea(Area(
		"Vertical Rust Chimney",
		std::vector<Action>{
		Action("Wriggle violently upwards", std::make_shared<ChangeRoomEvent>(atticRawPtr)),
			Action("Peep through rusted seam", std::make_shared<ChangeRoomEvent>(kitchenRawPtr))
	}
	));

	// CLOCKWORK ATTIC
	attic->AddArea(Area(
		"Giant Brass Pendulum",
		std::vector<Action>{
		Action("Grab pendulum and ride sweep arc", std::make_shared<ChangeRoomEvent>(livingRoomRawPtr)),
			Action("Lick giant ticking escapement wheel", std::make_shared<ChangeRoomEvent>(shadowRealmRawPtr))
	}
	));

	attic->AddArea(Area(
		"Rotting Floorboard Gap",
		std::vector<Action>{
		Action("Drop into dark gap below", std::make_shared<ChangeRoomEvent>(basementRawPtr)),
			Action("Wind life-sized mechanical automaton", std::make_shared<ChangeRoomEvent>(mirrorMazeRawPtr))
	}
	));

	// INFINITE MIRROR MAZE
	mirrorMaze->AddArea(Area(
		"Fractured Silver Mirror",
		std::vector<Action>{
		Action("Step into broken glass reflection", std::make_shared<ChangeRoomEvent>(hospitalRawPtr)),
			Action("High-five your reflection", std::make_shared<ChangeRoomEvent>(shadowRealmRawPtr))
	}
	));

	mirrorMaze->AddArea(Area(
		"Endless Glass Hallway",
		std::vector<Action>{
		Action("Walk backwards with eyes closed", std::make_shared<ChangeRoomEvent>(livingRoomRawPtr)),
			Action("Follow distant dripping sound", std::make_shared<ChangeRoomEvent>(forgottenWellRawPtr))
	}
	));

	// BOTTOM OF THE FORGOTTEN WELL
	forgottenWell->AddArea(Area(
		"Slippery Mossy Shaft",
		std::vector<Action>{
		Action("Climb rotting iron rungs upward", std::make_shared<ChangeRoomEvent>(atticRawPtr)),
			Action("Submerge head in black wellwater", std::make_shared<ChangeRoomEvent>(mirrorMazeRawPtr))
	}
	));

	forgottenWell->AddArea(Area(
		"Submerged Drain Hole",
		std::vector<Action>{
		Action("Get sucked into floor intake valve", std::make_shared<ChangeRoomEvent>(sewerRawPtr)),
			Action("Chisel stone brick away", std::make_shared<ChangeRoomEvent>(basementRawPtr))
	}
	));

	// THE SHADOW REALM
	shadowRealm->AddArea(Area(
		"Glitch Portal",
		std::vector<Action>{
		Action("Respawn in Living Room", std::make_shared<ChangeRoomEvent>(livingRoomRawPtr)),
			Action("Step into static beam", std::make_shared<ChangeRoomEvent>(hospitalRawPtr)),
			Action("Touch corrupt pixel cluster", std::make_shared<ChangeRoomEvent>(rustyPipeRawPtr))
	}
	));

	rooms.push_back(std::move(livingRoom));
	rooms.push_back(std::move(kitchen));
	rooms.push_back(std::move(hospital));
	rooms.push_back(std::move(basement));
	rooms.push_back(std::move(sewer));
	rooms.push_back(std::move(rustyPipe));
	rooms.push_back(std::move(attic));
	rooms.push_back(std::move(mirrorMaze));
	rooms.push_back(std::move(forgottenWell));
	rooms.push_back(std::move(shadowRealm));
}