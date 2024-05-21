//
// Created by JoachimWagner on 21.05.2024.
//

#pragma once
#include "../game/Game.h"

namespace atlas::client {

    class Client {

        atlas::game::Game &game;

    public:
        explicit Client(atlas::game::Game &game) : game(game) {}

        virtual ~Client() = default;

        void go() {
            game.play();
        }

    };
}



