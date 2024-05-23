cmake_minimum_required(VERSION 3.28)
project(VectorFillerExcercise)

set(CMAKE_CXX_STANDARD 17)

add_executable(VectorFillerExcercise main.cpp
        src/bootstrap/Bootstrap.h
        src/client/Client.h
        src/client/impl/ClientImpl.h
        src/collection/VectorFactory.h
        src/generator/Generator.h
        src/time/Stopwatch.h)
