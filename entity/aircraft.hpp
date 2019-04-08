//
// Created by Pablo Weremczuk on 2019-04-08.
//

#pragma once
#include <SFML/Graphics.hpp>
#include "../core/entity.hpp"
#include "../game/constants/textures.hpp"
#include "../core/resource_holder.hpp"
#include "../game/constants/typedefs.hpp"

class Aircraft : public Entity  {
public:
    enum Type {
        EAGLE,
        RAPTOR
    };

    explicit Aircraft(Aircraft::Type pType, const TextureHolder &pTextures );

    void drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;
private:
    Textures::ID toTextureID(Aircraft::Type type);
    Type type;
    sf::Sprite sprite;
};


