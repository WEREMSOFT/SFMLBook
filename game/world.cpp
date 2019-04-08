//
// Created by Pablo Weremczuk on 2019-04-08.
//

#include "world.hpp"

World::World(sf::RenderWindow& pWindow):
        window(pWindow),
        view(window.getDefaultView()),
        worldBounds(0.f, 0.f, view.getSize().x, 2000.f),
        spawnPosition(
                view.getSize().x / 2.f,
                worldBounds.height - view.getSize().y
        ),
        playerAircraft(nullptr) {
    loadTextures();
    buildScene();
    view.setCenter(spawnPosition);
}

void World::update(sf::Time dt){
    view.move(0.f, scrollSpeed * dt.asSeconds());

    sf::Vector2f position = playerAircraft->getPosition();
    sf::Vector2f velocity = playerAircraft->getVelocity();

    playerAircraft->setRotation(playerAircraft->getRotation() + 50.f * dt.asSeconds());

    if(position.x <= worldBounds.left + 150 ||
       position.x >= worldBounds.left + worldBounds.width - 150){
        velocity.x = -velocity.x;
        playerAircraft->setVelocity(velocity);
    }

    sceneGraph.update(dt);
}

void World::draw() {
    window.setView(view);
    window.draw(sceneGraph);
}

void World::loadTextures() {
    textures.load(Textures::EAGLE, "images/eagle.png");
    textures.load(Textures::RAPTOR, "images/raptor.png");
    textures.load(Textures::DESERT, "images/desert.jpg");
}

void World::buildScene() {
    for(std::size_t i = 0; i < LAYERCOUNT; ++i){
        SceneNode::Ptr layer(new SceneNode());
        sceneLayers[i] = layer.get();
        sceneGraph.addChild(std::move(layer));
    }


    // Set the background properties
    sf::Texture& texture = textures.get(Textures::DESERT);
    sf::IntRect textureRect(worldBounds);
    texture.setRepeated(true);

    std::unique_ptr<SpriteNode> backgroundSprite(new SpriteNode(texture, textureRect));
    backgroundSprite->setPosition(worldBounds.left, worldBounds.top);
    sceneLayers[BACKGROUND]->addChild(std::move(backgroundSprite));

    // Planes
    std::unique_ptr<Aircraft> leader(new Aircraft(Aircraft::Type::EAGLE , textures));

    playerAircraft = leader.get();
    playerAircraft->setPosition(spawnPosition);
    playerAircraft->setVelocity(40.f, scrollSpeed);
    sceneLayers[AIR]->addChild(std::move(leader));

    // Escort
    std::unique_ptr<Aircraft> escort(new Aircraft(Aircraft::Type::RAPTOR , textures));
    escort->setPosition(80.f, 50.f);
    playerAircraft->addChild(std::move(escort));
}