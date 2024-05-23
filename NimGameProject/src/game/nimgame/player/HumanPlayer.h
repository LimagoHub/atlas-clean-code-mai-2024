//
// Created by JoachimWagner on 22.05.2024.
//

#pragma once
#include <iostream>
#include "AbstractNimGamePlayer.h"

namespace atlas::game::player {

    class HumanPlayer:public AbstractNimGamePlayer {
    public:
        using AbstractNimGamePlayer::AbstractNimGamePlayer;

        [[nodiscard]] int makeMove(const int &stones) const  override {
            int move;
            std::cout << "Es gibt " << stones << " Steine. Bitte nehme Sie 1,2 oder 3." << std::endl;
            std::cin >> move;
            return move;
        }
    };
}
