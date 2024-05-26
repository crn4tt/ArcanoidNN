#pragma once
#include <SFML/Graphics.hpp>

class Bonus {
public:
    sf::RectangleShape shape;
    sf::Vector2f velocity;
    bool active;
    enum class Type { SlowDown };
    Type type;

    Bonus(sf::Vector2f position, Type bonusType);
    void update();
};