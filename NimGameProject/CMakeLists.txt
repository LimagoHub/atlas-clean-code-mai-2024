cmake_minimum_required(VERSION 3.28)
project(NimGameProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(NimGameProject main.cpp
        src/game/Game.h
        src/client/Client.h
        src/game/nimgame/NimGameImpl.h
        src/game/nimgame/player/AbstractNimGamePlayer.h
        src/game/nimgame/player/HumanPlayer.h
        src/game/nimgame/player/ComputerPlayer.h
        src/game/player/Player.h
        src/game/player/AbstractPlayer.h
        src/game/AbstractGame.h
        src/io/Writer.h
        src/io/ConsoleWriter.h
)
