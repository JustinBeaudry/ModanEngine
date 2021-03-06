cmake_minimum_required(VERSION 3.8)
project(ModanEngine)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${SDL_INCLUDE_DIRS} ${SDL_IMAGE_INCLUDE_DIRS})

set(SOURCE_FILES main.cpp Game.cpp Game.h TextureManager.h TextureManager.cpp GameObject.cpp GameObject.h Map.cpp Map.h ECS/ECS.h ECS/Components.h ECS/Transform.h ECS/Sprite.h Vector2D.h Vector2D.cpp ECS/KeyboardController.h ECS/Collider.h Collision.h Collision.cpp ECS/Tile.h)
add_executable(ModanEngine ${SOURCE_FILES})

target_link_libraries(ModanEngine ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES})