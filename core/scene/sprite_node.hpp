//
// Created by Pablo Weremczuk on 2019-04-08.
//

#pragma once
#include <SFML/Graphics.hpp>
#include "scene_node.hpp"


class SpriteNode: public SceneNode {
public:
    explicit SpriteNode(const sf::Texture& texture);
    SpriteNode(const sf::Texture& texture, const sf::IntRect& rect);

private:
    void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    sf::Sprite sprite;
};


