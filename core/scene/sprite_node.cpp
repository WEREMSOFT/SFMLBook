//
// Created by Pablo Weremczuk on 2019-04-08.
//

#include "sprite_node.hpp"

SpriteNode::SpriteNode(const sf::Texture &texture): sprite(texture){
    std::cout << "building spritenode" << std::endl;
}

SpriteNode::SpriteNode(const sf::Texture &texture, const sf::IntRect &rect): sprite(texture) {
    std::cout << "building spritenode second thingi" << std::endl;
    sprite.setTextureRect(rect);
}

void SpriteNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite, states);
}
