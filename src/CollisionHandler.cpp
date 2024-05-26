#include "CollisionHandler.h"

void CollisionHandler::handleCollisions(Ball& ball, Paddle& paddle, std::vector<Block>& blocks, std::vector<Bonus>& bonuses, int& score, bool& gameOver, sf::RenderWindow& window) {
    if (ball.left() < 0 || ball.right() > window.getSize().x) {
        ball.velocity.x = -ball.velocity.x;
    }
    if (ball.top() < 0) {
        ball.velocity.y = -ball.velocity.y;
    }
    if (ball.bottom() > window.getSize().y) {
        gameOver = true;
    }

    if(ball.shape.getGlobalBounds().intersects(paddle.shape.getGlobalBounds())) {
        ball.velocity.y = -ball.velocity.y;
    }

    for(auto& block : blocks) {
        if(!block.destroyed && ball.shape.getGlobalBounds().intersects(block.shape.getGlobalBounds())) {
            block.destroyed = true;
            ball.velocity.y = -ball.velocity.y;
            score += 10;

            ball.velocity.x *= 1.02f;
            ball.velocity.y *= 1.02f;

            if(rand() % 6 == 0) {
                bonuses.push_back(Bonus(block.shape.getPosition(), Bonus::Type::SlowDown));
            }

            break;
        }
    }

    auto it = bonuses.begin();
    while(it != bonuses.end()) {
        it->update();
        if(it->shape.getGlobalBounds().intersects(paddle.shape.getGlobalBounds())) {
            switch(it->type) {
                case Bonus::Type::SlowDown:
                    ball.velocity.x *= 1.05f;
                    ball.velocity.y *= 1.05f;
                    break;
            }
            it = bonuses.erase(it);
        } else {
            ++it;
        }
    }
}