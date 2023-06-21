#define GTEST_LANG_CXX11 1
#include <gtest/gtest.h>

#include "Snake.h"
#include "Event.h"
#include "Map.h"
#include "Position.h"

using namespace Game;

const auto SNAKE_X = size_t{ 5 };
const auto SNAKE_Y = size_t{ 5 };
const auto SNAKE_POSITION = Position(SNAKE_X, SNAKE_Y);
const auto SNAKE_DIRECTION = Direction::UP;
const auto SNAKE_SIZE = size_t{ 3 };

TEST(SnakeTest, SnakeConstruction) {
    auto snake = Snake(SNAKE_SIZE, SNAKE_POSITION, SNAKE_DIRECTION);
    ASSERT_EQ(snake.head(), SNAKE_POSITION);
    ASSERT_EQ(snake.size(), SNAKE_SIZE);
    ASSERT_EQ(snake.direction(), SNAKE_DIRECTION);
}

TEST(SnakeTest, SnakeMoveUp) {
    auto kernel = EventKernel();
    auto map = TestMap();
    auto snake = Snake(SNAKE_SIZE, SNAKE_POSITION, Direction::UP);
    snake.update(kernel, map, false);
    ASSERT_EQ(snake.head(), Position(SNAKE_X, SNAKE_Y + 1));
    ASSERT_EQ(snake.size(), SNAKE_SIZE);
    ASSERT_EQ(snake.direction(), Direction::UP);
    snake.update(kernel, map, false);
    ASSERT_EQ(snake.head(), Position(SNAKE_X, SNAKE_Y + 2));
    ASSERT_EQ(snake.size(), SNAKE_SIZE);
    ASSERT_EQ(snake.direction(), Direction::UP);
}

TEST(SnakeTest, SnakeMoveDown) {
    auto kernel = EventKernel();
    auto map = TestMap();
    auto snake = Snake(SNAKE_SIZE, SNAKE_POSITION, Direction::DOWN);
    snake.update(kernel, map, false);
    ASSERT_EQ(snake.head(), Position(SNAKE_X, SNAKE_Y - 1));
    ASSERT_EQ(snake.size(), SNAKE_SIZE);
    ASSERT_EQ(snake.direction(), Direction::DOWN);
    snake.update(kernel, map, false);
    ASSERT_EQ(snake.head(), Position(SNAKE_X, SNAKE_Y - 2));
    ASSERT_EQ(snake.size(), SNAKE_SIZE);
    ASSERT_EQ(snake.direction(), Direction::DOWN);
}

TEST(SnakeTest, SnakeMoveRight) {
    auto kernel = EventKernel();
    auto map = TestMap();
    auto snake = Snake(SNAKE_SIZE, SNAKE_POSITION, Direction::RIGHT);
    snake.update(kernel, map, false);
    ASSERT_EQ(snake.head(), Position(SNAKE_X + 1, SNAKE_Y));
    ASSERT_EQ(snake.size(), SNAKE_SIZE);
    ASSERT_EQ(snake.direction(), Direction::RIGHT);
    snake.update(kernel, map, false);
    ASSERT_EQ(snake.head(), Position(SNAKE_X + 2, SNAKE_Y));
    ASSERT_EQ(snake.size(), SNAKE_SIZE);
    ASSERT_EQ(snake.direction(), Direction::RIGHT);
}

TEST(SnakeTest, SnakeMoveLeft) {
    auto kernel = EventKernel();
    auto map = TestMap();
    auto snake = Snake(SNAKE_SIZE, SNAKE_POSITION, Direction::LEFT);
    snake.update(kernel, map, false);
    ASSERT_EQ(snake.head(), Position(SNAKE_X - 1, SNAKE_Y));
    ASSERT_EQ(snake.size(), SNAKE_SIZE);
    ASSERT_EQ(snake.direction(), Direction::LEFT);
    snake.update(kernel, map, false);
    ASSERT_EQ(snake.head(), Position(SNAKE_X - 2, SNAKE_Y));
    ASSERT_EQ(snake.size(), SNAKE_SIZE);
    ASSERT_EQ(snake.direction(), Direction::LEFT);
}
