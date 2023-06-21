#pragma once

#include <tuple>
#include <cstddef>
#include <cstdint>

#include "Config.h"
#include "Position.h"

namespace Game {
	class Map {
	public:
		Map(const Config& config);
		Map(size_t width, size_t height, unsigned int seed);
		size_t getWidth() const { return width_; };
		size_t getHeight() const { return height_; };
		Position nextPosition(const Position& currentPosition, Direction direction) const;
		Position oneUp(const Position& currentPosition) const;
		Position oneDown(const Position& currentPosition) const;
		Position oneRight(const Position& currentPosition) const;
		Position oneLeft(const Position& currentPosition) const;
		Position getRandomPosition() const;
		Position center() const { return Position(width_ / 2, height_ / 2); };
		Position topLeft() const { return Position(0, height_ - 1); };
		Position topRight() const { return Position(width_ - 1, height_ - 1); };
		Position bottomLeft() const { return Position(0, 0); };
		Position bottomRight() const { return Position(width_ - 1, 0); };
	private:
		size_t width_;
		size_t height_;
	};
	class TestMap : public Map {
	public:
		TestMap() : Map(SIZE_MAX, SIZE_MAX, 0) {};
	};
}