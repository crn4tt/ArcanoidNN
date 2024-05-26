#include "Ball.h"

Ball::Ball(float mX, float mY) {
    shape.setPosition(mX, mY);
    shape.setRadius(ballRadius);
    shape.setFillColor(sf::Color::White);
    shape.setOrigin(ballRadius, ballRadius);
}

void Ball::move() {
    shape.move(velocity);
}

float Ball::x() const { return shape.getPosition().x; }
float Ball::y() const { return shape.getPosition().y; }
float Ball::left() const { return x() - shape.getRadius(); }
float Ball::right() const { return x() + shape.getRadius(); }
float Ball::top() const { return y() - shape.getRadius(); }
float Ball::bottom() const { return y() + shape.getRadius(); }