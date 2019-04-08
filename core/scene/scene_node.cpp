//
// Created by Pablo Weremczuk on 2019-04-08.
//

#include "scene_node.hpp"

SceneNode::SceneNode() {
}

void SceneNode::addChild(SceneNode::Ptr pChild) {
    pChild->parent = this;
    children.push_back(std::move(pChild));
}

SceneNode::Ptr SceneNode::removeChild(const SceneNode &node) {
    auto found = std::find_if(
            children.begin(),
            children.end(),
            [&] (Ptr& p) -> bool {return p.get() == &node; });
    assert(found != children.end());
    Ptr result = std::move(*found);
    result->parent = nullptr;
    children.erase(found);
    return result;
}

void SceneNode::update(sf::Time dt) {
    updateCurrent(dt);
    updateChildren(dt);
}

sf::Transform SceneNode::getWorldTransform() const {
    sf::Transform returnValue = sf::Transform::Identity;

    for(const SceneNode* node = this; node != nullptr; node = node->parent){
        returnValue = node->getTransform() * returnValue;
    }

    return returnValue;
}

sf::Vector2f SceneNode::getWorldPosition() const {
    sf::Vector2f returnValue = getWorldTransform() * sf::Vector2f();
    return returnValue;
}


void SceneNode::updateChildren(sf::Time dt) {
    for(Ptr& child: children) child->update(dt);
}

void SceneNode::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    drawCurrent(target, states);
    for (auto itr = children.begin(); itr != children.end(); ++itr){
        (*itr)->draw(target, states);
    }
}

void SceneNode::updateCurrent(sf::Time dt) {

}

void SceneNode::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const {

}
