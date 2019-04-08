//
// Created by Pablo Weremczuk on 2019-04-08.
//

#include "entity.hpp"

Entity::Entity() {}

void Entity::setVelocity(sf::Vector2f pVelocity) {
    velocity = pVelocity;
}

void Entity::setVelocity(float x, float y) {
    velocity.x = x;
    velocity.y = y;
}

void Entity::updateCurrent(sf::Time dt) {
    move(velocity * dt.asSeconds());
}

sf::Vector2f Entity::getVelocity() {
    return velocity;
}
