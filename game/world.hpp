//
// Created by Pablo Weremczuk on 2019-04-08.
//

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>
#include "../core/scene/sprite_node.hpp"
#include "constants/typedefs.hpp"
#include "../entity/aircraft.hpp"
#include <array>

class World : private sf::NonCopyable {
public:
    explicit World(sf::RenderWindow &pWindow);
    void update(sf::Time dt);
    void draw();

private:
    void loadTextures();
    void buildScene();

private:
    enum Layer {
        BACKGROUND,
        AIR,
        LAYERCOUNT
    };

    std::array<SceneNode *, LAYERCOUNT> sceneLayers;
    sf::RenderWindow &window;
    sf::View view;
    TextureHolder textures;
    SceneNode sceneGraph;
    sf::FloatRect worldBounds;
    sf::Vector2f spawnPosition;
    float scrollSpeed = -50.f;
    Aircraft *playerAircraft;
};


