#include "Paddle.h"

Paddle::Paddle(float x, float y) {
    shape.setPosition(x, y);
    shape.setSize({paddleWidth, paddleHeight});
    shape.setFillColor(sf::Color::Red);
    shape.setOrigin(paddleWidth / 2.f, paddleHeight / 2.f);
}

void Paddle::update() {
    shape.move(velocity);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && left() > 0) {
        velocity.x = -paddleVelocity;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && right() < 800) {
        velocity.x = paddleVelocity;
    } else {
        velocity.x = 0;
    }
}

float Paddle::x() const { return shape.getPosition().x; }
float Paddle::y() const { return shape.getPosition().y; }
float Paddle::left() const { return x() - shape.getSize().x / 2.f; }
float Paddle::right() const { return x() + shape.getSize().x / 2.f; }
float Paddle::top() const { return y() - shape.getSize().y / 2.f; }
float Paddle::bottom() const { return y() + shape.getSize().y / 2.f; }