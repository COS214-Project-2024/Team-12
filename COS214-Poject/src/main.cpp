// main.cpp
#include "GameState.h"  // Add this first to resolve incomplete type error
#include "MapGrid.h"
#include "CityComponent.h"
#include "ResidentialBuilding.h"
#include "CommercialBuilding.h"
#include "Industry.h"
#include "House.h"
#include "UtilityFlyweight.h"
#include "UtilityFactory.h"
#include "WaterSupply.h"
#include "PowerPlant.h"
#include "SewageSystem.h"
#include "WasteManagement.h"
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
                  << "4. Create Zone\n"
                  << "5. Show Zone Info\n"
                  << "6. Undo\n"
                  << "7. Redo\n"
                  << "0. Exit\n"
                  << "\nChoice: ";
    }

    void showStatistics() {
        std::cout << "\n=== City Statistics ===\n"
                << "Money: $" << state.getMoney() << "\n"
                << "Happiness: " << state.getHappiness() << "%\n"
                  // Add more statistics here
                << "\nPress Enter to continue...";
        std::cin.get();
    }

void handleCreateZone() {
    std::cout << "\nSelect zone type:\n"
              << "1. Residential Zone\n"
              << "2. Commercial Zone\n"
              << "3. Industrial Zone\n"
              << "Choice: ";

    int choice;
    std::string zoneType;
    if (!(std::cin >> choice)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\033[1;31mInvalid input!\033[0m\n";
        return;
    }

    switch(choice) {
        case 1: zoneType = "Residential"; break;  // Match the zone type strings in MapGrid
        case 2: zoneType = "Commercial"; break;
        case 3: zoneType = "Industrial0"; break;
        default:
            std::cout << "\033[1;31mInvalid zone type!\033[0m\n";
            return;
    }

    Location topLeft, bottomRight;
    std::cout << "Enter top-left corner coordinates (x y): ";
    if (!(std::cin >> topLeft.x >> topLeft.y)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\033[1;31mInvalid coordinates!\033[0m\n";
        return;
    }

    std::cout << "Enter bottom-right corner coordinates (x y): ";
    if (!(std::cin >> bottomRight.x >> bottomRight.y)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\033[1;31mInvalid coordinates!\033[0m\n";
        return;
    }

    // Use grid's createZone method instead of direct manipulation
    if (grid.createZone(topLeft, bottomRight, zoneType)) {
        std::cout << "\033[1;32mZone created successfully!\033[0m\n";
    }
}

    void showZoneInfo() {
        Location loc;
        std::cout << "Enter coordinates to check zone (x y): ";
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

        auto zone = grid.getZone(loc);
        if (zone) {
            std::cout << "\nZone Information:\n"
                    << "Type: " << zone->getBuildingType() << "\n";
            zone->displayStatus();
        } else {
            std::cout << "\033[1;33mNo zone at this location.\033[0m\n";
        }
        
        std::cout << "\nPress Enter to continue...";
        std::cin.get();
    }


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

        // Check money before asking for location
        int cost = 0;
        switch (choice) {
            case 1: cost = 100; break;
            case 2: cost = 200; break;
            case 3: cost = 300; break;
            default: 
                std::cout << "\033[1;31mInvalid choice!\033[0m\n";
                return;
        }

        if (state.getMoney() < cost) {
            std::cout << "\033[1;31mNot enough money! Need $" << cost << "\033[0m\n";
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

        auto zone = grid.getZone(loc);
        if (zone) {
            std::string zoneType = zone->getBuildingType();
            bool compatible = false;
            
            // Check if building type matches zone type
            switch(choice) {
                case 1: // House
                    compatible = (zoneType == "Residential");
                    break;
                case 2: // Commercial
                    compatible = (zoneType == "Commercial");
                    break;
                case 3: // Industrial
                    compatible = (zoneType == "Industrial");
                    break;
            }

            if (!compatible) {
                std::cout << "\033[1;31mBuilding type not allowed in this zone!\033[0m\n";
                return;
            }
        }

        if (!grid.isValidLocation(loc)) {
            std::cout << "\033[1;31mInvalid location!\033[0m\n";
            return;
        }

        if (grid.getComponent(loc)) {
            std::cout << "\033[1;31mLocation already occupied!\033[0m\n";
            return;
        }

        std::shared_ptr<CityComponent> building;
        switch (choice) {
            case 1: building = std::make_shared<House>(); break;
            case 2: building = std::make_shared<CommercialBuilding>(); break;
            case 3: building = std::make_shared<Industry>(); break;
            default: 
                std::cout << "\033[1;31mInvalid choice!\033[0m\n";
                return;
        }

        // Use MapGrid's validation
        auto result = grid.canPlaceBuilding(loc, building);
        if (!result.success) {
            std::cout << "\033[1;31m" << result.message << "\033[0m\n";
            return;
        }

        if (!state.spendMoney(cost)) {
            std::cout << "\033[1;31mTransaction failed!\033[0m\n";
            return;
        }

        // Use PlaceComponent which now includes validation
        auto command = std::make_unique<PlaceComponentCommand>(grid, loc, building);
        state.executeCommand(std::move(command));
        std::cout << "\033[1;32mBuilding placed successfully!\033[0m\n";
    }

void handlePlaceUtility() {
    UtilityFactory factory;

    std::cout << "\nSelect utility type:\n";
    for(int i = 1; i <= 4; i++) {
        std::cout << i << ". " << UtilityFactory::getUtilityName(i) 
                  << " ($" << UtilityFactory::getUtilityCost(i) << ")\n";
    }
    std::cout << "Choice: ";

    int choice;
    if (!(std::cin >> choice)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\033[1;31mInvalid input!\033[0m\n";
        return;
    }

    try {
        auto utility = factory.getUtilityByType(choice);
        if (state.getMoney() < utility->getCost()) {
            std::cout << "\033[1;31mNot enough money! Need $" 
                      << utility->getCost() << "\033[0m\n";
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

        // Check if placement is valid
        auto result = grid.canPlaceBuilding(loc, utility);
        if (!result.success) {
            std::cout << "\033[1;31m" << result.message << "\033[0m\n";
            return;
        }

        if (!state.spendMoney(utility->getCost())) {
            std::cout << "\033[1;31mTransaction failed!\033[0m\n";
            return;
        }

        auto command = std::make_unique<PlaceComponentCommand>(grid, loc, utility);
        state.executeCommand(std::move(command));
        
        // Add utility effect to surrounding cells
        int radius = utility->getRadius();
        for (int y = loc.y - radius; y <= loc.y + radius; y++) {
            for (int x = loc.x - radius; x <= loc.x + radius; x++) {
                Location affectedLoc{x, y};
                if (grid.isValidLocation(affectedLoc)) {
                    grid.addUtilityEffect(affectedLoc, utility);
                }
            }
        }

        std::cout << "\033[1;32m" << utility->getName() 
                  << " placed successfully!\033[0m\n";
    }
    catch (const std::out_of_range& e) {
        std::cout << "\033[1;31mInvalid choice!\033[0m\n";
    }
}

    void showTooltip(const Location& loc) {
        auto zone = grid.getZone(loc);
        if (zone) {
            std::cout << "\nZone Type: " << zone->getBuildingType() 
                      << "\nAllowed Buildings: ";
            if (zone->getBuildingType() == "Residential")
                std::cout << "Houses, Apartments";
            else if (zone->getBuildingType() == "Commercial")
                std::cout << "Shops, Offices";
            else if (zone->getBuildingType() == "Industrial")
                std::cout << "Factories, Warehouses";
            std::cout << "\n";
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

            try {
                switch (choice) {
                    case 1: handleBuildStructure(); break;
                    case 2: handlePlaceUtility(); break;
                    case 3: showStatistics(); break;
                    case 4: handleCreateZone(); break;
                    case 5: showZoneInfo(); break;
                    case 6: state.undo(); break;
                    case 7: state.redo(); break;
                    case 0: running = false; break;
                    default: std::cout << "\033[1;31mInvalid choice!\033[0m\n";
                }
            } catch (const std::exception& e) {
                std::cout << "\033[1;31mError: " << e.what() << "\033[0m\n";
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