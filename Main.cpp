#include "TextAdventureGame.hpp"
#include <memory>

int main() {
	TextAdventureGame* game = new TextAdventureGame();
	game->Run();
	delete game;
}
