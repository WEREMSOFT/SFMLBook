//
// Created by Pablo Weremczuk on 2019-04-08.
//

#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "world.hpp"
#include "../core/resource_holder.hpp"
#include "constants/textures.hpp"
#include "../entity/aircraft.hpp"


class Game {
public:
    ResourceHolder<sf::Texture, Textures::ID> th;
    Game();
    ~Game();
    void run();

private:
    void processEvents();

    void update(sf::Time deltaTime);

    void render();

    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

    bool isMovingUp, isMovingDown, isMovingLeft, isMovingRight;
    sf::RenderWindow mWindow;
    sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
    static constexpr auto playerSpeed = 500.f;
    World world;
};


