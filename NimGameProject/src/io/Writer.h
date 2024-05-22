//
// Created by JoachimWagner on 22.05.2024.
//

#pragma once


#include <string_view>

class Writer {
public:
    virtual ~Writer()= default;


    virtual void write(std::string_view message) const = 0;

};
