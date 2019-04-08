cmake_minimum_required(VERSION 3.13)
project(4_Controllers)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wc++17-extensions -std=c++17 -framework GLUT -framework sfml-audio  -framework sfml-graphics -framework sfml-window -framework sfml-system")
file(COPY images DESTINATION ./)

add_executable(4_Controllers main.cpp entity/aircraft.cpp entity/aircraft.hpp core/entity.cpp core/entity.hpp core/resource_holder.hpp core/scene/scene_node.cpp core/scene/scene_node.hpp game/game.cpp game/game.hpp game/world.cpp game/world.hpp core/scene/sprite_node.cpp core/scene/sprite_node.hpp)
