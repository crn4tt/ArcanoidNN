#pragma once
#include <SFML/Graphics.hpp>
#include "Paddle.h"
#include "Ball.h"
#include "Block.h"
#include "Bonus.h"
#include "CollisionHandler.h"
#include <vector>
#include <memory>

class Game {
public:
    Game();
    void run();

private:
    sf::RenderWindow window;
    Paddle paddle{400, 550};
    Ball ball{400, 300};
    std::vector<std::unique_ptr<Block>> blocks;
    std::vector<Bonus> bonuses;
    CollisionHandler collisionHandler;
    sf::Font font;
    sf::Text text;
    int score;
    bool gameOver;

    void initialize();
    void processEvents();
    void update();
    void render();
    void restart();
};
