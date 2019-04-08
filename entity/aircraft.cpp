//
// Created by Pablo Weremczuk on 2019-04-08.
//

#include "aircraft.hpp"

Aircraft::Aircraft(Aircraft::Type pType, const TextureHolder &pTextures) : type(pType),
                                                                              sprite(pTextures.get(toTextureID(type))) {
    sf::FloatRect bounds = sprite.getLocalBounds();
    sprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

void Aircraft::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(sprite, states);
}

Textures::ID Aircraft::toTextureID(Aircraft::Type type) {
    switch (type) {
        case Aircraft::Type::EAGLE:
            return Textures::ID::EAGLE;
        case Aircraft::Type::RAPTOR:
            return Textures::ID::EAGLE;
    }
}
