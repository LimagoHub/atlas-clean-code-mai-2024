//
// Created by JoachimWagner on 23.05.2024.
//

#pragma once

#include <iostream>
#include <thread>
#include <memory>
#include "../generator/impl/random/MersenneTwisterNumberGeneratorFactory.h"
#include "../collection/VectorFactoryBuilder.h"
#include "../client/impl/ClientImpl.h"

namespace atlas::bootstrap {
    class Bootstrap {
        using VECTOR_FACTORY = std::unique_ptr<atlas::collection::VectorFactory<int>>;
        using GENERATOR_BUILDER = std::unique_ptr<generator::GeneratorBuilder<int>>;
    public:


        static void create(size_t threadcount) {
            std::cout << "Messung mit " << threadcount << " Threads" << std::endl;
            VECTOR_FACTORY factory = createVectorFactory(threadcount);

            atlas::client::VectorClientImpl client{std::move(factory)};
            client.doSomethingWithLargeVector();
        }

        static VECTOR_FACTORY createVectorFactory (size_t threadCount) {
            //collection::VectorFactoryBuilder::setLogger(true);
            //collection::VectorFactoryBuilder::setSecure(true);
            collection::VectorFactoryBuilder::setBenchmark(true);
            return collection::VectorFactoryBuilder::createWithGenerator(createGeneratorBuilder(),threadCount );
        }

        static GENERATOR_BUILDER createGeneratorBuilder() {
            GENERATOR_BUILDER generatorBuilder = std::make_unique<atlas::generator::MersenneTwisterNumberGeneratorFactory>();
            return generatorBuilder;
        }

        auto startApplication()-> void const {
            const size_t availableProcessors = std::thread::hardware_concurrency();
            for (int threadCount = 0; threadCount <= availableProcessors + 1; ++threadCount) {
                create(threadCount);
            }

        }

    };
}
