#include <sstream>

#include "Game.h"
#include "SDL.h"

namespace Game {

Game::Game(const Config& config) : running_(true), kernel_(), world_(config), window_(nullptr) {
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		auto ss = std::stringstream{ "SDL could not be initialized:" } << SDL_GetError();
		throw new std::runtime_error(ss.str());
	}
	window_ = SDL_CreateWindow(
		"Snake game",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		640,
		480,
		0
	);
	if (window_ == nullptr)
	{
		auto ss = std::stringstream{ "SDL could not create window:" } << SDL_GetError();
		throw new std::runtime_error(ss.str());
	}
}

Game::~Game() {
	SDL_DestroyWindow(window_);
	SDL_Quit();
}

int Game::run() {
	while (running_) {
		world_.update(kernel_);
	}
	return 0;
}

} // namespace Game
