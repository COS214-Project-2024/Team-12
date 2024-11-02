#ifndef MAPGRID_H
#define MAPGRID_H

#include "CityComponent.h"
#include "UtilityFlyweight.h"
#include "ResidentialBuilding.h"
#include "CommercialBuilding.h"
#include "ZoneComposite.h"
#include "Industry.h"
#include "Transport.h"
#include <memory>
#include <vector>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <array>
#include <set>
#include <unordered_set>

class MapGrid {
private:
	// Add zone validation methods
	bool isOverlappingZone(const Location& topLeft, const Location& bottomRight) const {
        for (int y = topLeft.y; y <= bottomRight.y; y++) {
            for (int x = topLeft.x; x <= bottomRight.x; x++) {
                if (grid[y][x].zone) {
                    return true;
                }
            }
        }
        return false;
    }

	bool isCompatibleBuilding(const std::shared_ptr<CityComponent>& building,
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

    struct ZoneStyle {
        std::array<std::string, 9> borderChars; // Changed to std::string
        std::string backgroundColor;

        ZoneStyle(const std::array<std::string, 9>& borders, const std::string& bgColor)
            : borderChars(borders), backgroundColor(bgColor) {}
    };

    // Cell structure with zone support
    struct Cell {
        std::shared_ptr<CityComponent> component;
        std::vector<std::shared_ptr<UtilityFlyweight>> affectingUtilities;
        std::shared_ptr<ZoneComposite> zone;  // Added zone support
    };

    std::vector<std::vector<Cell>> grid;
    int width, height;
    
    // Initialize zone styles
    std::map<std::string, ZoneStyle> zoneStyles;

    void initializeZoneStyles() {
        // Changed char arrays to std::string arrays
        const std::array<std::string, 9> residentialBorders = {"╔", "╗", "╚", "╝", "║", "═", "╠", "╣", "╬"};
        const std::array<std::string, 9> commercialBorders = {"┌", "┐", "└", "┘", "│", "─", "├", "┤", "┼"};
        const std::array<std::string, 9> industrialBorders = {"╭", "╮", "╰", "╯", "│", "─", "├", "┤", "┼"};

        zoneStyles.insert({"Residential", ZoneStyle(residentialBorders, "\033[48;5;17m")});
        zoneStyles.insert({"Commercial", ZoneStyle(commercialBorders, "\033[48;5;52m")});
        zoneStyles.insert({"Industrial", ZoneStyle(industrialBorders, "\033[48;5;58m")});
    }

    bool isZoneBoundary(int x, int y) const {
        if (!isValidLocation({x, y}) || !grid[y][x].zone) {
            return false;
        }
        
        // Check if any adjacent cell is outside the zone
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (dx == 0 && dy == 0) continue;
                
                int newX = x + dx;
                int newY = y + dy;
                
                if (!isValidLocation({newX, newY}) || 
                    !grid[newY][newX].zone || 
                    grid[newY][newX].zone != grid[y][x].zone) {
                    return true;
                }
            }
        }
        return false;
    }

public:
	int getHeight() const {
		return height;
	}

	int getWidth() const {
		return width;
	}
	    std::vector<std::shared_ptr<ZoneComposite>> getAllZones() const {
        	std::set<std::shared_ptr<ZoneComposite>> uniqueZones;
        
        	// Collect all unique zones
        	for (int y = 0; y < height; y++) {
            	for (int x = 0; x < width; x++) {
                	if (grid[y][x].zone) {
                    	uniqueZones.insert(grid[y][x].zone);
                	}
            	}
        	}
        
        	return std::vector<std::shared_ptr<ZoneComposite>>(uniqueZones.begin(), uniqueZones.end());
    	}

    // Method to get all buildings in a specific zone
    std::vector<std::shared_ptr<CityComponent>> getBuildingsInZone(const std::shared_ptr<ZoneComposite>& zone) const {
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
	// Enhanced placement checks
	struct PlacementResult {
		bool success;
		std::string message;
	};

    PlacementResult canPlaceZone(const Location& topLeft, const Location& bottomRight) const {
        // Check boundaries
        if (!isValidLocation(topLeft) || !isValidLocation(bottomRight)) {
            return {false, "Zone boundaries are outside the map!"};
        }

        // Check for overlapping zones
        if (isOverlappingZone(topLeft, bottomRight)) {
            return {false, "Cannot create overlapping zones!"};
        }

        return {true, "Zone placement is valid."};
    }

    PlacementResult canPlaceBuilding(const Location& loc, 
                                    const std::shared_ptr<CityComponent>& building) const {
        if (!isValidLocation(loc)) {
            return {false, "Invalid location!"};
        }

        if (grid[loc.y][loc.x].component) {
            return {false, "Location already occupied!"};
        }

        // Check zone compatibility
        if (auto zone = grid[loc.y][loc.x].zone) {
            if (!isCompatibleBuilding(building, zone)) {
                return {false, "Building type not allowed in this zone!"};
            }
        }

        return {true, "Building placement is valid."};
    }

    MapGrid(int w, int h) : width(w), height(h) {
        grid.resize(height, std::vector<Cell>(width));
		initializeZoneStyles(); // Initialize styles in constructor
    }

	bool createZone(const Location& topLeft, const Location& bottomRight, const std::string& zoneType) {
        auto result = canPlaceZone(topLeft, bottomRight);
        if (!result.success) {
            std::cout << "\033[1;31m" << result.message << "\033[0m\n";
            return false;
        }

        auto zone = std::make_shared<ZoneComposite>(zoneType, topLeft, bottomRight);
        
        // Set zone for all cells in the rectangle
        for (int y = topLeft.y; y <= bottomRight.y; y++) {
            for (int x = topLeft.x; x <= bottomRight.x; x++) {
                setZone({x, y}, zone);
            }
        }

        std::cout << "\033[1;32mZone created successfully!\033[0m\n";
        return true;
    }

	void setZone(const Location& loc, std::shared_ptr<ZoneComposite> newZone) {
        if (isValidLocation(loc)) {
            grid[loc.y][loc.x].zone = newZone;
        }
    }

    std::shared_ptr<ZoneComposite> getZone(const Location& loc) const {
        return isValidLocation(loc) ? grid[loc.y][loc.x].zone : nullptr;
    }

    // Existing methods remain the same
    bool isValidLocation(const Location& loc) const {
        return loc.x >= 0 && loc.x < width && loc.y >= 0 && loc.y < height;
    }

	bool placeComponent(const Location& loc, std::shared_ptr<CityComponent> component) {
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

	bool connectLocations(const Location& start, const Location& end, 
                        std::shared_ptr<Transport> transport) {
        // Implementation of connection logic
        return true;
    }

    void removeComponent(const Location& loc) {
        if (isValidLocation(loc)) {
            grid[loc.y][loc.x].component.reset();
        }
    }

    std::shared_ptr<CityComponent> getComponent(const Location& loc) const {
        return isValidLocation(loc) ? grid[loc.y][loc.x].component : nullptr;
    }

    // Additional utility-specific methods
    // void addUtilityEffect(const Location& loc, std::shared_ptr<UtilityFlyweight> utility) {
    //     if (isValidLocation(loc)) {
    //         grid[loc.y][loc.x].affectingUtilities.push_back(utility);
    //     }
    // }

void addUtilityEffect(const Location& loc, std::shared_ptr<UtilityFlyweight> utility) {
    if (!isValidLocation(loc)) return;
    
    std::cout << "\nAdding utility " << utility->getName() 
              << " at (" << loc.x << "," << loc.y << ")" << std::endl;
    
    grid[loc.y][loc.x].affectingUtilities.push_back(utility);
    
    if (auto building = grid[loc.y][loc.x].component) {
        std::cout << "Found building at location" << std::endl;
        
        if (auto residential = std::dynamic_pointer_cast<ResidentialBuilding>(building)) {
            std::cout << "It's a residential building" << std::endl;
            if (utility->getName() == "Water Supply") {
                residential->setWaterSupply(utility);
                std::cout << "Connected water supply" << std::endl;
            }
            else if (utility->getName() == "Power Plant") {
                residential->setPowerSupply(utility);
                std::cout << "Connected power supply" << std::endl;
            }
            else if (utility->getName() == "Waste Management") {
                residential->setWasteManagement(utility);
                std::cout << "Connected waste management" << std::endl;
            }
            else if (utility->getName() == "Sewage System") {
                residential->setSewageManagement(utility);
                std::cout << "Connected sewage system" << std::endl;
            }
            
            std::cout << "After connection, utility coverage: " 
                      << residential->getUtilityCoverage() << std::endl;
        }
        else if (auto commercial = std::dynamic_pointer_cast<CommercialBuilding>(building)) {
            std::cout << "It's a commercial building" << std::endl;
            if (utility->getName() == "Water Supply") {
                commercial->setWaterSupply(utility);
                std::cout << "Connected water supply" << std::endl;
            }
            else if (utility->getName() == "Power Plant") {
                commercial->setPowerSupply(utility);
                std::cout << "Connected power supply" << std::endl;
            }
            else if (utility->getName() == "Waste Management") {
                commercial->setWasteManagement(utility);
                std::cout << "Connected waste management" << std::endl;
            }
            else if (utility->getName() == "Sewage System") {
                commercial->setSewageManagement(utility);
                std::cout << "Connected sewage system" << std::endl;
            }
            
            std::cout << "After connection, utility coverage: " 
                      << commercial->getUtilityCoverage() << std::endl;
        }
    }
}

	void removeUtilityEffect(const Location& loc, std::shared_ptr<UtilityFlyweight> utility) {
    if (isValidLocation(loc)) {
        auto& utilities = grid[loc.y][loc.x].affectingUtilities;
        utilities.erase(
            std::remove_if(utilities.begin(), utilities.end(),
                [&utility](const auto& u) { return u == utility; }),
            utilities.end()
        );
    }
	}

	    // Add a method to check if a location is in a valid zone for a building type
    bool isValidZoneForBuilding(const Location& loc, const std::shared_ptr<CityComponent>& building) const {
        auto zone = getZone(loc);
        if (!zone) return true;  // If no zone, any building is allowed
        return isCompatibleBuilding(building, zone);
    }

std::string getDisplayString() const {
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
				} else {
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
	<< "\033[1;30m[ ]\033[0m - Empty\n";
	   

    return ss.str();
}
};

#endif