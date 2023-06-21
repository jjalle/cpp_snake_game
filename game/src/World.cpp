#include "World.h"

namespace Game {

World::World(const Config& config) : map_(config), snake_(config), food_(config) {
}

void World::update(EventKernel& kernel)
{
	auto snakeHead = snake_.head();
	auto eatenFood = false;
	if (food_.isEaten(snakeHead))
	{
		// Find new unoccupied position for food
		auto position = map_.getRandomPosition();
		while (snake_.collides(position)) {
			position = map_.getRandomPosition();
		}
		food_.updatePosition(position);
		// Trigger eat event
		kernel.trigger(EatEvent());
		eatenFood = true;
	}
	snake_.update(kernel, map_, eatenFood);
}

} // namespace Game
