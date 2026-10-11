#include "InputReader.h"
#include <iostream>
#include <stdexcept>
#include <cmath>

bool InputReader::ReadInt(const std::string& prompt,
    int min, int max, int& value) const
{
    std::string input;

    while (true)
    {
        std::cout << prompt;

        // Stop if the input stream closes.
        if (!std::getline(std::cin, input))
            return false;

        try
        {
            std::size_t used = 0;
            int number = std::stoi(input, &used);

            // Reject extra text, and invalid ranges.
            if (input.find_first_not_of(" \t\r", used)
                != std::string::npos
                || number < min || number > max)
            {
                throw std::invalid_argument("Invalid selection");
            }

            value = number;
            return true;
        }
        catch (const std::invalid_argument&)
        {
            std::cout << "Enter a whole number from "
                << min << " to " << max << ".\n";
        }
        catch (const std::out_of_range&)
        {
            std::cout << "That number is too large. Try again.\n";
        }
    }
}
    bool InputReader::ReadCost(const std::string & prompt,
        double& value) const
    {
        std::string text;

        while (true)
        {
            std::cout << prompt;

            if (!std::getline(std::cin, text))
                return false;

            try
            {
                std::size_t used = 0;
                double cost = std::stod(text, &used);

                // Reject extra text, negative costs, infinity, and NaN.
                if (text.find_first_not_of(" \t\r", used)
                    != std::string::npos
                    || !std::isfinite(cost) || cost < 0)
                {
                    throw std::invalid_argument("Invalid cost");
                }

                value = cost;
                return true;
            }
            catch (const std::invalid_argument&)
            {
                std::cout << "Enter a numeric cost of 0 or more.\n";
            }
            catch (const std::out_of_range&)
            {
                std::cout << "That cost is outside the supported range.\n";
            }
        }
    }