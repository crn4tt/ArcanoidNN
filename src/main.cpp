// main.cpp
#include <SFML/Graphics.hpp>
#include "Paddle.h"
#include "Ball.h"
#include "Block.h"
#include "Bonus.h"
#include "CollisionHandler.h"
#include <vector>

int main() {
    sf::RenderWindow window{{800, 600}, "Arkanoid - Complete"};
    window.setFramerateLimit(60);

    Paddle paddle{400, 550};
    Ball ball{400, 300};
    CollisionHandler collisionHandler;

    const int countBlocksX{11}, countBlocksY{4}, blockWidth{60}, blockHeight{20};
    std::vector<Block> blocks;
    std::vector<Bonus> bonuses;

    for(int iX{0}; iX < countBlocksX; ++iX) {
        for(int iY{0}; iY < countBlocksY; ++iY) {
            blocks.emplace_back((iX + 1) * (blockWidth + 3) + 22, (iY + 2) * (blockHeight + 3), blockWidth, blockHeight);
        }
    }

    int score{0};
    bool gameOver = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if(!gameOver) {
            paddle.update();
            ball.move();
            collisionHandler.handleCollisions(ball, paddle, blocks, bonuses, score, gameOver, window);
        }

        window.clear(sf::Color::Black);
        if(gameOver) {
            sf::Text text;
            sf::Font font;
            if(font.loadFromFile("PionerSans-Bold.ttf")) {
                text.setFont(font);
                text.setString("Game Over! Score: " + std::to_string(score));
                text.setCharacterSize(30);
                text.setFillColor(sf::Color::Red);
                text.setPosition(300, 300); 
                window.draw(text);
            }
        } else {
            for(auto& block : blocks) {
                if(!block.destroyed)
                    window.draw(block.shape);
            }
            for(auto& bonus : bonuses) {
                if(bonus.active)
                    window.draw(bonus.shape);
            }
            window.draw(paddle.shape);
            window.draw(ball.shape);
        }
        window.display();
    }

    return 0;
}
