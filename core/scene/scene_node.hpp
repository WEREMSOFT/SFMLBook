//
// Created by Pablo Weremczuk on 2019-04-08.
//

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>


class SceneNode: public sf::Transformable, public sf::Drawable, private sf::NonCopyable {
public:
    typedef std::unique_ptr<SceneNode> Ptr;

    SceneNode();
    void addChild(Ptr pChild);
    Ptr removeChild(const SceneNode& node);
    void update(sf::Time dt);
    sf::Transform getWorldTransform() const;
    sf::Vector2f getWorldPosition() const;

private:
    std::vector<Ptr> children;
    SceneNode* parent;

    virtual void updateCurrent(sf::Time dt);
    void updateChildren(sf::Time dt);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
};


