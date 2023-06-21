#include <cassert>
#include "Snake.h"
namespace Game {

Snake::Snake(size_t size, Position init, Direction direction): direction_(direction) {
	assert(size > 0);
	auto position = init;
	for (size_t i = 0; i < size; i++)
	{
		body_.push_back(position);
	}
}

void Snake::changeDirection(Direction moveDirection)
{
	switch (moveDirection) {
	case Direction::UP:
	{
		if (direction_ != Direction::DOWN)
		{
			direction_ = Direction::UP;
		}
		break;
	}
	case Direction::DOWN:
	{
		if (direction_ != Direction::UP)
		{
			direction_ = Direction::DOWN;
		}
		break;
	}
	case Direction::LEFT:
	{
		if (direction_ != Direction::RIGHT)
		{
			direction_ = Direction::LEFT;
		}
		break;
	}
	case Direction::RIGHT:
	{
		if (direction_ != Direction::LEFT)
		{
			direction_ = Direction::RIGHT;
		}
		break;
	}
	}
}

void Snake::update(EventKernel& kernel, const Map& map, bool eatenFood)
{
	// Add new position to the front of the body list
	const auto head = body_.front();
	auto newPosition = map.nextPosition(head, direction_);
	body_.push_front(newPosition);
	if (eatenFood == false) {
		// Remove last element from body
		body_.pop_back();
	}
}

bool Snake::collides(const Position& position)
{
	for (const auto& snakePosition : body_)
	{
		if (snakePosition == position)
		{
			return true;
		}
	}
	return false;
}

} // namespace Game