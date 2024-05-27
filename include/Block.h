#pragma once
#include <SFML/Graphics.hpp>

class Block {
public:
    sf::RectangleShape shape;
    int strength; 
    bool destroyed{false};
    sf::Texture texture;
    bool falling{false};
    sf::Vector2f fallVelocity{0.0f, 5.0f};

    Block(float x, float y, float width, float height, int str) : strength(str) {
        shape.setPosition(x, y);
        shape.setSize({width, height});
        shape.setOrigin(width / 2.f, height / 2.f);
    }

    bool setTexture(const std::string& texturePath) {
        if (!texture.loadFromFile(texturePath)) {
            return false; 
        }
        shape.setTexture(&texture);
        return true;
    }

    void update() {
        if(falling) {
            shape.move(fallVelocity);
        }
    }

    void hit() {
        if(--strength <= 0) {
            destroyed = true;
        }
    }
};

class SolidBlock : public Block {
public:
    SolidBlock(float x, float y, float width, float height) : Block(x, y, width, height, 3) {
        setTexture("rusty_metall.png");
    }
};

class FragileBlock : public Block {
public:
    FragileBlock(float x, float y, float width, float height) : Block(x, y, width, height, 1) {
        setTexture("wood.png");
    }
};