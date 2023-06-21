#pragma once
#include "Position.h"

namespace Game {
	class Config {
	public:
		Config() : seed_{ 0 }, mapHeight_{ 64 }, mapWidth_{ 64 }, snakeSize_{ 5 }, snakePosition_{ 31, 31 }, snakeDirection_{ Direction::LEFT }, foodPosition_{ 9, 9 } {};
		auto mapHeight() const { return mapHeight_; };
		auto mapWidth() const { return mapWidth_; };
		auto seed() const { return seed_; };
		auto snakeSize() const { return snakeSize_; };
		auto snakePosition() const { return snakePosition_; };
		auto snakeDirection() const { return snakeDirection_; };
		auto foodPosition() const { return foodPosition_; };
	private:
		unsigned int seed_;
		size_t mapHeight_;
		size_t mapWidth_;
		size_t snakeSize_;
		Position snakePosition_;
		Direction snakeDirection_;
		Position foodPosition_;
	};
}