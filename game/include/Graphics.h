#pragma once

#include <string>
#include "Config.h"
#include "SDL.h"
#undef main

namespace Game {
	class Graphics
	{
	public:
		Graphics(const Config& config) : Graphics() {};
		Graphics();
		~Graphics();
	private:
		SDL_Window* window_;
	};
}