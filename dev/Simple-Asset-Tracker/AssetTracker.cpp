#include "AssetTracker.h"
#include "ConsoleColors.h"

#include <iostream>
#include <limits>
#include <string>

void AssetTracker::Run() {

    // TODO: Load saved assets here later.

    while (true)
    {
        ConsoleColor::Menu("\n=== Simple Asset Tracker ===");
        std::cout << "Version: 2.0.0 | Build Date: 10/11/2026\n";
        std::cout << "=== Made by: Spooky ===\n\n";

        ConsoleColor::Menu("1. Add asset\n2. View assets\n3. Exit");
        std::cout << "Choose an option: ";

        int choice = 0;

        if (!(std::cin >> choice))
        {
            // Stop if the input stream closes.
            if (std::cin.eof())
                return;

            // Clear bad input so the user can try again.
            std::cin.clear();
            std::cin.ignore(
                (std::numeric_limits<std::streamsize>::max)(), '\n'
            );

            ConsoleColor::Warning("Please choose a real selection.");
            continue;
        }

        // Remove the newline left behind by reading the number.
        std::cin.ignore(
            (std::numeric_limits<std::streamsize>::max)(), '\n'
        );

        switch (choice)
        {
        case 1:
            if (!AddAsset())
                return;
            break;

        case 2:
            ViewAssets();
            break;

        case 3:
            ConsoleColor::Success("Goodbye!\n");
            return;

        default:
            ConsoleColor::Warning("Please choose 1, 2, or 3.");
            break;
        }
    }
}

bool AssetTracker::AddAsset() {
    Asset asset;

    std::cout << "Asset name: ";
    if (!std::getline(std::cin, asset.name))
        return false;

    if (asset.name.find_first_not_of(" \t") == std::string::npos)
    {
        ConsoleColor::Error("Asset name cannot be empty.");
        return true; // Return to the menu.
    }

    // Cost remains text for now.
    // TODO: Validate that the cost is a number.
    std::cout << "Cost: ";
    if (!std::getline(std::cin, asset.cost))
        return false;

    std::string recurring;
    std::cout << "Recurring cost? (y/n): ";
    if (!std::getline(std::cin, recurring))
        return false;

    if (recurring != "y" && recurring != "Y" &&
        recurring != "n" && recurring != "N")
    {
        ConsoleColor::Error("Please enter y or n.");
        return true;
    }

    asset.recurring = (recurring == "y" || recurring == "Y");

    // Only ask for a frequency if the cost repeats.
    if (asset.recurring)
    {
        std::string frequency;
        std::cout << "Weekly or monthly? (w/m): ";

        if (!std::getline(std::cin, frequency))
            return false;

        if (frequency == "w" || frequency == "W")
        {
            asset.frequency = "Weekly";
        }
        else if (frequency == "m" || frequency == "M")
        {
            asset.frequency = "Monthly";
        }
        else
        {
            ConsoleColor::Error("Please enter w or m.");
            return true;
        }
    }

    // Assign an ID once the asset is ready to add.
    asset.id = nextId++;
    assets.push_back(asset);

    ConsoleColor::Success(
        "Asset added! ID: " + std::to_string(asset.id)
    );

    // TODO: Save assets to a file here later.
    return true;
}

void AssetTracker::ViewAssets() const
{
    if (assets.empty())
    {
        ConsoleColor::Warning("No assets added yet.");
        return;
    }

    for (const Asset& asset : assets)
    {
        asset.Display();
    }
}