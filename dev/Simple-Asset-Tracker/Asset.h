#pragma once

#include <string>

class Asset
{
public:
    int id = 0;
    std::string name;
    std::string cost;
    bool recurring = false;
    std::string frequency = "None";
    void Display() const;
};