//
// Created by JoachimWagner on 22.05.2024.
//

#pragma once

#include <iostream>
#include "Writer.h"

class ConsoleWriter: public Writer{
public:
    void write(std::string_view message) const override {
        std::cout << message << std::endl;
    }
};
