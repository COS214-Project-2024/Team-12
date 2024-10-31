
// GridMapTest.cpp
#include "CityComponent.h"
#include "CityComposite.h"
#include "ResidentialBuilding.h"
#include "CommercialBuilding.h"
#include "Industry.h"
#include "House.h"
#include "Flat.h"
#include "Townhouse.h"
#include "Estate.h"
#include "UtilityFlyweight.h"
#include "UtilityFactory.h"
#include "WaterSupply.h"
#include "PowerPlant.h"
#include "SewageSystem.h"
#include "WasteManagement.h"
#include "UtilityDecorator.h"
#include "AdvancedTechnologyDecorator.h"
#include "GreenTechnologyDecorator.h"
#include "MapGrid.h"
#include <iostream>
#include <memory>
#include <cmath>
#include <cassert>
#include <iomanip>
#include <limits>
#include <cmath>

void displayGrid(const MapGrid& grid, int width, int height) {
    std::cout << "\nCity Grid Layout:\n";
    
    // Print top border of grid
    std::cout << "   ";  // Space for row numbers
    for(int x = 0; x < width; x++) {
        std::cout << std::setw(2) << x << " ";
    }
    std::cout << "\n";

    // Print each row
    for(int y = 0; y < height; y++) {
        // Print row number
        std::cout << std::setw(2) << y << " ";
        
        // Print top line of cells in this row
        for(int x = 0; x < width; x++) {
            std::cout << "+---";
        }
        std::cout << "+\n";

        // Print row number again
        std::cout << "   ";
        
        // Print cell contents
        for(int x = 0; x < width; x++) {
            std::cout << "|";
            Node* node = grid.getNode(x, y);
            if(node && node->getComponent()) {
                if(dynamic_cast<UtilityFlyweight*>(node->getComponent())) {
                    std::cout << " U ";
                } else if(dynamic_cast<House*>(node->getComponent())) {
                    std::cout << " H ";
                } else {
                    std::cout << " ? ";
                }
            } else {
                std::cout << "   ";
            }
        }
        std::cout << "|\n";
    }

    // Print bottom border of last row
    std::cout << "   ";
    for(int x = 0; x < width; x++) {
        std::cout << "+---";
    }
    std::cout << "+\n";

    // Print legend
    std::cout << "\nLegend:\n"
              << "U = Utility\n"
              << "H = House\n"
              << "  = Empty\n";
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void displayMenu() {
    std::cout << "\n=== City Building Menu ===\n"
              << "1. Place House\n"
              << "2. Place Utility\n"
              << "3. Show Utility Coverage\n"
              << "4. Display Grid\n"
              << "5. Show Statistics\n"
              << "0. Exit\n"
              << "Enter choice: ";
}

void displayUtilityCoverage(const MapGrid& grid, int width, int height, const std::vector<std::shared_ptr<UtilityFlyweight>>& utilities) {
    std::cout << "\nUtility Coverage Map:\n";
    std::cout << "Legend: . = Empty, U = Utility, H = House\n";
    std::cout << "       * = In range of utility, # = Multiple utility coverage\n\n";

    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            int coverage = 0;
            Node* node = grid.getNode(x, y);
            
            // Check if this location is within range of any utility
            for(const auto& utility : utilities) {
                Location utilityLoc = utility->getLocation();
                double distance = std::sqrt(
                    std::pow(x - utilityLoc.x, 2) + 
                    std::pow(y - utilityLoc.y, 2)
                );
                if(distance <= utility->getEffectRadius()) {
                    coverage++;
                }
            }

            if(node && node->getComponent()) {
                if(dynamic_cast<UtilityFlyweight*>(node->getComponent())) {
                    std::cout << "U";
                } else if(dynamic_cast<House*>(node->getComponent())) {
                    std::cout << "H";
                }
            } else if(coverage > 1) {
                std::cout << "#";
            } else if(coverage == 1) {
                std::cout << "*";
            } else {
                std::cout << ".";
            }
            std::cout << " ";
        }
        std::cout << "\n";
    }
}

void showStatistics(const MapGrid& grid, int width, int height, 
                   const std::vector<std::shared_ptr<UtilityFlyweight>>& utilities) {
    int houseCount = 0;
    int utilityCount = utilities.size();
    int coveredHouses = 0;

    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            Node* node = grid.getNode(x, y);
            if(node && node->getComponent()) {
                if(auto house = dynamic_cast<House*>(node->getComponent())) {
                    houseCount++;
                    // Check if house is covered by any utility
                    bool isCovered = false;
                    for(const auto& utility : utilities) {
                        Location utilityLoc = utility->getLocation();
                        double distance = std::sqrt(
                            std::pow(x - utilityLoc.x, 2) + 
                            std::pow(y - utilityLoc.y, 2)
                        );
                        if(distance <= utility->getEffectRadius()) {
                            isCovered = true;
                            break;
                        }
                    }
                    if(isCovered) coveredHouses++;
                }
            }
        }
    }

    std::cout << "\n=== City Statistics ===\n"
              << "Houses built: " << houseCount << "\n"
              << "Utilities placed: " << utilityCount << "\n"
              << "Houses with utility coverage: " << coveredHouses << "\n"
              << "Houses without coverage: " << (houseCount - coveredHouses) << "\n"
              << "Coverage ratio: " << (houseCount > 0 ? (coveredHouses * 100.0 / houseCount) : 0)
              << "%\n";
}

void cityBuildingGame() {
    const int WIDTH = 10;
    const int HEIGHT = 10;
    MapGrid cityMap(WIDTH, HEIGHT);
    UtilityFactory factory;
    std::vector<std::shared_ptr<UtilityFlyweight>> utilities;
    
    bool running = true;
    while(running) {
        clearScreen();
        displayGrid(cityMap, WIDTH, HEIGHT);
        displayMenu();
        
        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch(choice) {
            case 1: { // Place House
                int x, y;
                std::cout << "Enter coordinates (x y): ";
                std::cin >> x >> y;
                
                if(x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
                    auto house = new House();
                    cityMap.placeComponent(house, x, y);
                } else {
                    std::cout << "Invalid coordinates!\n";
                }
                break;
            }
            
            case 2: { // Place Utility
                int x, y;
                std::cout << "Enter coordinates (x y): ";
                std::cin >> x >> y;
                
                if(x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
                    auto utility = factory.getUtility("WaterSupply");
                    cityMap.placeComponent(utility.get(), x, y);
                    utilities.push_back(utility);
                } else {
                    std::cout << "Invalid coordinates!\n";
                }
                break;
            }
            
            case 3: // Show Coverage
                displayUtilityCoverage(cityMap, WIDTH, HEIGHT, utilities);
                std::cout << "\nPress Enter to continue...";
                std::cin.get();
                break;
                
            case 4: // Display Grid
                displayGrid(cityMap, WIDTH, HEIGHT);
                std::cout << "\nPress Enter to continue...";
                std::cin.get();
                break;
                
            case 5: // Show Statistics
                showStatistics(cityMap, WIDTH, HEIGHT, utilities);
                std::cout << "\nPress Enter to continue...";
                std::cin.get();
                break;
                
            case 0: // Exit
                running = false;
                break;
                
            default:
                std::cout << "Invalid choice!\n";
                break;
        }
    }
}

int main() {
    try {
        cityBuildingGame();
    } catch (const std::exception& e) {
        std::cout << "Game crashed: " << e.what() << std::endl;
    }
    return 0;
}