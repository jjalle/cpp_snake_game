#pragma once

#include <tuple>
#include <cstddef>

namespace Game {
	enum Direction {
		UP,
		DOWN,
		LEFT,
		RIGHT
	};
	class Position {
	public:
		Position(size_t x, size_t y) : x_(x), y_(y) {};
		bool operator==(const Position& other) const
		{
			return std::tie(x_, y_) == std::tie(other.x_, other.y_);
		}
		bool operator!=(const Position& other) const
		{
			return std::tie(x_, y_) != std::tie(other.x_, other.y_);
		}
		size_t x_;
		size_t y_;
	};
}