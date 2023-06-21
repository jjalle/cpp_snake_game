#pragma once

#include <list>
#include "Map.h"
#include "Food.h"
#include "Event.h"
#include "Config.h"

namespace Game {
	class Snake {
	public:
		Snake(const Config& config) : Snake(config.snakeSize(), config.snakePosition(), config.snakeDirection()) {};
		Snake(size_t size, Position init, Direction direction);
		Position head() const { return body_.front(); };
		size_t size() const { return body_.size(); };
		Direction direction() const { return direction_; };
		void subscribeEvents(EventKernel& event) const {};
		void changeDirection(Direction direction);
		void update(EventKernel& event, const Map& map, bool eatenFood);
		bool collides(const Position& position);
	private:
		std::list<Position> body_;
		Direction direction_;
	};
}