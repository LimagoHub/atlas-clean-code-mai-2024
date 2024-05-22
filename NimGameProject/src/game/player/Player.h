//
// Created by JoachimWagner on 22.05.2024.
//

#pragma once

#include <string>

namespace atlas::game::player {
    template<class BOARD, class MOVE>
    class Player {
        public:
            virtual ~Player()= default;
            virtual std::string getName() const = 0;
            virtual MOVE makeMove(const BOARD &board) const = 0;
    };
}