//
// Created by JoachimWagner on 23.05.2024.
//

#pragma once


#include <memory>
#include "VectorFactory.h"
#include "impl/sequential/VectorFactorySequentialImpl.h"
#include "impl/decorators/VectorFactoryLoggerDecorator.h"
#include "impl/decorators/VectorFactorySecureDecorator.h"
#include "impl/decorators/VectorFactoryBenchmarkDecorator.h"
#include "../generator/GeneratorBuilder.h"
namespace atlas::collection {
    class VectorFactoryBuilder {
        using VECTOR_FACTORY = std::unique_ptr<atlas::collection::VectorFactory<int>>;
        using VECTOR_FACTORY_SEQUENCIAL = atlas::collection::VectorFactorySequentialImpl<int>;
        using VECTOR_FACTORY_LOGGER = atlas::collection::VectorFactoryLoggerDecorator<int>;
        using VECTOR_FACTORY_SECURE = atlas::collection::VectorFactorySecureDecorator<int>;
        using VECTOR_FACTORY_BENCHMARK = atlas::collection::VectorFactoryBenchmarkDecorator<int>;

        using GENERATOR_BUILDER = std::unique_ptr<atlas::generator::GeneratorBuilder<int>>;

    public:
        inline static bool logger{false};
        inline static bool secure{false};
        inline static bool benchmark{false};

        static bool isLogger() {
            return logger;
        }

        static void setLogger(bool logger) {
            VectorFactoryBuilder::logger = logger;
        }

        static bool isSecure() {
            return secure;
        }

        static void setSecure(bool secure) {
            VectorFactoryBuilder::secure = secure;
        }

        static bool isBenchmark() {
            return benchmark;
        }

        static void setBenchmark(bool benchmark) {
            VectorFactoryBuilder::benchmark = benchmark;
        }

        static VECTOR_FACTORY createWithGenerator(GENERATOR_BUILDER generatorbuilder, size_t threadCount) {
            VECTOR_FACTORY result;
            switch(threadCount) {
                default:
                case 1: result = std::make_unique<VECTOR_FACTORY_SEQUENCIAL>(std::move(generatorbuilder->create()));
                break;


            }

            if (logger) result = std::make_unique<VECTOR_FACTORY_LOGGER>(std::move(result));
            if (secure) result = std::make_unique<VECTOR_FACTORY_SECURE >(std::move(result));
            if (benchmark) result = std::make_unique<VECTOR_FACTORY_BENCHMARK >(std::move(result));
            return result;
        }

    };
}
