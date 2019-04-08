//
// Created by Pablo Weremczuk on 2019-04-08.
//
#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>


template <typename Resource, typename Identifier>
class ResourceHolder {
private:
    std::map<Identifier, std::unique_ptr<Resource>> resourceMap;
public:
    void load(Identifier id, const std::string& filename);
    Resource& get(Identifier id) const;
};

template <typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string& filename){
    std::unique_ptr<Resource> resource(new Resource());
    assert(resource->loadFromFile(filename) && "ERROR!! SOMETHING WHEN WRONG LOADING RESOURCE ");
    auto inserted = resourceMap.insert(std::make_pair(id, std::move(resource)));
    assert(inserted.second);
}


template<typename Resource, typename Identifier>
Resource& ResourceHolder<Resource, Identifier>::get(Identifier id) const {

    auto found = resourceMap.find(id);
    assert(found != resourceMap.end());
    return *found->second;

}


