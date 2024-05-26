#pragma once
#include <SFML/Graphics.hpp>

class Ball {
public:
    sf::CircleShape shape;
    const float ballRadius{10.0f};
    sf::Vector2f velocity{-4.0f, -4.0f};

    Ball(float mX, float mY);
    void move();

    float x() const;
    float y() const;
    float left() const;
    float right() const;
    float top() const;
    float bottom() const;
};