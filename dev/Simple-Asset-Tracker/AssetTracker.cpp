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

        ConsoleColor::Menu(
            "1. Add asset\n2. View assets\n3. Delete asset\n4. Exit");
        int choice = 0;

        if (!input.ReadInt("Choose an option: ", 1, 4, choice))
        {
            return;
        }
        switch (choice)
        {
        case 1:
            if (!AddAsset())
            {
                return;
            }
            break;

        case 2:
            ViewAssets();
            break;

        case 3:
            if (!DeleteAsset())
                return;
            break;

        case 4:
            ConsoleColor::Success("Goodbye!");
            return;
        }
    }
}

bool AssetTracker::AddAsset() {
    Asset asset;

    while (true)
    {
        std::cout << "Asset name: ";

        if (!std::getline(std::cin, asset.name))
            return false;

        if (asset.name.find_first_not_of(" \t\r") != std::string::npos)
            break;

        ConsoleColor::Error("Asset name cannot be empty. Try again.");
    }

    if (!input.ReadCost("Enter a cost of 0 or more: ", asset.cost))
    {
        return false;
    }

    std::string recurring;

    while (true)
    {
        std::cout << "Recurring cost? (y/n): ";

        if (!std::getline(std::cin, recurring))
            return false;

        if (recurring == "y" || recurring == "Y" ||
            recurring == "n" || recurring == "N")
        {
            asset.recurring = (recurring == "y" || recurring == "Y");
            break;
        }

        ConsoleColor::Error("Please enter y or n. Try again.");
    }
    if (asset.recurring)
    {
        while (true)
        {
            std::string frequency;
            std::cout << "Weekly or monthly? (w/m): ";

            if (!std::getline(std::cin, frequency))
                return false;

            if (frequency == "w" || frequency == "W")
            {
                asset.frequency = "Weekly";
                break;
            }

            if (frequency == "m" || frequency == "M")
            {
                asset.frequency = "Monthly";
                break;
            }

            ConsoleColor::Error("Please enter w or m. Try again.");
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
    std::cout << "\n=== Asset List ===\n";
    std::cout << "Total assets: " << assets.size() << '\n';
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
bool AssetTracker::DeleteAsset()
{
    if (assets.empty())
    {
        ConsoleColor::Warning("No assets to delete.");
        return true;
    }

    ViewAssets();

    int id = 0;
    if (!input.ReadInt("Enter asset ID (0 to cancel): ",
        0, nextId - 1, id))
        return false;

    if (id == 0)
        return true;

    // Find the asset with this ID.
    for (auto it = assets.begin(); it != assets.end(); ++it)
    {
        if (it->id == id)
        {
            assets.erase(it);
            ConsoleColor::Success("Asset deleted.");
            return true;
        }
    }

    ConsoleColor::Warning("Asset ID not found.");
    return true;
}