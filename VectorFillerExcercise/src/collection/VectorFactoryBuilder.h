//
// Created by JoachimWagner on 23.05.2024.
//

#pragma once


#include <memory>
#include "VectorFactory.h"
#include "impl/sequential/VectorFactorySequentialImpl.h"
#include "impl/decorators/VectorFactoryLoggerDecorator.h"
#include "../generator/Generator.h"

class VectorFactoryBuilder {
    using VECTOR_FACTORY = std::unique_ptr<atlas::collection::VectorFactory<int>>;
    using VECTOR_FACTORY_SEQUENCIAL = atlas::collection::VectorFactorySequentialImpl<int>;
    using VECTOR_FACTORY_LOGGER = atlas::collection::VectorFactoryLoggerDecorator<int>;
    using GENERATOR = std::unique_ptr<atlas::generator::Generator<int>>;

    inline static bool logger{false};

    static bool isLogger() {
        return logger;
    }

    static void setLogger(bool logger) {
        VectorFactoryBuilder::logger = logger;
    }

    static VECTOR_FACTORY createWithGenerator(GENERATOR generator) {
        VECTOR_FACTORY result;
        result=  std::make_unique<VECTOR_FACTORY_SEQUENCIAL>(std::move(generator));
        if(logger) result = std::make_unique<VECTOR_FACTORY_LOGGER>(std::move(result));
        return result;
    }

};
