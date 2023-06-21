#pragma once

#include "Position.h"
#include "Config.h"

namespace Game {
    class Food {
    public:
        Food(const Config& config) : Food(config.foodPosition()) {};
        Food(Position init) : position_(init) {};
        bool isEaten(const Position& position) const { return position == position_; };
        void updatePosition(Position position) { position_ = position; };
    private:
        Position position_;
    };
}