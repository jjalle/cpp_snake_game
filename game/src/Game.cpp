#include <sstream>
#include <functional>

#include "Game.h"

namespace Game {

Game::Game(const Config& config) : running_(true), kernel_(), world_(config), graphics_(config), input_(config) {
	EventCallback exitCallback = std::bind(&Game::onExit, this, std::placeholders::_1);
	kernel_.subscribe(EventType::EXIT, exitCallback);
}

int Game::run() {
	while (running_) {
		input_.pollEvents(kernel_);
		kernel_.process();
		world_.update(kernel_);
		kernel_.process();
	}
	return 0;
}

} // namespace Game
