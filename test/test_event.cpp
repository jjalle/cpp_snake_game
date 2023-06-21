#define GTEST_LANG_CXX11 1
#include <gtest/gtest.h>

#include "Event.h"
using namespace Game;


TEST(EventTest, EventUp) {
    auto count = 0;
    auto f = [&count](const Event& event) { ASSERT_EQ(EventType::MOVE_UP, event.getType()); count++; };
    auto kernel = EventKernel();
    kernel.subscribe(EventType::MOVE_UP, f);
    kernel.trigger(MoveUpEvent());
    kernel.process();
    ASSERT_EQ(count, 1);
    kernel.trigger(MoveUpEvent());
    kernel.process();
    ASSERT_EQ(count, 2);
}

TEST(EventTest, EventDown) {
    auto count = 0;
    auto f = [&count](const Event& event) { ASSERT_EQ(EventType::MOVE_DOWN, event.getType()); count++; };
    auto kernel = EventKernel();
    kernel.subscribe(EventType::MOVE_DOWN, f);
    kernel.trigger(MoveDownEvent());
    kernel.process();
    ASSERT_EQ(count, 1);
    kernel.trigger(MoveDownEvent());
    kernel.process();
    ASSERT_EQ(count, 2);
}

TEST(EventTest, EventRight) {
    auto count = 0;
    auto f = [&count](const Event& event) { ASSERT_EQ(EventType::MOVE_RIGHT, event.getType()); count++; };
    auto kernel = EventKernel();
    kernel.subscribe(EventType::MOVE_RIGHT, f);
    kernel.trigger(MoveRightEvent());
    kernel.process();
    ASSERT_EQ(count, 1);
    kernel.trigger(MoveRightEvent());
    kernel.process();
    ASSERT_EQ(count, 2);
}

TEST(EventTest, EventLeft) {
    auto count = 0;
    auto f = [&count](const Event& event) { ASSERT_EQ(EventType::MOVE_LEFT, event.getType()); count++; };
    auto kernel = EventKernel();
    kernel.subscribe(EventType::MOVE_LEFT, f);
    kernel.trigger(MoveLeftEvent());
    kernel.process();
    ASSERT_EQ(count, 1);
    kernel.trigger(MoveLeftEvent());
    kernel.process();
    ASSERT_EQ(count, 2);
}

TEST(EventTest, EventEat) {
    auto count = 0;
    auto f = [&count](const Event& event) { ASSERT_EQ(EventType::EAT, event.getType()); count++; };
    auto kernel = EventKernel();
    kernel.subscribe(EventType::EAT, f);
    kernel.trigger(EatEvent());
    kernel.process();
    ASSERT_EQ(count, 1);
    kernel.trigger(EatEvent());
    kernel.process();
    ASSERT_EQ(count, 2);
}

TEST(EventTest, EventDeath) {
    auto count = 0;
    auto f = [&count](const Event& event) { ASSERT_EQ(EventType::DEATH, event.getType()); count++; };
    auto kernel = EventKernel();
    kernel.subscribe(EventType::DEATH, f);
    kernel.trigger(DeathEvent());
    kernel.process();
    ASSERT_EQ(count, 1);
    kernel.trigger(DeathEvent());
    kernel.process();
    ASSERT_EQ(count, 2);
}

TEST(EventTest, EventExit) {
    auto count = 0;
    auto f = [&count](const Event& event) { ASSERT_EQ(EventType::EXIT, event.getType()); count++; };
    auto kernel = EventKernel();
    kernel.subscribe(EventType::EXIT, f);
    kernel.trigger(ExitEvent());
    kernel.process();
    ASSERT_EQ(count, 1);
    kernel.trigger(ExitEvent());
    kernel.process();
    ASSERT_EQ(count, 2);
}