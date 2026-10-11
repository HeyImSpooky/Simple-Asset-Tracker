#pragma once

#include <string>

class InputReader
{
public:
    // Returns false if input closes.
    // Otherwise, stores a valid number in value.
    bool ReadInt(const std::string& prompt,
        int min, int max, int& value) const;
    bool ReadCost(const std::string& prompt,
        double& value) const;
};