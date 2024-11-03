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
#include "Industry.h"
#include "MetalWorkFacility.h"
#include "PetroChemicalFacility.h"
#include "CrystalCraftIndustry.h"
#include "WoodAndCoalPlant.h"
#include "IncomeResourceProcessor.h"
#include "ResourceProcessor.h"
#include "ConstructionResourceProcessor.h"
// #include "LandMark.h"
// #include "Park.h"
// #include "Monument.h"
// #include "CulturalCenter.h"
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

class CityGame {
private:
    std::vector<std::shared_ptr<IncomeResourceProduct>> incomeResources;
    std::vector<std::shared_ptr<ConstructionResourceProduct>> constructionResources;

    void initializeResources() {
        // Income Resources
        incomeResources.push_back(std::make_shared<Gold>(100, 50.0));    // Initial 100 units, $50 per unit
        incomeResources.push_back(std::make_shared<Diamonds>(50, 100.0)); // Initial 50 units, $100 per unit
        incomeResources.push_back(std::make_shared<Coal>(200, 10.0));    // Initial 200 units, $10 per unit
        incomeResources.push_back(std::make_shared<Oil>(150, 30.0));     // Initial 150 units, $30 per unit

        // Construction Resources
        constructionResources.push_back(std::make_shared<Stone>(300, 5)); // Initial 300 units, $5 per unit
        constructionResources.push_back(std::make_shared<Wood>(400, 3));  // Initial 400 units, $3 per unit
        constructionResources.push_back(std::make_shared<Concrete>(400, 3));
        constructionResources.push_back(std::make_shared<Steel>(400, 3));
    }

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
                << "9. Process Resources\n"
                << "0. Exit\n"
                << "\nChoice: ";
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

void spawnResources() {
    // Spawn Income Resources
    spawnIncomeResource<Gold>(3, 100, 50.0);      // Spawn 3 gold deposits
    spawnIncomeResource<Diamonds>(2, 50, 100.0);   // Spawn 2 diamond deposits
    spawnIncomeResource<Coal>(4, 200, 10.0);      // Spawn 4 coal deposits
    spawnIncomeResource<Oil>(3, 150, 30.0);       // Spawn 3 oil deposits
    
    // Spawn Construction Resources
    spawnConstructionResource<Stone>(5, 300, 5);   // Spawn 5 stone deposits
    spawnConstructionResource<Wood>(5, 400, 3);    // Spawn 5 wood deposits
    spawnConstructionResource<Concrete>(5, 300, 5);
    spawnConstructionResource<Steel>(5, 400, 3);

}

template<typename T>
void spawnIncomeResource(int count, int quantity, double marketValue) {
    for(int i = 0; i < count; i++) {
        Location loc = grid.getRandomEmptyLocation();
        auto resource = std::make_shared<T>(quantity, marketValue);
        grid.placeComponent(loc, resource);
        incomeResources.push_back(std::dynamic_pointer_cast<IncomeResourceProduct>(resource));
        std::cout << "Spawned " << typeid(T).name() << " at (" << loc.x << "," << loc.y << ")\n";
    }
}

template<typename T>
void spawnConstructionResource(int count, int quantity, int unitCost) {
    for(int i = 0; i < count; i++) {
        Location loc = grid.getRandomEmptyLocation();
        auto resource = std::make_shared<T>(quantity, unitCost);
        grid.placeComponent(loc, resource);
        constructionResources.push_back(std::dynamic_pointer_cast<ConstructionResourceProduct>(resource));
        std::cout << "Spawned " << typeid(T).name() << " at (" << loc.x << "," << loc.y << ")\n";
    }
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
              << "3. Industrial Buildings\n"
            //   << "4. Landmarks\n"
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
        
        case 3: // Industrial
            std::cout << "\nSelect Industrial building type:\n"
                      << "1. Metal Work Facility ($300)\n"
                      << "2. Petrochemical Factory ($400)\n"
                      << "3. Crystal Craft Industry ($350)\n"
                      << "4. Wood and Coal Plant ($300)\n" 
                      << "Choice: ";
            int indChoice;
            std::cin >> indChoice;
            switch(indChoice) {
                        case 1: {
                            auto gold = std::make_shared<Gold>(100, 50.0);
                            auto steel = std::make_shared<Steel>(300, 5);
                            building = std::make_shared<MetalWorkFacility>(gold, steel);
                            cost = 300;
                            buildingType = "MetalWork";
                            break;
                        }
                        case 2: {
                            auto oil = std::make_shared<Oil>(100, 50.0);
                            auto concrete = std::make_shared<Concrete>(100, 50.0);
                            building = std::make_shared<PetrochemicalFacility>(oil, concrete);
                            cost = 400; 
                            buildingType = "PetroChemical";
                            break;
                        }
                        case 3: {
                            auto diamond = std::make_shared<Diamonds>(100, 50.0);
                            auto stone = std::make_shared<Stone>(300, 5);
                            building = std::make_shared<CrystalCraftIndustry>(diamond, stone);
                            cost = 350;
                            buildingType = "CrystalCraft";
                            break;
                        }
                        case 4: {
                            auto coal = std::make_shared<Coal>(100, 50.0);
                            auto wood = std::make_shared<Wood>(300, 5);
                            building = std::make_shared<WoodAndCoalPlant>(coal, wood);
                            cost = 300;
                            buildingType = "WoodAndCoal";
                            break;
                        }
                        default:
                            std::cout << "\033[1;31mInvalid industrial building type!\033[0m\n";
                            return;
            }
            break;
        /*
        case 4: // Landmarks
            std::cout << "\nSelect Landmark type:\n"
                      << "1. Park ($200)\n"
                      << "2. Monument ($300)\n"
                      << "3. Cultural Center ($400)\n"
                      << "Choice: ";
            int landChoice;
            std::cin >> landChoice;
            switch(landChoice) {
                case 1: building = std::make_shared<Park>(); cost = 200; buildingType = "Park"; break;
                case 2: building = std::make_shared<Monument>(); cost = 300; buildingType = "Monument"; break;
                case 3: building = std::make_shared<CulturalCenter>(); cost = 400; buildingType = "CulturalCenter"; break;
                default:
                    std::cout << "\033[1;31mInvalid landmark type!\033[0m\n";
                    return;
            }
            break;
        */
        default:
            std::cout << "\033[1;31mInvalid building category!\033[0m\n";
            return;
    }
    // auto& government = Government::getInstance();
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
            case 3: compatible = (zoneType == "Industrial"); break;
            case 4: compatible = true; // Landmarks can be placed anywhere
                break;
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
        case 3: government.setBuildingAmount("Industrial", 1); break;
        // Landmarks might not need counting
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

    void showResources() {
        std::cout << "\n=== Income Resources ===\n";
        for(const auto& resource : incomeResources) {
            resource->displayStatus();
        }
        
        std::cout << "\n=== Construction Resources ===\n";
        for(const auto& resource : constructionResources) {
            resource->displayStatus();
        }
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

    switch(choice) {
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

            switch(processChoice) {
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

public:
    CityGame(int width, int height) : grid(width, height) {
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
                    case 9: handleProcessResources(); break;
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
        CityGame game(25, 25);
        game.run();
    } catch (const std::exception& e) {
        std::cerr << "\033[1;31mError: " << e.what() << "\033[0m\n";
        return 1;
    }
    return 0;
}