#include "Game.h"

int main(int argc, const char * argv[]) {
	auto game = Game::Game{};
	auto result = game.run();
	return result;
}
