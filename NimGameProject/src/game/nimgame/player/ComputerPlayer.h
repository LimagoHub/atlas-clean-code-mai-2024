//
// Created by JoachimWagner on 22.05.2024.
//
#pragma once
#include <iostream>
#include "AbstractNimGamePlayer.h"

namespace atlas::game::player {

    class ComputerPlayer:public AbstractNimGamePlayer {
        inline static const int moves[] = {3,1,1,2};
    public:
        explicit ComputerPlayer(const std::string &name) : AbstractNimGamePlayer(name) {}

        int makeMove(const int &stones) override {
            int move = moves[stones % 4];
            std::cout << "Computer nimmt " << move << " Steine." << std::endl;
            return move;
        }
    };
}