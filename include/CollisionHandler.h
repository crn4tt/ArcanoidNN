#pragma once
#include "Ball.h"
#include "Paddle.h"
#include "Block.h"
#include "Bonus.h"
#include <vector>

class CollisionHandler {
public:
    void handleCollisions(Ball& ball, Paddle& paddle, std::vector<Block>& blocks, std::vector<Bonus>& bonuses, 
                          int& score, bool& gameOver, sf::RenderWindow& window);
};