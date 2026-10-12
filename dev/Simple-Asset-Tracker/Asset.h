#pragma once

#include <string>

class Asset
{
public:
    int id = 0;
    std::string name;
    double cost = 0.0;
    bool recurring = false;
    std::string frequency = "None";
    void Display() const;
};