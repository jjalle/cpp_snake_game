#pragma once

#include <string>
#include "Event.h"
#include "World.h"
#include "Config.h"
#include "SDL.h"

namespace Game {
	class Game
	{
	public:
		Game() : Game(Config()) {};
		Game(const Config& config);
		~Game();
		int run();
		bool isRunning() const { return running_; };
		void exit() { running_ = false; kernel_.trigger(ExitEvent()); };
	private:
		EventKernel kernel_;
		World world_;
		bool running_;
		SDL_Window* window_;
	};
}