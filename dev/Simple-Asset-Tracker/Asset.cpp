#include "Asset.h"
#include <iostream>
#include <iomanip>

void Asset::Display() const
{
    std::cout << "\nID: " << id
        << "\nName: " << name
        << "\nCost: $" << std::fixed << std::setprecision(2) << cost
        << "\nRecurring: " << (recurring ? "Yes" : "No")
        << "\nFrequency: " << frequency << '\n';
}