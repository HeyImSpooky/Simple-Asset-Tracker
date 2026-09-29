// Simple-Asset-Tracker.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <chrono>

int main()
{
    std::cout << "==========================\n";
    std::cout << "Simple Asset Tracker | COS1 Development Project\n";
    std::cout << "Version: 1.0.0 | Build Date: " << __DATE__ << " " << __TIME__ << " | Created by: Spooky\n";
    std::cout << "==========================\n";
    std::cout << "\n\n";
    std::cout << "Initializing the data and threads...\n";

    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "\n\n";
    std::cout << "Database started successfully.\n";

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
