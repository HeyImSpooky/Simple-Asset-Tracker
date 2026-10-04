#pragma once

#include <string>

struct Asset
{
    int id = 0;
    std::string name;
    std::string cost;
    bool recurring = false;
    std::string frequency = "None";
};