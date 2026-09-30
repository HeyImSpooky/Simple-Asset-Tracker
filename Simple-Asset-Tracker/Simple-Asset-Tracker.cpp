// Simple-Asset-Tracker.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <limits>

// Stores the information for one asset.
struct Asset {
    int id;
    std::string name;
    std::string cost;
	bool recurring;
	std::string frequency;
};

int main() {
    // Holds all the assets added during this session.
    std::vector<Asset> assets;

    int nextId = 1;
    int choice = 0;

    while (true) {
        std::cout << "\n=== Simple Asset Tracker ===\n";
        std::cout << "Version: 1.0.0 | Build Date: 9/29/2026\n";
        std::cout << "=== Made by: Spooky ===\n";
        std::cout << "\n\n";
        std::cout << "1. Add asset\n";
        std::cout << "2. View assets\n";
        std::cout << "3. Exit\n";
        std::cout << "Choose an option: ";

        // Exit cleanly if the input stream closes.
        if (!(std::cin >> choice)) {
            if (std::cin.eof()) {
                break;
            }

            // Clear invalid input so the menu can work again.
            std::cin.clear();
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(), '\n'
            );

            std::cout << "Please choose a real selection.\n";
            continue;
        }

        // Remove the leftover newline before using getline.
        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(), '\n'
        );

        switch (choice) {
        case 1: {
            Asset asset;

            std::cout << "Asset name: ";
            if (!std::getline(std::cin, asset.name)) {
                return 0;
            }

            if (asset.name.find_first_not_of(" \t") == std::string::npos) {
                std::cout << "Asset name cannot be empty.\n";
                break;
            }

            std::cout << "Cost: ";
            if (!std::getline(std::cin, asset.cost)) {
                return 0;
            }

			std::cout << "Recurring cost? (y/n): ";
            std::string recurring;
            if (!std::getline(std::cin, recurring)) {
                return 0;
            }

			std::cout << "Weekly or monthly? (w/m): ";
			std::string frequency;
			if (!std::getline(std::cin, frequency)) {
				return 0;
			}

            // Give the asset a unique ID and add it to the list.
            asset.id = nextId++;
            assets.push_back(asset);

            std::cout << "Asset added! ID: " << asset.id << "\n";
            break;
        }

        case 2:
            if (assets.empty()) {
                std::cout << "No assets added yet.\n";
            }
            else {
                for (const Asset& asset : assets) {
                    std::cout << "\nID: " << asset.id
                        << "\nName: " << asset.name
                        << "\nCost: " << asset.cost
                        << "\nRecurring: " << (asset.recurring ? "Yes" : "No")
                        << "\nFrequency: " << asset.frequency << "\n";
                }
            }
            break;

        case 3:
            std::cout << "Goodbye!\n";
            return 0;

        default:
            std::cout << "Please choose 1, 2, or 3.\n";
            break;
        }
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
