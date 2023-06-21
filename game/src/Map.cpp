#include "Map.h"
#include <random>

namespace Game {

Map::Map(const Config& config) : Map(config.mapWidth(), config.mapHeight(), config.seed()) {
}

Map::Map(size_t width, size_t height, unsigned int seed) : width_(width), height_(height) {
	srand(seed);
}

Position Map::nextPosition(const Position& currentPosition, Direction direction) const
{
	switch (direction) {
	case Direction::UP: return oneUp(currentPosition);
	case Direction::DOWN: return oneDown(currentPosition);
	case Direction::LEFT: return oneLeft(currentPosition);
	case Direction::RIGHT: return oneRight(currentPosition);
	};
}

Position Map::oneUp(const Position& currentPosition) const {
	auto x = currentPosition.x_;
	auto y = (currentPosition.y_ + 1) % height_;
	return  Position(x, y);
}

Position Map::oneDown(const Position& currentPosition) const {
	auto x = currentPosition.x_;
	auto y = (currentPosition.y_ == 0)? height_ -1 : currentPosition.y_ - 1;
	return  Position(x, y);
}

Position Map::oneRight(const Position& currentPosition) const {
	auto x = (currentPosition.x_ + 1) % width_;
	auto y = currentPosition.y_;
	return  Position(x, y);
}

Position Map::oneLeft(const Position& currentPosition) const {
	auto x = (currentPosition.x_ == 0) ? width_ - 1 : currentPosition.x_ - 1;
	auto y = currentPosition.y_;
	return  Position(x, y);
}

Position Map::getRandomPosition() const {
	auto x = rand() % width_;
	auto y = rand() % height_;
	return Position(x, y);
}

} // namespace Game