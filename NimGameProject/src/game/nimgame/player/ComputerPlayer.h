//
// Created by JoachimWagner on 22.05.2024.
//
#pragma once
#include <iostream>
#include <array>
#include "AbstractNimGamePlayer.h"

namespace atlas::game::player {

    class ComputerPlayer:public AbstractNimGamePlayer {
       static constexpr std::array<int,4> moves{3,1,1,2};
    public:
        using AbstractNimGamePlayer::AbstractNimGamePlayer;

          [[nodiscard]] int makeMove(const int &stones) const  override {
            int move = moves[stones % 4];
            std::cout << "Computer nimmt " << move << " Steine." << std::endl;
            return move;
        }
    };
}