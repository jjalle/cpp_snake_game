#define GTEST_LANG_CXX11 1
#include <gtest/gtest.h>

#include "Map.h"
using namespace Game;

const auto MAP_HEIGHT = 10;
const auto MAP_WIDTH = 20;
TEST(MapTest, MapConstruction) {
    auto map = Map(MAP_WIDTH, MAP_HEIGHT, 0);
    ASSERT_EQ(map.getHeight(), MAP_HEIGHT);
    ASSERT_EQ(map.getWidth(), MAP_WIDTH);
    ASSERT_EQ(map.center(), Position(MAP_WIDTH / 2, MAP_HEIGHT / 2));
    ASSERT_EQ(map.topLeft(), Position(0, MAP_HEIGHT - 1));
    ASSERT_EQ(map.topRight(), Position(MAP_WIDTH - 1, MAP_HEIGHT - 1));
    ASSERT_EQ(map.bottomLeft(), Position(0, 0));
    ASSERT_EQ(map.bottomRight(), Position(MAP_WIDTH - 1, 0));
}

TEST(MapTest, MapRandom) {
    auto map = Map(MAP_WIDTH, MAP_HEIGHT, 0);
    auto posA = map.getRandomPosition();
    auto posB = map.getRandomPosition();
    ASSERT_NE(posA, posB);
}

TEST(MapTest, MapUp) {
    auto map = Map(MAP_WIDTH, MAP_HEIGHT, 0);
    auto startingPosition = Position(0, 0);
    auto wrappingPosition = Position(MAP_WIDTH - 1, MAP_HEIGHT - 1);
    {
        auto nextPosition = map.oneUp(startingPosition);
        auto nextWrappingPosition = map.oneUp(wrappingPosition);
        ASSERT_EQ(nextPosition, Position(0, 1));
        ASSERT_EQ(nextWrappingPosition, Position(MAP_WIDTH - 1, 0));
    }
    {
        auto nextPosition = map.nextPosition(startingPosition, Direction::UP);
        auto nextWrappingPosition = map.nextPosition(wrappingPosition, Direction::UP);
        ASSERT_EQ(nextPosition, Position(0, 1));
        ASSERT_EQ(nextWrappingPosition, Position(MAP_WIDTH - 1, 0));
    }
}

TEST(MapTest, MapDown) {
    auto map = Map(MAP_WIDTH, MAP_HEIGHT, 0);
    auto startingPosition = Position(MAP_WIDTH - 1, MAP_HEIGHT - 1);
    auto wrappingPosition = Position(0, 0);
    {
        auto nextPosition = map.oneDown(startingPosition);
        auto nextWrappingPosition = map.oneDown(wrappingPosition);
        ASSERT_EQ(nextPosition, Position(MAP_WIDTH - 1, MAP_HEIGHT - 2));
        ASSERT_EQ(nextWrappingPosition, Position(0, MAP_HEIGHT - 1));
    }
    {
        auto nextPosition = map.nextPosition(startingPosition, Direction::DOWN);
        auto nextWrappingPosition = map.nextPosition(wrappingPosition, Direction::DOWN);
        ASSERT_EQ(nextPosition, Position(MAP_WIDTH - 1, MAP_HEIGHT - 2));
        ASSERT_EQ(nextWrappingPosition, Position(0, MAP_HEIGHT - 1));
    }
}

TEST(MapTest, MapRight) {
    auto map = Map(MAP_WIDTH, MAP_HEIGHT, 0);
    auto startingPosition = Position(0, 0);
    auto wrappingPosition = Position(MAP_WIDTH - 1, MAP_HEIGHT - 1);
    {
        auto nextPosition = map.oneRight(startingPosition);
        auto nextWrappingPosition = map.oneRight(wrappingPosition);
        ASSERT_EQ(nextPosition, Position(1, 0));
        ASSERT_EQ(nextWrappingPosition, Position(0, MAP_HEIGHT - 1));
    }
    {
        auto nextPosition = map.nextPosition(startingPosition, Direction::RIGHT);
        auto nextWrappingPosition = map.nextPosition(wrappingPosition, Direction::RIGHT);
        ASSERT_EQ(nextPosition, Position(1, 0));
        ASSERT_EQ(nextWrappingPosition, Position(0, MAP_HEIGHT - 1));
    }
}

TEST(MapTest, MapLeft) {
    auto map = Map(MAP_WIDTH, MAP_HEIGHT, 0);
    auto startingPosition = Position(MAP_WIDTH - 1, MAP_HEIGHT - 1);
    auto wrappingPosition = Position(0, 0);
    {
        auto nextPosition = map.oneLeft(startingPosition);
        auto nextWrappingPosition = map.oneLeft(wrappingPosition);
        ASSERT_EQ(nextPosition, Position(MAP_WIDTH - 2, MAP_HEIGHT - 1));
        ASSERT_EQ(nextWrappingPosition, Position(MAP_WIDTH - 1, 0));
    }
    {
        auto nextPosition = map.nextPosition(startingPosition, Direction::LEFT);
        auto nextWrappingPosition = map.nextPosition(wrappingPosition, Direction::LEFT);
        ASSERT_EQ(nextPosition, Position(MAP_WIDTH - 2, MAP_HEIGHT - 1));
        ASSERT_EQ(nextWrappingPosition, Position(MAP_WIDTH - 1, 0));
    }
}
