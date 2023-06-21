#include <sstream>

#include "Graphics.h"

namespace Game {

Graphics::Graphics() : window_(nullptr) {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		auto ss = std::stringstream{ "SDL could not be initialized: " } << SDL_GetError();
		throw new std::runtime_error(ss.str());
	}
	window_ = SDL_CreateWindow(
		"Snake game",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		640,
		480,
		SDL_WINDOW_SHOWN
	);
	if (window_ == nullptr) {
		auto ss = std::stringstream{ "SDL could not create window: " } << SDL_GetError();
		throw new std::runtime_error(ss.str());
	}
}

Graphics::~Graphics() {
	SDL_DestroyWindow(window_);
	window_ = nullptr;
	SDL_Quit();
}

} // namespace Game
