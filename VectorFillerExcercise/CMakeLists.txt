cmake_minimum_required(VERSION 3.28)
project(VectorFillerExcercise)

set(CMAKE_CXX_STANDARD 17)

add_executable(VectorFillerExcercise main.cpp
        src/bootstrap/Bootstrap.h
        src/client/Client.h
        src/client/impl/ClientImpl.h
        src/collection/VectorFactory.h
        src/generator/Generator.h
        src/time/Stopwatch.h
        src/time/impl/StopwatchImpl.h
        src/time/impl/decorator.h
        src/generator/IntGenerator.h
        src/generator/impl/random/MersenneTwisterNumberGenerator.h
        src/collection/AbstractVectorFactory.h
        src/collection/impl/sequential/VectorFactorySequentialImpl.h
        src/collection/VectorFactoryBuilder.h
        src/collection/VectorFactoryBuilder.h
        src/collection/impl/decorators/VectorFactoryBenchmarkDecorator.h
        src/collection/impl/parallel/VectorFactoryParallelImpl.h
        src/generator/GeneratorBuilder.h
        src/generator/impl/random/MersenneTwisterNumberGeneratorFactory.h
        src/collection/impl/parallel/VectorFactoryAutoImpl.h
)
