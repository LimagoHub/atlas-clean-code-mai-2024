//
// Created by JoachimWagner on 21.05.2024.
//

#pragma once

#include <vector>
#include "../AbstractGame.h"
#include "../player/Player.h"


namespace atlas::game {

    class NimGameImpl : public AbstractGame<int,int>{





        // ---- Implementierungssumpf -----------------------------------

    protected:

        void updateBoard() override { setBoard(getBoard() - getMove());}

        bool isGameover() const override{
            return getBoard() < 1 || getPlayers().empty();
        }

        bool isValid() const override{
            return getMove() >= 1 && getMove() <= 3;
        }
    public:

        explicit NimGameImpl(Writer &writer) : AbstractGame(writer) {
            setBoard(23);
        }


    };

}



