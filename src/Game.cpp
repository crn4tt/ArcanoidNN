#include "Game.h"

Game::Game() : window(sf::VideoMode(800, 600), "Arkanoid"), paddle(400, 550), ball(400, 300), score(0), gameOver(false) {
    window.setFramerateLimit(60);
    if(!font.loadFromFile("PionerSans-Bold.ttf")) {
    }
    text.setFont(font);
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::Red);
    text.setPosition(300, 300);
    initialize();
}

void Game::run() {
    while (window.isOpen()) {
        processEvents();
        if (!gameOver) {
            update();
        }
        render();
    }
}

void Game::initialize() {
    blocks.clear();
    bonuses.clear();
    score = 0;
    gameOver = false;

    const int countBlocksX{11}, countBlocksY{4}, blockWidth{60}, blockHeight{20};

    for(int iX{0}; iX < countBlocksX; ++iX) {
        blocks.push_back(std::make_unique<SolidBlock>((iX + 1) * (blockWidth + 3) + 22, 2 * (blockHeight + 3), blockWidth, blockHeight));
        
        for(int iY{1}; iY < countBlocksY; ++iY) {
            blocks.push_back(std::make_unique<FragileBlock>((iX + 1) * (blockWidth + 3) + 22, (iY + 2) * (blockHeight + 3), blockWidth, blockHeight));
        }
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void Game::update() {
    paddle.update();
    ball.move();
    collisionHandler.handleCollisions(ball, paddle, blocks, bonuses, score, gameOver, window);
    for (auto& block : blocks) {
        block->update();
    }
}

void Game::render() {
    window.clear(sf::Color::Black);
    if(gameOver) {
        text.setString("Game Over! Score: " + std::to_string(score));
        window.draw(text);
    } else {
        for(const auto& block : blocks) {
            if(!block->destroyed)
                window.draw(block->shape);
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

void Game::restart() {
    initialize(); 
    ball.shape.setPosition(400, 300); 
    paddle.shape.setPosition(400, 550); 
    ball.velocity = {-4.0f, -4.0f}; 
}
