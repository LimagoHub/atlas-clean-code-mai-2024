//
// Created by JoachimWagner on 21.05.2024.
//

#pragma once

namespace atlas::game {
    class Game {

    public:
        virtual ~Game() = default;

        virtual void play() = 0;

    };

}



