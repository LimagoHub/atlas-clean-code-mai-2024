//
// Created by JoachimWagner on 22.05.2024.
//

#pragma once
#include "../../player/AbstractPlayer.h"
namespace atlas::game::player {

    class AbstractNimGamePlayer: public AbstractPlayer<int,int>{

    public:
        explicit AbstractNimGamePlayer(const std::string &name) : AbstractPlayer(name) {}
    };
}
