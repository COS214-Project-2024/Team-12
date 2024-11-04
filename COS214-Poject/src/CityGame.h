// CityGame.h
#ifndef CITYGAME_H
#define CITYGAME_H

#include "GameState.h"
#include "MapGrid.h"
#include "CityComponent.h"
#include "ResidentialBuilding.h"
#include "House.h"
#include "Flat.h"
#include "Townhouse.h"
#include "Estate.h"
#include "CommercialBuilding.h"
#include "Shops.h"
#include "Office.h"
#include "Malls.h"
#include "Industry.h"
#include "MetalWorkFacility.h"
#include "PetroChemicalFacility.h"
#include "CrystalCraftIndustry.h"
#include "WoodAndCoalPlant.h"
#include "LandMark.h"
#include "Park.h"
#include "Monument.h"
#include "CulturalCenter.h"
#include "UtilityFlyweight.h"
#include "UtilityFactory.h"
#include "WaterSupply.h"
#include "PowerPlant.h"
#include "SewageSystem.h"
#include "WasteManagement.h"
#include "ConcreteTaxCollector.h"
#include "TaxCollector.h"
#include "NPCManager.h"
#include "Gold.h"
#include "Diamonds.h"
#include "Coal.h"
#include "Oil.h"
#include "Stone.h"
#include "Wood.h"
#include "Steel.h"
#include "Concrete.h"
#include "IncomeResourceProduct.h"
#include "ConstructionResourceProduct.h"
#include "IncomeResourceProcessor.h"
#include "ResourceProcessor.h"
#include "ConstructionResourceProcessor.h"
#include "BuildingRequirements.h"
#include "Roads.h"
#include "RoadsFactory.h"
#include "Trains.h"
#include "TrainsFactory.h"
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <limits>
#include <map>

class CityGame {
private:
    MapGrid grid;
    GameState state;
    bool running = true;

    // Resource Management
    std::map<Location, std::shared_ptr<IncomeResourceProduct>> incomeResourceMap;
    std::map<Location, std::shared_ptr<ConstructionResourceProduct>> constructionResourceMap;
    std::map<std::string, int> collectedResources;
    std::vector<std::shared_ptr<IncomeResourceProduct>> incomeResources;
    std::vector<std::shared_ptr<ConstructionResourceProduct>> constructionResources;

    // Save and Load
    std::vector<std::unique_ptr<GameStateMemento>> savedStates;
    size_t currentSaveIndex = 0;

    // Singleton References
    Government& government = Government::getInstance();
    NPCManager& npcManager = NPCManager::getInstance();

    // Initialization Methods
    void initializeResources() {
        // Income Resources
        incomeResources.push_back(std::make_shared<Gold>(100, 50.0));
        incomeResources.push_back(std::make_shared<Diamonds>(50, 100.0));
        incomeResources.push_back(std::make_shared<Coal>(200, 10.0));
        incomeResources.push_back(std::make_shared<Oil>(150, 30.0));

        // Construction Resources
        constructionResources.push_back(std::make_shared<Stone>(300, 5));
        constructionResources.push_back(std::make_shared<Wood>(400, 3));
        constructionResources.push_back(std::make_shared<Concrete>(400, 3));
        constructionResources.push_back(std::make_shared<Steel>(400, 3));
    }

    void initializeResourceSystem() {
        initializeCollectedResources(collectedResources);
    }

    void spawnResources() {
        // Income Resources
        spawnIncomeResource<Gold>(3, 20, 10.0);
        spawnIncomeResource<Diamonds>(2, 15, 15.0);
        spawnIncomeResource<Coal>(4, 50, 5.0);
        spawnIncomeResource<Oil>(3, 40, 8.0);

        // Construction Resources
        spawnConstructionResource<Stone>(5, 60, 2);
        spawnConstructionResource<Wood>(5, 80, 1);
        spawnConstructionResource<Concrete>(5, 60, 2);
        spawnConstructionResource<Steel>(5, 50, 3);
    }

    template<typename T>
    void spawnIncomeResource(int count, int quantity, double marketValue) {
        for (int i = 0; i < count; i++) {
            Location loc = grid.getRandomEmptyLocation();
            auto resource = std::make_shared<T>(quantity, marketValue);
            resource->setLocation(loc);
            grid.placeComponent(loc, resource);
            incomeResources.push_back(resource);
            incomeResourceMap[loc] = resource;
            // For debugging purposes, you may comment out the next line
            // std::cout << "Spawned " << resource->getName() << " at (" << loc.x << "," << loc.y << ")\n";
        }
    }

    template<typename T>
    void spawnConstructionResource(int count, int quantity, int unitCost) {
        for (int i = 0; i < count; i++) {
            Location loc = grid.getRandomEmptyLocation();
            auto resource = std::make_shared<T>(quantity, unitCost);
            resource->setLocation(loc);
            grid.placeComponent(loc, resource);
            constructionResources.push_back(resource);
            constructionResourceMap[loc] = resource;
            // For debugging purposes, you may comment out the next line
            // std::cout << "Spawned " << resource->getName() << " at (" << loc.x << "," << loc.y << ")\n";
        }
    }

    // Display Methods
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
                  << "9. Place Transport Link\n"
                  << "10. Process Resources\n"
                  << "11. Save Game\n"
                  << "12. Load Game\n"
                  << "0. Exit\n"
                  << "\nChoice: ";
    }

    void displayCollectedResources() const {
        std::cout << "\n=== Collected Resources ===\n";
        if (collectedResources.empty()) {
            std::cout << "No resources collected yet.\n";
        } else {
            for (const auto& [resourceName, quantity] : collectedResources) {
                std::cout << resourceName << ": " << quantity << "\n";
            }
        }
        std::cout << "===========================\n";
    }

    // Game Actions
    void handleSaveGame() {
        auto saveState = state.createMemento();
        savedStates.push_back(std::move(saveState));
        currentSaveIndex = savedStates.size() - 1;
        std::cout << "\033[1;32mGame saved successfully! Save #" << currentSaveIndex + 1 << "\033[0m\n";
    }

    void handleLoadGame() {
        if (savedStates.empty()) {
            std::cout << "\033[1;31mNo saved games found!\033[0m\n";
            return;
        }

        std::cout << "Available saves (1-" << savedStates.size() << "): ";
        int saveChoice;
        std::cin >> saveChoice;

        if (saveChoice < 1 || saveChoice > static_cast<int>(savedStates.size())) {
            std::cout << "\033[1;31mInvalid save number!\033[0m\n";
            return;
        }

        currentSaveIndex = saveChoice - 1;
        state.restoreFromMemento(*savedStates[currentSaveIndex]);
        std::cout << "\033[1;32mGame loaded successfully!\033[0m\n";
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

        switch (choice) {
            case 1: zoneType = "Residential"; break;
            case 2: zoneType = "Commercial"; break;
            case 3: zoneType = "Industrial"; break;
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

        // Use grid's createZone method
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
                  << "3. Industrial Buildings\n"
                  << "4. Public Services\n"
                  << "5. Landmarks\n"
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
        int indChoice = 0;

        // Handle subcategories based on main category
        switch (categoryChoice) {
            case 1: { // Residential
                std::cout << "\nSelect Residential building type:\n"
                          << "1. House ($100)\n"
                          << "2. Flat ($150)\n"
                          << "3. Townhouse ($200)\n"
                          << "4. Estate ($300)\n"
                          << "Choice: ";
                int resChoice;
                std::cin >> resChoice;
                switch (resChoice) {
                    case 1:
                        building = std::make_shared<House>();
                        cost = 100;
                        buildingType = "House";
                        break;
                    case 2:
                        building = std::make_shared<Flat>();
                        cost = 150;
                        buildingType = "Flat";
                        break;
                    case 3:
                        building = std::make_shared<Townhouse>();
                        cost = 200;
                        buildingType = "Townhouse";
                        break;
                    case 4:
                        building = std::make_shared<Estate>();
                        cost = 300;
                        buildingType = "Estate";
                        break;
                    default:
                        std::cout << "\033[1;31mInvalid residential building type!\033[0m\n";
                        return;
                }
                break;
            }
            case 2: { // Commercial
                std::cout << "\nSelect Commercial building type:\n"
                          << "1. Shop ($200)\n"
                          << "2. Mall ($400)\n"
                          << "3. Office ($600)\n"
                          << "Choice: ";
                int comChoice;
                std::cin >> comChoice;
                switch (comChoice) {
                    case 1:
                        building = std::make_shared<Shops>();
                        cost = 200;
                        buildingType = "Shop";
                        break;
                    case 2:
                        building = std::make_shared<Malls>();
                        cost = 400;
                        buildingType = "Mall";
                        break;
                    case 3:
                        building = std::make_shared<Office>();
                        cost = 600;
                        buildingType = "Office";
                        break;
                    default:
                        std::cout << "\033[1;31mInvalid commercial building type!\033[0m\n";
                        return;
                }
                break;
            }
            case 3: { // Industrial
                std::cout << "\nSelect Industrial building type:\n"
                          << "1. Metal Work Facility ($300)\n"
                          << "2. Petrochemical Factory ($400)\n"
                          << "3. Crystal Craft Industry ($350)\n"
                          << "4. Wood and Coal Plant ($300)\n"
                          << "Choice: ";
                std::cin >> indChoice;
                switch (indChoice) {
                    case 1:
                        cost = 300;
                        buildingType = "MetalWorkFacility";
                        break;
                    case 2:
                        cost = 400;
                        buildingType = "PetroChemical";
                        break;
                    case 3:
                        cost = 350;
                        buildingType = "CrystalCraft";
                        break;
                    case 4:
                        cost = 300;
                        buildingType = "WoodAndCoal";
                        break;
                    default:
                        std::cout << "\033[1;31mInvalid industrial building type!\033[0m\n";
                        return;
                }
                break;
            }
            case 4: { // Public Services
                std::cout << "\nSelect Public Service type:\n"
                          << "1. Fire Station ($500)\n"
                          << "2. Hospital ($700)\n"
                          << "3. Police Station ($600)\n"
                          << "Choice: ";
                int pubServChoice;
                std::cin >> pubServChoice;
                switch (pubServChoice) {
                    case 1:
                        building = std::make_shared<FireStation>(nullptr, nullptr, nullptr, nullptr, "Operational");
                        cost = 500;
                        buildingType = "Fire Station";
                        break;
                    case 2:
                        building = std::make_shared<Hospital>(nullptr, nullptr, nullptr, nullptr, "Operational");
                        cost = 700;
                        buildingType = "Hospital";
                        break;
                    case 3:
                        building = std::make_shared<PoliceStation>(nullptr, nullptr, nullptr, nullptr, "Operational");
                        cost = 600;
                        buildingType = "Police Station";
                        break;
                    default:
                        std::cout << "\033[1;31mInvalid public service type!\033[0m\n";
                        return;
                }
                break;
            }
            case 5: { // Landmarks
                std::cout << "\nSelect Landmark type:\n"
                          << "1. Monument ($500)\n"
                          << "2. Cultural Center ($700)\n"
                          << "3. Park ($300)\n"
                          << "Choice: ";
                int landChoice;
                std::cin >> landChoice;

                switch (landChoice) {
                    case 1:
                        building = std::make_shared<Monument>("Monument", 100, 500,
                                                              nullptr, nullptr,
                                                              nullptr, nullptr);
                        cost = 500;
                        buildingType = "Monument";
                        break;
                    case 2:
                        building = std::make_shared<CulturalCenter>("Cultural Center", 200, 700,
                                                                    nullptr, nullptr,
                                                                    nullptr, nullptr);
                        cost = 700;
                        buildingType = "Cultural Center";
                        break;
                    case 3:
                        building = std::make_shared<Park>("Park", 150, 300,
                                                          nullptr, nullptr,
                                                          nullptr, nullptr);
                        cost = 300;
                        buildingType = "Park";
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

        displayCollectedResources();

        // Offer Choice Between Resources or Money
        std::cout << "Do you want to build using resources or money?\n"
                  << "1. Resources\n"
                  << "2. Money\n"
                  << "Choice: ";
        int paymentChoice;
        std::cin >> paymentChoice;

        bool paymentSuccess = false;

        if (paymentChoice == 1) {
            // Use resources
            if (!hasRequiredResources(buildingType)) {
                std::cout << "\033[1;31mNot enough resources to build a " << buildingType << "!\033[0m\n";
                return;
            }
            // Deduct resources
            consumeResources(buildingType);
            paymentSuccess = true;
            std::cout << "\033[1;32m" << buildingType << " will be built using resources!\033[0m\n";
        } else if (paymentChoice == 2) {
            // Use money
            if (government.getMoney() < cost) {
                std::cout << "\033[1;31mNot enough money! Need $" << cost << "\033[0m\n";
                return;
            }
            government.reduceMoney(cost);
            paymentSuccess = true;
            std::cout << "\033[1;32m" << buildingType << " will be built using money!\033[0m\n";
        } else {
            std::cout << "\033[1;31mInvalid payment choice!\033[0m\n";
            return;
        }

        // Proceed only if payment was successful
        if (!paymentSuccess) {
            return;
        }

        // Get Location to Place the Building
        Location placeLoc;
        std::cout << "Enter location to place the building (x y): ";
        if (!(std::cin >> placeLoc.x >> placeLoc.y)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\033[1;31mInvalid coordinates!\033[0m\n";
            return;
        }

        // For Industrial Buildings, Handle Resource Assignment and Building Creation
        if (categoryChoice == 3) {
            switch (indChoice) {
                case 1: { // Metal Work Facility
                    // Find closest resources
                    auto [goldResource, goldLoc] = findClosestResource<Gold>(placeLoc);
                    auto [steelResource, steelLoc] = findClosestResource<Steel>(placeLoc);

                    const int collectionRange = MetalWorkFacility::METAL_WORK_RANGE;

                    if (!goldResource || !steelResource) {
                        std::cout << "\033[1;31mRequired resources not found nearby!\033[0m\n";
                        return;
                    }

                    building = std::make_shared<MetalWorkFacility>(goldResource, steelResource, &grid, collectedResources);
                    break;
                }
                case 2: { // Petrochemical Factory
                    auto [oilResource, oilLoc] = findClosestResource<Oil>(placeLoc);
                    auto [concreteResource, concreteLoc] = findClosestResource<Concrete>(placeLoc);

                    const int collectionRange = PetrochemicalFacility::PETRO_CHEMICAL_RANGE;

                    if (!oilResource || !concreteResource) {
                        std::cout << "\033[1;31mRequired resources not found nearby!\033[0m\n";
                        return;
                    }

                    building = std::make_shared<PetrochemicalFacility>(oilResource, concreteResource, &grid, collectedResources);
                    break;
                }
                case 3: { // Crystal Craft Industry
                    auto [diamondResource, diamondLoc] = findClosestResource<Diamonds>(placeLoc);
                    auto [stoneResource, stoneLoc] = findClosestResource<Stone>(placeLoc);

                    const int collectionRange = CrystalCraftIndustry::CRYSTAL_CRAFT_RANGE;

                    if (!diamondResource || !stoneResource) {
                        std::cout << "\033[1;31mRequired resources not found nearby!\033[0m\n";
                        return;
                    }

                    building = std::make_shared<CrystalCraftIndustry>(diamondResource, stoneResource, &grid, collectedResources);
                    break;
                }
                case 4: { // Wood and Coal Plant
                    auto [coalResource, coalLoc] = findClosestResource<Coal>(placeLoc);
                    auto [woodResource, woodLoc] = findClosestResource<Wood>(placeLoc);

                    const int collectionRange = WoodAndCoalPlant::WOOD_COAL_RANGE;

                    if (!coalResource || !woodResource) {
                        std::cout << "\033[1;31mRequired resources not found nearby!\033[0m\n";
                        return;
                    }

                    building = std::make_shared<WoodAndCoalPlant>(coalResource, woodResource, &grid, collectedResources);
                    break;
                }
                default:
                    std::cout << "\033[1;31mInvalid industrial building type!\033[0m\n";
                    return;
            }
        }

        // Check Zone Compatibility
        auto zone = grid.getZone(placeLoc);
        if (zone) {
            std::string zoneType = zone->getBuildingType();
            bool compatible = false;

            switch (categoryChoice) {
                case 1:
                    compatible = (zoneType == "Residential");
                    break;
                case 2:
                    compatible = (zoneType == "Commercial");
                    break;
                case 3:
                    compatible = (zoneType == "Industrial");
                    break;
                case 4:
                case 5:
                    compatible = true; // Public Services and Landmarks can be placed anywhere
                    break;
            }

            if (!compatible) {
                std::cout << "\033[1;31mBuilding type not allowed in this zone!\033[0m\n";
                return;
            }
        }

        // Validate Location and Placement
        if (!grid.isValidLocation(placeLoc)) {
            std::cout << "\033[1;31mInvalid location!\033[0m\n";
            return;
        }

        if (grid.getComponent(placeLoc)) {
            std::cout << "\033[1;31mLocation already occupied!\033[0m\n";
            return;
        }

        // Use MapGrid's Validation
        auto result = grid.canPlaceBuilding(placeLoc, building);
        if (!result.success) {
            std::cout << "\033[1;31m" << result.message << "\033[0m\n";
            return;
        }

        // Update Government Building Count
        switch (categoryChoice) {
            case 1:
                government.setBuildingAmount("Residential", 1);
                break;
            case 2:
                government.setBuildingAmount("Commercial", 1);
                break;
            case 3:
                government.setBuildingAmount("Industrial", 1);
                break;
            case 4:
                government.setBuildingAmount("PublicService", 1);
                break;
            case 5:
                government.setBuildingAmount("Landmark", 1);
                break;
        }

        // Place the Building
        auto command = std::make_unique<PlaceComponentCommand>(grid, placeLoc, building);
        state.executeCommand(std::move(command));
        std::cout << "\033[1;32m" << buildingType << " placed successfully at ("
                  << placeLoc.x << ", " << placeLoc.y << ")!\033[0m\n";
    }

    void handlePlaceUtility() {
        UtilityFactory factory;

        std::cout << "\nSelect utility type:\n";
        for (int i = 1; i <= 4; i++) {
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

    void collectTaxes() {
        ConcreteTaxCollector collector;

        // Collect taxes from all buildings on the grid
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

    void showStatistics() {
        std::cout << "\n=== City Statistics ===\n";
        government.displayGovernmentStats();

        std::cout << "\n=== NPC States ===\n"
                  << "Happy Citizens: " << npcManager.getDonationCount() << "\n"
                  << "Neutral Citizens: " << npcManager.getNeutralCount() << "\n"
                  << "Revolting Citizens: " << npcManager.getRevoltCount() << "\n"
                  << "Productive Citizens: " << npcManager.getProductiveCount() << "\n"
                  << "Criminal Citizens: " << npcManager.getCrimeCount() << "\n"
                  << "\nDominant State: " << npcManager.getHighestState() << "\n";

        // Industry Stats
        std::cout << "\n=== Industry Status ===\n";
        bool foundIndustry = false;
        for (int y = 0; y < grid.getHeight(); y++) {
            for (int x = 0; x < grid.getWidth(); x++) {
                if (auto component = grid.getComponent({x, y})) {
                    if (auto industry = std::dynamic_pointer_cast<Industry>(component)) {
                        foundIndustry = true;
                        std::cout << "\nIndustry at (" << x << "," << y << "):\n";
                        industry->displayStatus();
                    }
                }
            }
        }
        if (!foundIndustry) {
            std::cout << "No industries built yet.\n";
        }

        // Resource Deposits Stats
        std::cout << "\n=== Resource Deposits ===\n";
        std::map<std::string, int> resourceCounts;
        for (int y = 0; y < grid.getHeight(); y++) {
            for (int x = 0; x < grid.getWidth(); x++) {
                if (auto component = grid.getComponent({x, y})) {
                    if (auto incomeRes = std::dynamic_pointer_cast<IncomeResourceProduct>(component)) {
                        resourceCounts[incomeRes->getName()]++;
                    }
                    if (auto constructionRes = std::dynamic_pointer_cast<ConstructionResourceProduct>(component)) {
                        resourceCounts[constructionRes->getName()]++;
                    }
                }
            }
        }

        if (resourceCounts.empty()) {
            std::cout << "No resource deposits found.\n";
        } else {
            std::cout << "Income Resources:\n";
            if (resourceCounts["Gold"]) std::cout << "  Gold Deposits: " << resourceCounts["Gold"] << "\n";
            if (resourceCounts["Diamond"]) std::cout << "  Diamond Deposits: " << resourceCounts["Diamond"] << "\n";
            if (resourceCounts["Coal"]) std::cout << "  Coal Deposits: " << resourceCounts["Coal"] << "\n";
            if (resourceCounts["Oil"]) std::cout << "  Oil Deposits: " << resourceCounts["Oil"] << "\n";

            std::cout << "\nConstruction Resources:\n";
            if (resourceCounts["Stone"]) std::cout << "  Stone Deposits: " << resourceCounts["Stone"] << "\n";
            if (resourceCounts["Wood"]) std::cout << "  Wood Deposits: " << resourceCounts["Wood"] << "\n";
            if (resourceCounts["Concrete"]) std::cout << "  Concrete Deposits: " << resourceCounts["Concrete"] << "\n";
            if (resourceCounts["Steel"]) std::cout << "  Steel Deposits: " << resourceCounts["Steel"] << "\n";
        }

        std::cout << "\nPress Enter to continue...";
        std::cin.get();
    }

    void handleProcessResources() {
        std::cout << "\nResource Processing Menu:\n"
                  << "1. Select Industry\n"
                  << "2. View Processing Status\n"
                  << "0. Back\n"
                  << "Choice: ";

        int choice;
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\033[1;31mInvalid input!\033[0m\n";
            return;
        }

        switch (choice) {
            case 1: {
                // Show available industries on the map
                std::vector<std::pair<Location, std::shared_ptr<Industry>>> industries;

                // Find all industries on the map
                for (int y = 0; y < grid.getHeight(); y++) {
                    for (int x = 0; x < grid.getWidth(); x++) {
                        Location loc{x, y};
                        if (auto component = grid.getComponent(loc)) {
                            if (auto industry = std::dynamic_pointer_cast<Industry>(component)) {
                                industries.push_back({loc, industry});
                            }
                        }
                    }
                }

                if (industries.empty()) {
                    std::cout << "\033[1;31mNo industries found! Build some industries first.\033[0m\n";
                    return;
                }

                // Display available industries
                std::cout << "\nAvailable Industries:\n";
                for (size_t i = 0; i < industries.size(); i++) {
                    std::cout << i + 1 << ". " << industries[i].second->getBuildingType()
                              << " at (" << industries[i].first.x << ","
                              << industries[i].first.y << ")\n";
                }

                // Select industry
                std::cout << "Select industry (1-" << industries.size() << "): ";
                int industryChoice;
                std::cin >> industryChoice;

                if (industryChoice < 1 || industryChoice > static_cast<int>(industries.size())) {
                    std::cout << "\033[1;31mInvalid industry selection!\033[0m\n";
                    return;
                }

                auto selectedIndustry = industries[industryChoice - 1].second;

                // Process resources menu
                std::cout << "\nProcessing Options:\n"
                          << "1. Process Income Resource\n"
                          << "2. Process Construction Resource\n"
                          << "Choice: ";

                int processChoice;
                std::cin >> processChoice;

                std::cout << "Enter amount to process: ";
                int amount;
                std::cin >> amount;

                switch (processChoice) {
                    case 1:
                        selectedIndustry->processResources(amount, true);  // Process primary (income)
                        break;
                    case 2:
                        selectedIndustry->processResources(amount, false); // Process secondary (construction)
                        break;
                    default:
                        std::cout << "\033[1;31mInvalid processing choice!\033[0m\n";
                        return;
                }
                break;
            }
            case 2: {
                // View processing status of all industries
                bool found = false;
                for (int y = 0; y < grid.getHeight(); y++) {
                    for (int x = 0; x < grid.getWidth(); x++) {
                        if (auto component = grid.getComponent({x, y})) {
                            if (auto industry = std::dynamic_pointer_cast<Industry>(component)) {
                                found = true;
                                std::cout << "\nIndustry at (" << x << "," << y << "):\n";
                                industry->displayStatus();
                            }
                        }
                    }
                }
                if (!found) {
                    std::cout << "\033[1;31mNo industries found on the map!\033[0m\n";
                }
                break;
            }
            case 0:
                return;
            default:
                std::cout << "\033[1;31mInvalid choice!\033[0m\n";
                break;
        }
    }

    // Resource Management Methods
    bool isResourceInRange(const Location& industryLoc, const Location& resourceLoc, int collectionRange) const {
        int dx = abs(industryLoc.x - resourceLoc.x);
        int dy = abs(industryLoc.y - resourceLoc.y);
        return dx <= collectionRange && dy <= collectionRange;
    }

    template<typename T>
    std::pair<std::shared_ptr<T>, Location> findClosestResource(const Location& industryLoc) {
        int minDistance = std::numeric_limits<int>::max();
        std::shared_ptr<T> closestResource = nullptr;
        Location closestLoc{-1, -1};

        // Search in income resources
        for (const auto& [loc, resource] : incomeResourceMap) {
            if (auto res = std::dynamic_pointer_cast<T>(resource)) {
                int distance = abs(loc.x - industryLoc.x) + abs(loc.y - industryLoc.y);
                if (distance < minDistance) {
                    minDistance = distance;
                    closestResource = res;
                    closestLoc = loc;
                }
            }
        }

        // Search in construction resources if not found in income resources
        if (!closestResource) {
            for (const auto& [loc, resource] : constructionResourceMap) {
                if (auto res = std::dynamic_pointer_cast<T>(resource)) {
                    int distance = abs(loc.x - industryLoc.x) + abs(loc.y - industryLoc.y);
                    if (distance < minDistance) {
                        minDistance = distance;
                        closestResource = res;
                        closestLoc = loc;
                    }
                }
            }
        }

        return {closestResource, closestLoc};
    }

    void addCollectedResource(const std::string& resourceName, int amount) {
        collectedResources[resourceName] += amount;
    }

    // bool hasRequiredResources(const std::string& buildingType) {
    //     auto it = buildingResourceRequirements.find(buildingType);
    //     if (it == buildingResourceRequirements.end()) {
    //         return false;
    //     }
    //     const ResourceRequirement& req = it->second;
    //     // Check if the player has enough resources
    //     return collectedResources["Wood"] >= req.wood &&
    //            collectedResources["Stone"] >= req.stone &&
    //            collectedResources["Steel"] >= req.steel &&
    //            collectedResources["Concrete"] >= req.concrete;
    // }

    bool hasRequiredResources(const std::string& buildingType) {
        displayCollectedResources();  // Show current resources
        return checkResourceRequirements(buildingType, collectedResources);
    }

    void consumeResources(const std::string& buildingType) {
        auto it = buildingResourceRequirements.find(buildingType);
        if (it != buildingResourceRequirements.end()) {
            const auto& req = it->second;
            
            std::cout << "\n=== Consuming Resources ===\n";
            
            // Deduct resources and log
            collectedResources["Wood"] -= req.wood;
            std::cout << "Wood: -" << req.wood << "\n";
            
            collectedResources["Stone"] -= req.stone;
            std::cout << "Stone: -" << req.stone << "\n";
            
            collectedResources["Steel"] -= req.steel;
            std::cout << "Steel: -" << req.steel << "\n";
            
            collectedResources["Concrete"] -= req.concrete;
            std::cout << "Concrete: -" << req.concrete << "\n";
            
            std::cout << "\033[1;32mResources successfully consumed\033[0m\n";
        }
    }

    // Add this helper function
    void displayResourceRequirements(const std::string& buildingType) {
        auto it = buildingResourceRequirements.find(buildingType);
        if (it != buildingResourceRequirements.end()) {
            const auto& req = it->second;
            std::cout << "\n=== Required Resources for " << buildingType << " ===\n"
                    << "Wood: " << req.wood << "\n"
                    << "Stone: " << req.stone << "\n"
                    << "Steel: " << req.steel << "\n"
                    << "Concrete: " << req.concrete << "\n";
        }
    }

public:
    CityGame(int width, int height) : grid(width, height) {
        initializeResourceSystem();
        initializeResources();
        spawnResources();
    }

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
                    case 9: handlePlaceTransport(); break;
                    case 10: handleProcessResources(); break;
                    case 11: handleSaveGame(); break;
                    case 12: handleLoadGame(); break;
                    case 0: running = false; break;
                    default: std::cout << "\033[1;31mInvalid choice!\033[0m\n";
                }
            } catch (const std::exception& e) {
                std::cout << "\033[1;31mError: " << e.what() << "\033[0m\n";
            }
        }
    }
};

#endif // CITYGAME_H
