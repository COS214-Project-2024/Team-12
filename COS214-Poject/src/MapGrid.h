#ifndef MAPGRID_H
#define MAPGRID_H

#include "CityComponent.h"
#include "UtilityFlyweight.h"
#include "ResidentialBuilding.h"
#include "CommercialBuilding.h"
#include "Industry.h"
#include <memory>
#include <vector>
#include <sstream>
#include <iomanip>
#include <algorithm>

class MapGrid {
private:
    struct Cell {
        std::shared_ptr<CityComponent> component;
        std::vector<std::shared_ptr<UtilityFlyweight>> affectingUtilities;
    };

    std::vector<std::vector<Cell>> grid;
    int width, height;

public:
    MapGrid(int w, int h) : width(w), height(h) {
        grid.resize(height, std::vector<Cell>(width));
    }

    bool isValidLocation(const Location& loc) const {
        return loc.x >= 0 && loc.x < width && loc.y >= 0 && loc.y < height;
    }

    bool placeComponent(const Location& loc, std::shared_ptr<CityComponent> component) {
        if (!isValidLocation(loc) || grid[loc.y][loc.x].component) {
            return false;
        }
        grid[loc.y][loc.x].component = component;
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
    void addUtilityEffect(const Location& loc, std::shared_ptr<UtilityFlyweight> utility) {
        if (isValidLocation(loc)) {
            grid[loc.y][loc.x].affectingUtilities.push_back(utility);
        }
    }

    // void removeUtilityEffect(const Location& loc, std::shared_ptr<UtilityFlyweight> utility) {
    //     if (isValidLocation(loc)) {
    //         auto& utilities = grid[loc.y][loc.x].affectingUtilities;
    //         utilities.erase(
    //             std::remove(utilities.begin(), utilities.end(), utility),
    //             utilities.end()
    //         );
    //     }
    // }

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
        
        // Grid content
        for (int y = 0; y < height; y++) {
            ss << std::setw(2) << y << " ";
            for (int x = 0; x < width; x++) {
                const auto& cell = grid[y][x];
                if (cell.component) {
                    // Get the building type and display appropriate symbol
                    std::string type = cell.component->getBuildingType();
                    
                    if (dynamic_cast<ResidentialBuilding*>(cell.component.get())) {
                        ss << "\033[1;32m[H]\033[0m"; // House in green
                    } else if (dynamic_cast<CommercialBuilding*>(cell.component.get())) {
                        ss << "\033[1;33m[C]\033[0m"; // Commercial in yellow
                    } else if (dynamic_cast<Industry*>(cell.component.get())) {
                        ss << "\033[1;31m[I]\033[0m"; // Industry in red
                    } else if (dynamic_cast<UtilityFlyweight*>(cell.component.get())) {
                        ss << "\033[1;36m[U]\033[0m"; // Utility in cyan
                    } else {
                        ss << "[?]"; // Unknown building type
                    }
                } else {
                    // Show utility coverage for empty cells
                    if (!cell.affectingUtilities.empty()) {
                        ss << "\033[1;34m[·]\033[0m"; // Utility coverage in blue
                    } else {
                        ss << "[ ]"; // Empty cell
                    }
                }
            }
            ss << "\n";
        }
        
        // Add legend
        ss << "\nLegend:\n"
           << "\033[1;32m[H]\033[0m - House\n"
           << "\033[1;33m[C]\033[0m - Commercial\n"
           << "\033[1;31m[I]\033[0m - Industry\n"
           << "\033[1;36m[U]\033[0m - Utility\n"
           << "\033[1;34m[·]\033[0m - Utility Coverage\n"
           << "[ ] - Empty\n";
        
        return ss.str();
    }
};

#endif