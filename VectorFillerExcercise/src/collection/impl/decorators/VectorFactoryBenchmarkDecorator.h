//
// Created by JoachimWagner on 10.04.2024.
//

#pragma once

#include <iostream>
#include "AbstractVectorFactoryDecorator.h"
#include "../../../time/impl/StopwatchImpl.h"
namespace atlas::collection {

    template<class T>
    class VectorFactoryBenchmarkDecorator: public AbstractVectorFactoryDecorator<T> {
        using VectorFactoryPointer = std::unique_ptr<VectorFactory<T>>;
        using StopwatchPointer = std::unique_ptr<atlas::time::Stopwatch>;
        using VECTOR = std::shared_ptr<std::vector<T>>;

        StopwatchPointer stopwatch_;
    public:
        //~VectorFactoryBenchmarkDecorator() override= default;
        explicit VectorFactoryBenchmarkDecorator(VectorFactoryPointer vectorFactoryPointer_,
                                                 StopwatchPointer stopwatch=std::make_unique<atlas::time::StopwatchImpl>())
                :AbstractVectorFactoryDecorator<T>{std::move(vectorFactoryPointer_)},stopwatch_{std::move(stopwatch)}{}


        auto createAndFillVector(size_t size) -> VECTOR override {
            stopwatch_->start();
            VECTOR result = this->vectorFactoryPointer->createAndFillVector(size);
            stopwatch_->stop();
            std::cout << "Dauer = " << stopwatch_->getDuration().count() << " millis." << std::endl;
            return result;
        }

    };

} // collections
