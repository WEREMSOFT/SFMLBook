//
// Created by Pablo Weremczuk on 2019-04-08.
//

#include "game.hpp"

Game::Game(): mWindow(sf::VideoMode(640, 480), "SFML Apllication"), world(mWindow) {
        std::cout << "creating game..." << std::endl;
        isMovingDown = isMovingUp = isMovingLeft = isMovingRight = false;
}

Game::~Game() {
    std::cout << "destroying game..." << std::endl;
}

void Game::run() {

    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while(mWindow.isOpen()) {
        processEvents();
        timeSinceLastUpdate += clock.restart();
        while(timeSinceLastUpdate > TimePerFrame) {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);
        }
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while(mWindow.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            mWindow.close();
        }
        if (event.type == sf::Event::KeyPressed) {
            handlePlayerInput(event.key.code, true);
        }
        if (event.type == sf::Event::KeyReleased) {
            handlePlayerInput(event.key.code, false);
        }
    }
}

void Game::update(sf::Time deltaTime) {
    sf::Vector2 movement(0.f, 0.f);
    if(isMovingUp)
        movement.y = -playerSpeed;
    if(isMovingDown)
        movement.y = playerSpeed;
    if(isMovingLeft)
        movement.x = -playerSpeed;
    if(isMovingRight)
        movement.x = playerSpeed;

    world.update(deltaTime);
}


void Game::render() {
    mWindow.clear();
    world.draw();
    mWindow.setView(mWindow.getDefaultView());
    mWindow.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
    if(key == sf::Keyboard::W)
        isMovingUp = isPressed;
    else if(key == sf::Keyboard::S)
        isMovingDown = isPressed;
    else if(key == sf::Keyboard::A)
        isMovingLeft = isPressed;
    else if(key == sf::Keyboard::D)
        isMovingRight = isPressed;
};
