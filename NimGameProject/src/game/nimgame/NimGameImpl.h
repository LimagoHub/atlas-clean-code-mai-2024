//
// Created by JoachimWagner on 21.05.2024.
//

#pragma once
#include "../Game.h"

namespace atlas::game {
    class NimGameImpl : public Game{

        int stones;
        bool gameover;

        void playRound() {

            humanMove();
            computerMove();
        }

        void humanMove() {
            int move;
            while(true) {
                std::cout << "Es gibt " << stones << " Steine. Bitte nehme Sie 1,2 oder 3." << std::endl;
                std::cin >> move;
                if(move >= 1 && move <= 3) break;
                std::cout << "Ungueltiger Zug" << std::endl;
            }
            stones -= move;

        }
        void computerMove() {
            const int moves[] = {3,1,1,2};
            int move;

            if(stones < 1) {
                std::cout << " Du Loser" << std::endl;
                gameover = true;
                return;
            }
            if(stones == 1) {
                std::cout << " Du hast nur Glueck gehabt" << std::endl;
                gameover = true;
                return;
            }

            move = moves[stones % 4];
            std::cout << "Compuetr nimmt " << move << " Steine." << std::endl;
            stones -= move;
        }

    public:

        NimGameImpl():stones{23}, gameover{false} {

        }



        void play() override {
            while( ! gameover) {
                playRound();
            }

        }


    };
}



