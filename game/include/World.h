#pragma once

#include "Map.h"
#include "Snake.h"
#include "Food.h"
#include "Config.h"
#include "Event.h"


namespace Game {
	class World
	{
	public:
		World() : World(Config()) {};
		World(const Config& config);
		void update(EventKernel& kernel);
	private:
		Map map_;
		Snake snake_;
		Food food_;
	};
}