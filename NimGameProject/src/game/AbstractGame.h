//
// Created by JoachimWagner on 22.05.2024.
//

#pragma once

#include <vector>
#include "Game.h"
#include "player/Player.h"
#include "../io/Writer.h"

namespace atlas::game {
    template<class BOARD, class MOVE>
    class AbstractGame:public Game {

        using PLAYER = atlas::game::player::Player<BOARD,MOVE>;
    public:

        explicit AbstractGame(Writer &writer) : writer(writer) {}

        void play() override {
            while( ! isGameover()) {
                playRound();
            }

        }

        void addPlayer(PLAYER * player) {
            players.push_back(player);
        }

        void removePlayer(PLAYER * player){
            // TODO implement
        }

    private:

        BOARD board;
        MOVE move;



        Writer &writer;
        std::vector<PLAYER *> players;
        PLAYER * currentPlayer;

        void playRound() {
            //int n =  5;
            for( auto player : players) {
                setCurrentPlayer(player);
                playSingleMove();
            }

        }


        void playSingleMove() {
            if(isGameover()) return;
            executeMove();
            terminateMove( );

        }

        void executeMove() {
            do {
                move = getCurrentPlayer()->makeMove(board);
            } while( moveIsNotValid());
        }

        void terminateMove() {  // Intergation
            updateBoard();
            printGameOverMessageIfgameIsOver();
        }

        bool moveIsNotValid() {
            if(  isValid()) return false;
            write( "Ungueltiger Zug" );
            return true;
        }
        void printGameOverMessageIfgameIsOver() { // Operation
            // TODO Make it better
            if(isGameover()) {
               write( getCurrentPlayer()->getName() + " hat verloren");
            }
        }

    protected:


        virtual bool isGameover() const = 0;
        virtual bool isValid() const = 0;
        virtual void updateBoard()  = 0;



        void write(std::string_view message) const{
            writer.write(message);
        }

        const std::vector<PLAYER *> &getPlayers() const {
            return players;
        }



        BOARD getBoard() const {
            return board;
        }

        void setBoard(BOARD board) {
            AbstractGame::board = board;
        }

        MOVE getMove() const {
            return move;
        }

        void setMove(MOVE move) {
            AbstractGame::move = move;
        }

        PLAYER *getCurrentPlayer() const {
            return currentPlayer;
        }

        void setCurrentPlayer(PLAYER *currentPlayer_) {
            currentPlayer = currentPlayer_;
        }
    };
}
