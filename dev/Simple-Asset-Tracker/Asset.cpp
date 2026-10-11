#include "Asset.h"
#include <iostream>

void Asset::Display() const
{
    std::cout << "\nID: " << id
        << "\nName: " << name
        << "\nCost: " << cost
        << "\nRecurring: " << (recurring ? "Yes" : "No")
        << "\nFrequency: " << frequency << '\n';
}