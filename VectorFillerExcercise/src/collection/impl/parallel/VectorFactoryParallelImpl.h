//
// Created by JoachimWagner on 23.05.2024.
//

#pragma once
#include <memory>
#include "../../AbstractVectorFactory.h"
#include "../../../generator/GeneratorBuilder.h"
namespace atlas::collection {

    template<class T>
    class VectorFactoryParallelImpl: public AbstractVectorFactory<T>{
        using MyGeneratorFactory = std::unique_ptr<generator::GeneratorBuilder<T>>;

        MyGeneratorFactory generatorFactory_;
        size_t threadCount_;

    public:
        VectorFactoryParallelImpl(MyGeneratorFactory generatorFactory, size_t threadCount) :
                generatorFactory_(
                std::move(generatorFactory)), threadCount_(threadCount) {}


    protected:
        auto fill_array() -> void override {
            // TODO implement method
        }
    };

}
