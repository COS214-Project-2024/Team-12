#ifndef MAPGRID_H
#define MAPGRID_H


#include "CityComponent.h"
#include "UtilityFlyweight.h"
#include "ResidentialBuilding.h"
#include "CommercialBuilding.h"
#include "ZoneComposite.h"
#include "Industry.h"
#include "Transport.h"
#include "Hospital.h"
#include "FireStation.h"
#include "PublicService.h"
#include "PoliceStation.h"
#include "Landmark.h"
#include "Monument.h"
#include "Park.h"
#include "CulturalCenter.h"

#include <memory>
#include <vector>
#include <string>
#include <random>
#include <set>
#include <algorithm>
#include <map>
#include <array>
#include <sstream>

#include "ForwardDeclarations.h"
#include "Location.h"
#include "CityComponent.h"
#include "ZoneComposite.h"
#include "UtilityFlyweight.h"





class MapGrid {
private:

    std::map<Location, std::shared_ptr<CityComponent>> gridMap;
    std::map<Location, std::shared_ptr<IncomeResourceProduct>> incomeResourceMap;
    std::map<Location, std::shared_ptr<ConstructionResourceProduct>> constructionResourceMap;

    // In MapGrid.h
    struct ResourceSpot {
        std::shared_ptr<CityComponent> resource;
        bool discovered;  // Whether the resource has been discovered
    };

    // Add method to find random empty position


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
             else if (zoneType == "Public Service")
        return dynamic_cast<PublicService*>(building.get()) != nullptr;

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
         char symbol = ' ';
    };

    std::vector<std::vector<Cell>> grid;
    int width, height;
    
    public:
      Cell& getCell(int x, int y) {
        return grid[y][x];
    }

    void setCellSymbol(int x, int y, char symbol) {
        grid[y][x].symbol = symbol;
    }

    void setTransportEndpoint(const Location& loc, char type) {
    setCellSymbol(loc.x, loc.y, (type == 'R') ? 'R' : 'T');
}


void setTransportPath(const Location& loc, char pathSymbol) {
    setCellSymbol(loc.x, loc.y, pathSymbol);  // Use setCellSymbol to set the symbol directly
}


private:

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
    Location getRandomEmptyLocation() const {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> disX(0, width - 1);
        std::uniform_int_distribution<> disY(0, height - 1);
        
        Location loc;
        do {
            loc.x = disX(gen);
            loc.y = disY(gen);
        } while (!isValidLocation(loc) || grid[loc.y][loc.x].component != nullptr);
        
        return loc;
    }

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
    // MapGrid.h


    // Method to get all buildings in a specific zone
    std::vector<std::shared_ptr<CityComponent>> getBuildingsInZone(const std::shared_ptr<ZoneComposite>& zone) const;
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

	bool placeComponent(const Location& loc, std::shared_ptr<CityComponent> component) ;

	bool connectLocations(const Location& start, const Location& end, 
                        std::shared_ptr<Transport> transport) {
            if (start.x == end.x) { // Vertical path
        for (int y = start.y; y <= end.y; ++y) {
            setCellSymbol(start.x, y, '|');
        }
    } else if (start.y == end.y) { // Horizontal path
        for (int x = start.x; x <= end.x; ++x) {
            setCellSymbol(x, start.y, '-');
        }
    }


    // Set the endpoints
    setCellSymbol(start.x, start.y, (transport->getType() == "Road") ? 'R' : 'T');
    setCellSymbol(end.x, end.y, (transport->getType() == "Road") ? 'R' : 'T');

    return true;
    }
    
   
    bool placePublicService(const Location& loc, std::shared_ptr<PublicService> publicService) {
    if (!isValidLocation(loc)) {
        std::cout << "\033[1;31mInvalid location!\033[0m\n";
        return false;
    }

    if (getComponent(loc)) {
        std::cout << "\033[1;31mLocation already occupied!\033[0m\n";
        return false;
    }

    // Place the public service on the map
    grid[loc.y][loc.x].component = publicService;
    std::cout << "\033[1;32mPublic service placed successfully!\033[0m\n";
    return true;
}

    // void removeComponent(const Location& loc) {
    //     if (isValidLocation(loc)) {
    //         grid[loc.y][loc.x].component.reset();
    //     }
    // }

    std::shared_ptr<CityComponent> getComponent(const Location& loc) const {
        return isValidLocation(loc) ? grid[loc.y][loc.x].component : nullptr;
    }

    // Additional utility-specific methods
    // void addUtilityEffect(const Location& loc, std::shared_ptr<UtilityFlyweight> utility) {
    //     if (isValidLocation(loc)) {
    //         grid[loc.y][loc.x].affectingUtilities.push_back(utility);
    //     }
    // }

void addUtilityEffect(const Location& loc, std::shared_ptr<UtilityFlyweight> utility);

// In MapGrid.h
void displayCollectionRange(const Location& industryLoc);


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


std::string getDisplayString() const;

    void removeComponent(const Location& loc);

    // Methods to remove resources from resource maps
    void removeIncomeResource(const Location& loc);
    void removeConstructionResource(const Location& loc);


};

#endif