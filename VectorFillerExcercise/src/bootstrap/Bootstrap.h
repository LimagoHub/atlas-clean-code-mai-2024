//
// Created by JoachimWagner on 23.05.2024.
//

#pragma once

#include <iostream>
#include <thread>

namespace atlas::bootstrap {
    class Bootstrap {
    public:


        auto startApplication()-> void const {
            const size_t availableProcessors = std::thread::hardware_concurrency();

            std::cout << "System is running with " << availableProcessors << " Kernels.\n";
        }

    };
}
