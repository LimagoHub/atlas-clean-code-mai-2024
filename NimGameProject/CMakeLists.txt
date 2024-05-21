cmake_minimum_required(VERSION 3.28)
project(NimGameProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(NimGameProject main.cpp
        src/game/Game.h
        src/client/Client.h
        src/game/nimgame/NimGameImpl.h
)
