#pragma once

#include <memory>
#include <SFML/Graphics.hpp>
#include "game_object.h"

class Game {
public:
    Game();
    void run();

private:
    sf::Clock         clock;
    sf::Time          delta_time;
    sf::RenderWindow  window;
    sf::Vector2f      resolution;
    float             fps;
    bool              paused;

    std::unique_ptr <GameObject> background;
    std::unique_ptr <GameObject> tree;
    std::unique_ptr <GameObject> bee;
    std::unique_ptr <GameObject> cloud;
    std::unique_ptr <GameObject> cloud2;


    auto initObject(GameObject::Type type,
                    const std::string &texture_file,
                    float sprite_x = 0,
                    float sprite_y = 0,
                    float speed    = 0 ) {
         return std::make_unique <GameObject>(
             type, texture_file, sprite_x, sprite_y, speed);
    }

    void handleInput();
    void update();
    void draw();
};