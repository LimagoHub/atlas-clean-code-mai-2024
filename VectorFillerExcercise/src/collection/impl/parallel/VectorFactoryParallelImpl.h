//
// Created by JoachimWagner on 23.05.2024.
//

#pragma once
#include <memory>
#include "../../AbstractVectorFactory.h"
namespace atlas::collection {

    template<class T>
    class VectorFactoryParallelImpl: public AbstractVectorFactory<T>{

        
        size_t threadCount_


    protected:
        auto fill_array() -> void override {
            // TODO implement method
        }
    };

}
