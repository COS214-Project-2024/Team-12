// main.cpp
#include "GameState.h"  // Add this first to resolve incomplete type error
#include "MapGrid.h"
#include "CityComponent.h"
#include "ResidentialBuilding.h"
#include "Flat.h"
#include "Townhouse.h"
#include "Estate.h"
#include "CommercialBuilding.h"
#include "Shops.h"
#include "Office.h"
#include "Malls.h"
// #include "MetalWorkFacility.h"
// #include "PetroChemicalFacility.h"
// #include "CrystalCraftIndustry.h"
// #include "WoodAndCoalPlant.h"
 #include "LandMark.h"
 #include "Park.h"
 #include "Monument.h"
 #include "CulturalCenter.h"
#include "Industry.h"
#include "House.h"
#include "UtilityFlyweight.h"
#include "UtilityFactory.h"
#include "WaterSupply.h"
#include "PowerPlant.h"
#include "SewageSystem.h"
#include "WasteManagement.h"
#include "ConcreteTaxCollector.h"
#include "taxCollector.h"
#include "NPCManager.h"
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <limits>


#include "Roads.h"
#include "RoadsFactory.h"
#include "Trains.h"
#include "TrainsFactory.h"

class CityGame {
private:
    MapGrid grid;
    GameState state;    // Now only handles command history
    bool running = true;

    // References to singletons
    Government& government = Government::getInstance();
    NPCManager& npcManager = NPCManager::getInstance();

void displayMenu() {
    std::cout << "\n\033[1;36m=== City Builder ===\033[0m\n"
              << "Money: $" << government.getMoney() 
              << " | Happiness: " << npcManager.getHappinessLevel() << "%\n"
              << "Population: " << government.getPopulation() 
              << " | Crime Rate: " << government.getCrimeRate() * 100 << "%\n\n"
              << "1. Build Structure\n"
              << "2. Place Utility\n"
              << "3. Show Statistics\n"
              << "4. Create Zone\n"
              << "5. Show Zone Info\n"
              << "6. Undo\n"
              << "7. Redo\n"
              << "8. Collect Taxes\n"
              << "9. Place Transport Link\n"  // New option for transport
              << "0. Exit\n"
              << "\nChoice: ";
}




void handlePlaceTransport() {
    int x1, y1, x2, y2;
    char transportType;
    int roadCost = 65;
    int trainCost = 85;
    int linkCost = 0;

    std::cout << "\nEnter start coordinates (x1 y1): ";
    if (!(std::cin >> x1 >> y1)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\033[1;31mInvalid coordinates!\033[0m\n";
        return;
    }

    std::cout << "Enter end coordinates (x2 y2): ";
    if (!(std::cin >> x2 >> y2)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\033[1;31mInvalid coordinates!\033[0m\n";
        return;
    }

    std::cout << "Enter transport type (R for Road, T for Train): ";
    std::cin >> transportType;

    // Determine cost per link based on transport type
    if (transportType == 'R') {
        linkCost = roadCost;
    } else if (transportType == 'T') {
        linkCost = trainCost;
    } else {
        std::cout << "\033[1;31mInvalid transport type!\033[0m\n";
        return;
    }

    // Check if there's enough money to place start and end points
    if (government.getMoney() < 2 * linkCost) {
        std::cout << "\033[1;31mNot enough money to place transport endpoints!\033[0m\n";
        return;
    }

    // Deduct money for start and end points
    government.reduceMoney(linkCost);
    grid.setTransportEndpoint({x1, y1}, transportType);
    government.reduceMoney(linkCost);
    grid.setTransportEndpoint({x2, y2}, transportType);

    // Determine path direction and fill with symbols, deducting money for each link
    if (x1 == x2) { // Vertical path
        for (int y = std::min(y1, y2) + 1; y < std::max(y1, y2); ++y) {
            if (government.getMoney() < linkCost) {
                std::cout << "\033[1;31mNot enough money to complete transport link!\033[0m\n";
                return;
            }
            government.reduceMoney(linkCost);
            grid.setTransportPath({x1, y}, '|');
        }
    } else if (y1 == y2) { // Horizontal path
        for (int x = std::min(x1, x2) + 1; x < std::max(x1, x2); ++x) {
            if (government.getMoney() < linkCost) {
                std::cout << "\033[1;31mNot enough money to complete transport link!\033[0m\n";
                return;
            }
            government.reduceMoney(linkCost);
            grid.setTransportPath({x, y1}, '-');
        }
    } else { // Diagonal or other complex path
        int dx = (x2 > x1) ? 1 : -1;
        int dy = (y2 > y1) ? 1 : -1;
        int x = x1 + dx, y = y1 + dy;
        while (x != x2 && y != y2) {
            if (government.getMoney() < linkCost) {
                std::cout << "\033[1;31mNot enough money to complete transport link!\033[0m\n";
                return;
            }
            government.reduceMoney(linkCost);
            grid.setTransportPath({x, y}, '+');
            x += dx;
            y += dy;
        }
    }

    std::cout << "\033[1;32mTransport link created successfully!\033[0m\n";
}







    void showStatistics() {
        std::cout << "\n=== City Statistics ===\n";
        government.displayGovernmentStats();
        std::cout << "\nNPC States:\n"
                << "Happy Citizens: " << npcManager.getDonationCount() << "\n"
                << "Neutral Citizens: " << npcManager.getNeutralCount() << "\n"
                << "Revolting Citizens: " << npcManager.getRevoltCount() << "\n"
                << "Productive Citizens: " << npcManager.getProductiveCount() << "\n"
                << "Criminal Citizens: " << npcManager.getCrimeCount() << "\n"
                << "\nDominant State: " << npcManager.getHighestState() << "\n"
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
    std::cout << "\nSelect building category:\n"
              << "1. Residential Buildings\n"
              << "2. Commercial Buildings\n"
              << "3. Public Services\n"
               << "4. Landmarks\n"
              << "Choice: ";
    
    int categoryChoice;
    if (!(std::cin >> categoryChoice)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\033[1;31mInvalid input!\033[0m\n";
        return;
    }

    // Initialize variables for building selection
    std::shared_ptr<CityComponent> building;
    int cost = 0;
    std::string buildingType;

    // Handle subcategories based on main category
    switch(categoryChoice) {
        case 1: // Residential
            std::cout << "\nSelect Residential building type:\n"
                      << "1. House ($100)\n"
                      << "2. Flat ($150)\n"
                      << "3. Townhouse ($200)\n"
                      << "4. Estate ($300)\n"
                      << "Choice: ";
            int resChoice;
            std::cin >> resChoice;
            switch(resChoice) {
                case 1: building = std::make_shared<House>(); cost = 100; buildingType = "House"; break;
                case 2: building = std::make_shared<Flat>(); cost = 150; buildingType = "Flat"; break;
                case 3: building = std::make_shared<Townhouse>(); cost = 200; buildingType = "Townhouse"; break;
                case 4: building = std::make_shared<Estate>(); cost = 300; buildingType = "Estate"; break;
                default: 
                    std::cout << "\033[1;31mInvalid residential building type!\033[0m\n";
                    return;
            }
            break;

        case 2: // Commercial
            std::cout << "\nSelect Commercial building type:\n"
                      << "1. Shop ($200)\n"
                      << "2. Mall ($400)\n"
                      << "3. Office ($600)\n"
                      << "Choice: ";
            int comChoice;
            std::cin >> comChoice;
            switch(comChoice) {
                case 1: building = std::make_shared<Shops>(); cost = 200; buildingType = "Shop"; break;
                case 2: building = std::make_shared<Malls>(); cost = 400; buildingType = "Mall"; break;
                case 3: building = std::make_shared<Office>(); cost = 600; buildingType = "Office"; break;
                default:
                    std::cout << "\033[1;31mInvalid commercial building type!\033[0m\n";
                    return;
            }
            break;

        case 3: // Public Services
            std::cout << "\nSelect Public Service type:\n"
                      << "1. Fire Station ($500)\n"
                      << "2. Hospital ($700)\n"
                      << "3. Police Station ($600)\n"
                      << "Choice: ";
            int pubServChoice;
            std::cin >> pubServChoice;
            switch(pubServChoice) {
                case 1: building = std::make_shared<FireStation>(nullptr, nullptr, nullptr, nullptr, "Operational"); cost = 500; buildingType = "Fire Station"; break;
                case 2: building = std::make_shared<Hospital>(nullptr, nullptr, nullptr, nullptr, "Operational"); cost = 700; buildingType = "Hospital"; break;
                case 3: building = std::make_shared<PoliceStation>(nullptr, nullptr, nullptr, nullptr, "Operational"); cost = 600; buildingType = "Police Station"; break;
                default:
                    std::cout << "\033[1;31mInvalid public service type!\033[0m\n";
                    return;
            }
            break;
         case 4: { // Landmarks
            std::cout << "\nSelect Landmark type:\n"
                      << "1. Monument ($500)\n"
                      << "2. Cultural Center ($700)\n"
                      << "3. Park ($300)\n"
                      << "Choice: ";
            int landChoice;
            std::cin >> landChoice;

            switch(landChoice) {
                case 1:
                    building = std::make_shared<Monument>("Monument", 100, 500,
                        nullptr, nullptr, 
                        nullptr, nullptr);
                    cost = 500; buildingType = "Monument";
                    break;
                case 2:
                    building = std::make_shared<CulturalCenter>("Cultural Center", 200, 700,
                        nullptr, nullptr, 
                        nullptr, nullptr);
                    cost = 700; buildingType = "Cultural Center";
                    break;
                case 3:
                    building = std::make_shared<Park>("Park", 150, 300,
                        nullptr, nullptr, 
                        nullptr, nullptr);
                    cost = 300; buildingType = "Park";
                    break;
                default:
                    std::cout << "\033[1;31mInvalid landmark type!\033[0m\n";
                    return;
            }
            break;
        }
        

        default:
            std::cout << "\033[1;31mInvalid building category!\033[0m\n";
            return;
    }

    // Check money
    if (government.getMoney() < cost) {
        std::cout << "\033[1;31mNot enough money! Need $" << cost << "\033[0m\n";
        return;
    }

    // Get location
    Location loc;
    std::cout << "Enter location (x y): ";
    if (!(std::cin >> loc.x >> loc.y)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\033[1;31mInvalid coordinates!\033[0m\n";
        return;
    }

    // Check zone compatibility
    auto zone = grid.getZone(loc);
    if (zone) {
        std::string zoneType = zone->getBuildingType();
        bool compatible = false;
        
        switch(categoryChoice) {
            case 1: compatible = (zoneType == "Residential"); break;
            case 2: compatible = (zoneType == "Commercial"); break;
            case 3: compatible = true; break; // Public Services can be placed anywhere
            case 4: compatible = true; // Landmarks can be placed anywhere
        }

        if (!compatible) {
            std::cout << "\033[1;31mBuilding type not allowed in this zone!\033[0m\n";
            return;
        }
    }

    // Validate location and placement
    if (!grid.isValidLocation(loc)) {
        std::cout << "\033[1;31mInvalid location!\033[0m\n";
        return;
    }

    if (grid.getComponent(loc)) {
        std::cout << "\033[1;31mLocation already occupied!\033[0m\n";
        return;
    }

    // Use MapGrid's validation
    auto result = grid.canPlaceBuilding(loc, building);
    if (!result.success) {
        std::cout << "\033[1;31m" << result.message << "\033[0m\n";
        return;
    }

    // Process payment and place building
    government.reduceMoney(cost);

    switch(categoryChoice) {
        case 1: government.setBuildingAmount("Residential", 1); break;
        case 2: government.setBuildingAmount("Commercial", 1); break;
        case 3: government.setBuildingAmount("PublicService", 1); break;
        case 4: government.setBuildingAmount("Landmark", 1); break;
    }

    auto command = std::make_unique<PlaceComponentCommand>(grid, loc, building);
    state.executeCommand(std::move(command));
    std::cout << "\033[1;32m" << buildingType << " placed successfully!\033[0m\n";
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
        if (government.getMoney() < utility->getCost()) {
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

        // Process payment using Government
        government.reduceMoney(utility->getCost());
        
        // Update utility count
        government.setBuildingAmount("Utility", 1);

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
                std::cout << "Houses, Flats";
            else if (zone->getBuildingType() == "Commercial")
                std::cout << "Shops, Offices";
            else if (zone->getBuildingType() == "Industrial")
                std::cout << "Factories, Warehouses";
            std::cout << "\n";
        }
    }

    void collectTaxes() {
        auto& government = Government::getInstance();
        ConcreteTaxCollector collector;
    
        // First collect taxes from all buildings on the grid, zoned or not
        for (int y = 0; y < grid.getHeight(); y++) {
            for (int x = 0; x < grid.getWidth(); x++) {
                if (auto building = grid.getComponent({x, y})) {
                    if (auto residential = std::dynamic_pointer_cast<ResidentialBuilding>(building)) {
                        collector.visit(residential.get());
                    }
                    else if (auto commercial = std::dynamic_pointer_cast<CommercialBuilding>(building)) {
                        collector.visit(commercial.get());
                    }
                }
            }
        }

        std::cout << "\033[1;32mTaxes collected successfully!\033[0m\n";
        std::cout << "Government funds: $" << government.getMoney() << "\n";
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
                case 8: collectTaxes(); break;
                case 9: handlePlaceTransport(); break;  // New case for transport
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