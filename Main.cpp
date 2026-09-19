#include "TextAdventureGame.hpp"

int main() {
	TextAdventureGame* game = new TextAdventureGame();
	game->Run();
	delete game;
}
