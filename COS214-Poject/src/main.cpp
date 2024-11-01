// main.cpp
#include "GameState.h"  // Add this first to resolve incomplete type error
#include "MapGrid.h"
#include "CityComponent.h"
#include "ResidentialBuilding.h"
#include "CommercialBuilding.h"
#include "Industry.h"
#include "House.h"
#include "UtilityFlyweight.h"
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <limits>

class CityGame {
private:
    MapGrid grid;
    GameState state;
    bool running = true;

    void displayMenu() {
        std::cout << "\n\033[1;36m=== City Builder ===\033[0m\n"
                  << "Money: $" << state.getMoney() 
                  << " | Happiness: " << state.getHappiness() << "%\n\n"
                  << "1. Build Structure\n"
                  << "2. Place Utility\n"
                  << "3. Show Statistics\n"
                  << "4. Undo\n"
                  << "5. Redo\n"
                  << "0. Exit\n"
                  << "\nChoice: ";
    }

    // Updated handleBuildStructure with better error handling and feedback
    void handleBuildStructure() {
        std::cout << "\nSelect building type:\n"
                  << "1. House ($100)\n"
                  << "2. Commercial ($200)\n"
                  << "3. Industrial ($300)\n"
                  << "Choice: ";
        
        int choice;
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\033[1;31mInvalid input!\033[0m\n";
            return;
        }
        
        Location loc;
        std::cout << "Enter location (x y): ";
        if (!(std::cin >> loc.x >> loc.y)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\033[1;31mInvalid coordinates!\033[0m\n";
            return;
        }

        if (!grid.isValidLocation(loc)) {
            std::cout << "\033[1;31mInvalid location!\033[0m\n";
            return;
        }

        // Check if location is already occupied
        if (grid.getComponent(loc)) {
            std::cout << "\033[1;31mLocation already occupied!\033[0m\n";
            return;
        }

        std::shared_ptr<CityComponent> building;
        int cost = 0;

        switch (choice) {
            case 1: 
                cost = 100;
                building = std::make_shared<House>();
                break;
            case 2: 
                cost = 200;
                building = std::make_shared<CommercialBuilding>();
                break;
            case 3: 
                cost = 300;
                building = std::make_shared<Industry>();
                break;
            default: 
                std::cout << "\033[1;31mInvalid choice!\033[0m\n";
                return;
        }

        if (!state.spendMoney(cost)) {
            std::cout << "\033[1;31mNot enough money!\033[0m\n";
            return;
        }

        auto command = std::make_unique<PlaceComponentCommand>(grid, loc, building);
        state.executeCommand(std::move(command));

        // Verify placement was successful
        if (grid.getComponent(loc)) {
            std::cout << "\033[1;32mBuilding placed successfully!\033[0m\n";
        } else {
            state.addMoney(cost);  // Refund if placement failed
            std::cout << "\033[1;31mFailed to place building!\033[0m\n";
        }
    }

public:
    CityGame(int width, int height) : grid(width, height) {}

    void run() {
        while (running) {
            system("clear");  // or "cls" on Windows
            std::cout << grid.getDisplayString();
            displayMenu();

            int choice;
            std::cin >> choice;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            switch (choice) {
                case 1: handleBuildStructure(); break;
                case 4: state.undo(); break;
                case 5: state.redo(); break;
                case 0: running = false; break;
                default: std::cout << "\033[1;31mInvalid choice!\033[0m\n";
            }
        }
    }
};

int main() {
    try {
        CityGame game(10, 10);
        game.run();
    } catch (const std::exception& e) {
        std::cerr << "\033[1;31mError: " << e.what() << "\033[0m\n";
        return 1;
    }
    return 0;
}