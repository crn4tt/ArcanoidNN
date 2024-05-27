#include "Bonus.h"

Bonus::Bonus(sf::Vector2f position, Type bonusType) : type(bonusType), active(true), velocity(0.0f, 2.0f) {
    shape.setPosition(position);
    shape.setSize({20.0f, 20.0f});
    shape.setFillColor(sf::Color::Green);
}

void Bonus::update() {
    if(active) {
        shape.move(velocity);
    }
}