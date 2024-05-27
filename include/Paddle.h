#pragma once
#include <SFML/Graphics.hpp>


class Paddle {
public:
    sf::RectangleShape shape;
    const float paddleWidth{180.0f};
    const float paddleHeight{20.0f};
    const float paddleVelocity{8.0f};
    sf::Vector2f velocity;

    Paddle(float x, float y);
    void update();
    void setVelocity(float vel);

    float x() const;
    float y() const;
    float left() const;
    float right() const;
    float top() const;
    float bottom() const;
};