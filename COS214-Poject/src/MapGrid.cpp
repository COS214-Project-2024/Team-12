// MapGrid.cpp
#include "MapGrid.h"
#include "Industry.h"
#include "ZoneComposite.h"
#include "CityComponent.h"
#include "ResidentialBuilding.h"
#include "CommercialBuilding.h"
#include "Transport.h"
#include "Gold.h"
#include "Diamonds.h"
#include "Coal.h"
#include "Oil.h"
#include "Stone.h"
#include "Wood.h"
#include "Steel.h"
#include "Concrete.h"

#include <sstream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <random>
// #include "Node.h"
// #include <iostream>

bool MapGrid::placeComponent(const Location& loc, std::shared_ptr<CityComponent> component) {
    auto result = canPlaceBuilding(loc, component);
    if (!result.success) {
        std::cout << "\033[1;31m" << result.message << "\033[0m\n";
        return false;
    }

    grid[loc.y][loc.x].component = component;
    component->setLocation(loc);

    // Check for existing utilities in this cell and connect them to the new building
    if (auto building = std::dynamic_pointer_cast<ResidentialBuilding>(component)) {
        for (const auto& utility : grid[loc.y][loc.x].affectingUtilities) {
            if (utility->getName() == "Water Supply") building->setWaterSupply(utility);
            else if (utility->getName() == "Power Plant") building->setPowerSupply(utility);
            else if (utility->getName() == "Waste Management") building->setWasteManagement(utility);
            else if (utility->getName() == "Sewage System") building->setSewageManagement(utility);
        }
    } else if (auto building = std::dynamic_pointer_cast<CommercialBuilding>(component)) {
        for (const auto& utility : grid[loc.y][loc.x].affectingUtilities) {
            if (utility->getName() == "Water Supply") building->setWaterSupply(utility);
            else if (utility->getName() == "Power Plant") building->setPowerSupply(utility);
            else if (utility->getName() == "Waste Management") building->setWasteManagement(utility);
            else if (utility->getName() == "Sewage System") building->setSewageManagement(utility);
        }
    }

    return true;
}

void MapGrid::addUtilityEffect(const Location& loc, std::shared_ptr<UtilityFlyweight> utility) {
    if (!isValidLocation(loc)) return;

    // Header for utility updates
    std::cout << "\n\033[1;34m=== Utility Update ===\033[0m\n";

    // Notification about the utility being added
    std::cout << "\033[1;36m[INFO]\033[0m Adding utility \033[1;33m" << utility->getName() 
              << "\033[0m at location (" << loc.x << "," << loc.y << ")\n";

    grid[loc.y][loc.x].affectingUtilities.push_back(utility);
    
    if (auto building = grid[loc.y][loc.x].component) {
        std::cout << "\033[1;36m[UPDATE]\033[0m Found building at location. Analyzing connections...\n";
        
        if (auto residential = std::dynamic_pointer_cast<ResidentialBuilding>(building)) {
            std::cout << "\033[1;32m[CONNECT]\033[0m Connecting " << utility->getName() 
                      << " to Residential Building.\n";
            if (utility->getName() == "Water Supply") {
                residential->setWaterSupply(utility);
                std::cout << "\033[1;36m[STATUS]\033[0m Water supply connected successfully.\n";
            }
            else if (utility->getName() == "Power Plant") {
                residential->setPowerSupply(utility);
                std::cout << "\033[1;36m[STATUS]\033[0m Power supply connected successfully.\n";
            }
            else if (utility->getName() == "Waste Management") {
                residential->setWasteManagement(utility);
                std::cout << "\033[1;36m[STATUS]\033[0m Waste management connected successfully.\n";
            }
            else if (utility->getName() == "Sewage System") {
                residential->setSewageManagement(utility);
                std::cout << "\033[1;36m[STATUS]\033[0m Sewage system connected successfully.\n";
            }
            
            std::cout << "\033[1;36m[INFO]\033[0m Current utility coverage level: " 
                      << residential->getUtilityCoverage() << "\n";
        }
        else if (auto commercial = std::dynamic_pointer_cast<CommercialBuilding>(building)) {
            std::cout << "\033[1;32m[CONNECT]\033[0m Connecting " << utility->getName() 
                      << " to Commercial Building.\n";
            if (utility->getName() == "Water Supply") {
                commercial->setWaterSupply(utility);
                std::cout << "\033[1;36m[STATUS]\033[0m Water supply connected successfully.\n";
            }
            else if (utility->getName() == "Power Plant") {
                commercial->setPowerSupply(utility);
                std::cout << "\033[1;36m[STATUS]\033[0m Power supply connected successfully.\n";
            }
            else if (utility->getName() == "Waste Management") {
                commercial->setWasteManagement(utility);
                std::cout << "\033[1;36m[STATUS]\033[0m Waste management connected successfully.\n";
            }
            else if (utility->getName() == "Sewage System") {
                commercial->setSewageManagement(utility);
                std::cout << "\033[1;36m[STATUS]\033[0m Sewage system connected successfully.\n";
            }
            
            std::cout << "\033[1;36m[INFO]\033[0m Current utility coverage level: " 
                      << commercial->getUtilityCoverage() << "\n";
        }
    }

    // Divider to separate this update from the next
    std::cout << "\033[1;34m========================\033[0m\n";
}

bool MapGrid::isCompatibleBuilding(const std::shared_ptr<CityComponent>& building,
	const std::shared_ptr<ZoneComposite>& zone) const {
        if(!building || !zone) return false;
        std::string buildingType = building->getBuildingType();
        std::string zoneType = zone->getBuildingType();
        
        if (zoneType == "Residential") 
            return dynamic_cast<ResidentialBuilding*>(building.get()) != nullptr;
        else if (zoneType == "Commercial")
            return dynamic_cast<CommercialBuilding*>(building.get()) != nullptr;
        else if (zoneType == "Industrial")
            return dynamic_cast<Industry*>(building.get()) != nullptr;
            
        return false;
}

std::vector<std::shared_ptr<CityComponent>> MapGrid::getBuildingsInZone(const std::shared_ptr<ZoneComposite>& zone) const {
    std::vector<std::shared_ptr<CityComponent>> buildings;
    
    // Get zone boundaries
    Location topLeft = zone->getTopLeft();
    Location bottomRight = zone->getBottomRight();
    
    // Collect all buildings within zone boundaries
    for (int y = topLeft.y; y <= bottomRight.y; y++) {
        for (int x = topLeft.x; x <= bottomRight.x; x++) {
            if (grid[y][x].component) {
                buildings.push_back(grid[y][x].component);
            }
        }
    }
    
    return buildings;
}

void MapGrid::displayCollectionRange(const Location& industryLoc) {
    if (auto industry = std::dynamic_pointer_cast<Industry>(getComponent(industryLoc))) {
        int range = industry->getCollectionRange();
        
        // Store current cell states
        std::vector<std::vector<bool>> rangeDisplay(height, std::vector<bool>(width, false));
        
        // Mark cells in range
        for (int y = industryLoc.y - range; y <= industryLoc.y + range; y++) {
            for (int x = industryLoc.x - range; x <= industryLoc.x + range; x++) {
                if (isValidLocation({x, y})) {
                    rangeDisplay[y][x] = true;
                }
            }
        }

        // Display the grid with range highlighting
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                if (x == industryLoc.x && y == industryLoc.y) {
                    std::cout << "\033[1;33m[I]\033[0m"; // Industry in yellow
                } else if (rangeDisplay[y][x]) {
                    if (auto resource = getComponent({x, y})) {
                        // Show resource in range with different color
                        std::cout << "\033[1;32m";
                        // Your existing resource display code
                        std::cout << "\033[0m";
                    } else {
                        std::cout << "\033[1;34m[ ]\033[0m"; // Empty cell in range
                    }
                } else {
                    // Normal display for cells out of range
                    // Your existing display code
                }
            }
            std::cout << "\n";
        }
    }
}

std::string MapGrid::getDisplayString() const {
    std::stringstream ss;
    
    // Header
    ss << "\033[1;36m=== City Map ===\033[0m\n\n";
    
    // Column numbers
    ss << "   ";
    for (int x = 0; x < width; x++) {
        ss << std::setw(3) << x;
    }
    ss << "\n";
    
    // Grid content with zones
    for (int y = 0; y < height; y++) {
        ss << std::setw(2) << y << " ";
        for (int x = 0; x < width; x++) {
            const auto& cell = grid[y][x];
            
            // Start zone styling if cell is in a zone
            if (cell.zone) {
                std::string zoneType = cell.zone->getBuildingType();
                // Add different background colors for different zone types
                if (zoneType == "Residential")
                    ss << "\033[48;5;17m"; // Dark blue background
                else if (zoneType == "Commercial")
                    ss << "\033[48;5;52m"; // Dark red background
                else if (zoneType == "Industrial")
                    ss << "\033[48;5;58m"; // Dark yellow background
            }

			// Display cell content
			if (cell.component) {
				if (auto building = std::dynamic_pointer_cast<CityComponent>(cell.component)) {
					std::string color;
					char symbol	;

					if (auto res = std::dynamic_pointer_cast<ResidentialBuilding>(building)) {
						color = res->getDisplayColor();
						symbol = res->getDisplaySymbol();
						ss << color << "[" << symbol << "]\033[0m";
					} 
					else if (auto com = std::dynamic_pointer_cast<CommercialBuilding>(building)) {
						color = com->getDisplayColor();
						symbol = com->getDisplaySymbol();
						ss << color << "[" << symbol << "]\033[0m";
					}
					else if (auto industry = std::dynamic_pointer_cast<Industry>(building)) {
						ss << "\033[1;31m[I]\033[0m";
					}
					else if (auto utility = std::dynamic_pointer_cast<UtilityFlyweight>(building)) {
						std::string type = utility->getName();
						if (type == "Water Supply") {
							ss << "\033[1;34m[W]\033[0m";
						} else if (type == "Power Plant") {
							ss << "\033[1;35m[P]\033[0m";
						} else if (type == "Sewage System") {
							ss << "\033[1;36m[S]\033[0m";
						} else if (type == "Waste Management") {
							ss << "\033[1;32m[M]\033[0m";
						}
					}// In MapGrid::getDisplayString(), add to the display section:
                    else if (auto incomeResource = std::dynamic_pointer_cast<IncomeResourceProduct>(cell.component)) {
                        if (dynamic_cast<Gold*>(incomeResource.get())) 
                            ss << "\033[1;33m[⚜]\033[0m";  // Gold symbol (fleur-de-lis)
                        else if (dynamic_cast<Diamonds*>(incomeResource.get())) 
                            ss << "\033[1;36m[♦]\033[0m";  // Diamond symbol
                        else if (dynamic_cast<Coal*>(incomeResource.get())) 
                            ss << "\033[1;30m[◆]\033[0m";  // Coal symbol (black diamond)
                        else if (dynamic_cast<Oil*>(incomeResource.get())) 
                            ss << "\033[1;32m[●]\033[0m";  // Oil symbol (black circle)
                    }
                    else if (auto constructionResource = std::dynamic_pointer_cast<ConstructionResourceProduct>(cell.component)) {
                        if (dynamic_cast<Stone*>(constructionResource.get())) 
                            ss << "\033[1;37m[◈]\033[0m";  // Stone symbol
                        else if (dynamic_cast<Wood*>(constructionResource.get())) 
                            ss << "\033[1;33m[⚏]\033[0m";  // Wood symbol
                        else if (dynamic_cast<Concrete*>(constructionResource.get())) 
                            ss << "\033[1;37m[⬢]\033[0m";  // Concrete symbol (hexagon)
                        else if (dynamic_cast<Steel*>(constructionResource.get())) 
                            ss << "\033[1;36m[⬡]\033[0m";  // Steel symbol (hollow hexagon)
                    }
				}
			} else {
				// Empty cell - show utility coverage if any
				if (!cell.affectingUtilities.empty()) {
					int coverageCount = cell.affectingUtilities.size();
					switch(coverageCount) {
						case 1: 
							ss << "\033[1;34m[1]\033[0m";
							break;
						case 2:
							ss << "\033[1;36m[2]\033[0m";
							break;
						case 3:
							ss << "\033[1;35m[3]\033[0m";
							break;
						case 4:
							ss << "\033[1;37m[4]\033[0m";
							break;
					}
				} else  {
					ss << "\033[1;30m[ ]\033[0m";
				}
			}

            // Reset background color if we're in a zone
            if (cell.zone) {
                ss << "\033[0m";
            }
        }
        ss << "\n";
    }
    
	ss << "\nLegend:\n"
	<< "=== Zones ===\n"
	<< "\033[48;5;17m   \033[0m - Residential Zone\n"
	<< "\033[48;5;52m   \033[0m - Commercial Zone\n"
	<< "\033[48;5;58m   \033[0m - Industrial Zone\n"
	<< "\n=== Buildings ===\n"
	<< "Residential:\n"
	<< "\033[1;32m[H]\033[0m - House\n"
	<< "\033[1;32m[F]\033[0m - Flat\n"
	<< "\033[1;32m[T]\033[0m - Townhouse\n"
	<< "\033[1;32m[E]\033[0m - Estate\n"
	<< "\nCommercial:\n"
	<< "\033[1;33m[S]\033[0m - Shop\n"
	<< "\033[1;33m[O]\033[0m - Office\n"
	<< "\033[1;33m[M]\033[0m - Mall\n"
	<< "\n=== Utilities ===\n"
	<< "\033[1;34m[W]\033[0m - Water Supply\n"
	<< "\033[1;35m[P]\033[0m - Power Plant\n"
	<< "\033[1;36m[S]\033[0m - Sewage System\n"
	<< "\033[1;32m[M]\033[0m - Waste Management\n"
	<< "\n=== Coverage ===\n"
	<< "\033[1;34m[1]\033[0m - Single Utility\n"
	<< "\033[1;36m[2]\033[0m - Double Coverage\n"
	<< "\033[1;35m[3]\033[0m - Triple Coverage\n"
	<< "\033[1;37m[4]\033[0m - Full Coverage\n"
	<< "\033[1;30m[ ]\033[0m - Empty\n"
    << "\n=== Resources ===\n"
    << "\033[1;33m[⚜]\033[0m - Gold\n"
    << "\033[1;36m[♦]\033[0m - Diamond\n"
    << "\033[1;30m[◆]\033[0m - Coal\n"
    << "\033[1;32m[●]\033[0m - Oil\n"
    << "\033[1;37m[◈]\033[0m - Stone\n"
    << "\033[1;33m[⚏]\033[0m - Wood\n"
    << "\033[1;37m[⬢]\033[0m - Concrete\n"
    << "\033[1;36m[⬡]\033[0m - Steel\n";

    return ss.str();
}

void MapGrid::removeComponent(const Location& loc) {
    gridMap.erase(loc);
}

void MapGrid::removeIncomeResource(const Location& loc) {
    incomeResourceMap.erase(loc);
}

void MapGrid::removeConstructionResource(const Location& loc) {
    constructionResourceMap.erase(loc);
}


// MapGrid::MapGrid(int width, int height) : width(width), height(height) {
//     std::cout << "Starting grid initialization..." << std::endl;
    
//     // First, reserve space for the rows
//     grid.resize(height);
    
//     // Then initialize each row and its nodes
//     for (int y = 0; y < height; y++) {
//         // Create a new vector for this row with 'width' columns
//         std::vector<std::unique_ptr<Node>> row;
//         row.reserve(width);
        
//         // Fill the row with nodes
//         for (int x = 0; x < width; x++) {
//             row.push_back(std::make_unique<Node>(x, y));
//         }
        
//         // Move the row into place
//         grid[y] = std::move(row);
//     }
    
//     std::cout << "Grid initialization complete: " << width << "x" << height << std::endl;
// }

// Node* MapGrid::getNode(int x, int y) const {
//     if (x >= 0 && x < width && y >= 0 && y < height && grid[y][x]) {
//         return grid[y][x].get();
//     }
//     std::cout << "Warning: Attempted to access invalid node at (" << x << "," << y << ")" << std::endl;
//     return nullptr;
// }

// void MapGrid::placeComponent(CityComponent* component, int x, int y) {
//     std::cout << "Attempting to place component at (" << x << "," << y << ")" << std::endl;
    
//     if (!component) {
//         std::cout << "Error: Null component" << std::endl;
//         return;
//     }

//     if (x < 0 || x >= width || y < 0 || y >= height) {
//         std::cout << "Error: Out of bounds coordinates (" << x << "," << y << ")" << std::endl;
//         return;
//     }

//     Node* node = getNode(x, y);
//     if (!node) {
//         std::cout << "Error: Could not access node at (" << x << "," << y << ")" << std::endl;
//         return;
//     }

//     if (node->getComponent()) {
//         std::cout << "Error: Location already occupied at (" << x << "," << y << ")" << std::endl;
//         return;
//     }

//     node->setComponent(component);
//     component->setLocation(x, y);
//     std::cout << "Successfully placed component at (" << x << "," << y << ")" << std::endl;
// }