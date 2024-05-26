#pragma once
#include <SFML/Graphics.hpp>

class Block {
public:
    sf::RectangleShape shape;
    bool destroyed{false};

    Block(float x, float y, float width, float height) {
        shape.setPosition(x, y);
        shape.setSize({width, height});
        shape.setFillColor(sf::Color::Yellow);
        shape.setOrigin(width / 2.f, height / 2.f);
    }
};