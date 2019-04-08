//
// Created by Pablo Weremczuk on 2019-04-08.
//

#pragma once
#include <SFML/Graphics.hpp>
#include "scene/scene_node.hpp"


class Entity: public SceneNode {
private:
    sf::Vector2f velocity;

public:
    Entity();

    void setVelocity(sf::Vector2f pVelocity);
    void setVelocity(float x, float y);
    void updateCurrent(sf::Time dt);
    sf::Vector2f getVelocity();
};


