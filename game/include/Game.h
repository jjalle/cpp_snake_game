#pragma once

#include <string>
#include "Event.h"
#include "World.h"
#include "Config.h"
#include "Input.h"
#include "Graphics.h"

namespace Game {
	class Game
	{
	public:
		Game() : Game(Config()) {};
		Game(const Config& config);
		int run();
		bool isRunning() const { return running_; };
		void onExit(const Event& event) { quit(); };
		void quit() { running_ = false; kernel_.trigger(ExitEvent()); };
	private:
		EventKernel kernel_;
		World world_;
		bool running_;
		Graphics graphics_;
		Input input_;
	};
}