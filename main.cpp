#include <SFML/Graphics.hpp>
#include <iostream>
#include "game/game.hpp"

int main() {
	Game game;
	game.run();
	std::cout << "Hello SFML!!" << std::endl;
}
