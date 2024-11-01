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
    
    // Header with city statistics
    ss << "\033[1;36m=== City Map ===\033[0m\n\n";
    
    // Column numbers with better formatting
    ss << "   ";
    for (int x = 0; x < width; x++) {
        ss << std::setw(3) << x;
    }
    ss << "\n";
    
    // Grid content with enhanced visuals
    for (int y = 0; y < height; y++) {
        ss << std::setw(2) << y << " ";
        for (int x = 0; x < width; x++) {
            const auto& cell = grid[y][x];
            if (cell.component) {
                // Building Types
                if (dynamic_cast<ResidentialBuilding*>(cell.component.get())) {
                    ss << "\033[1;32m[H]\033[0m"; // House in bright green
                } else if (dynamic_cast<CommercialBuilding*>(cell.component.get())) {
                    ss << "\033[1;33m[C]\033[0m"; // Commercial in bright yellow
                } else if (dynamic_cast<Industry*>(cell.component.get())) {
                    ss << "\033[1;31m[I]\033[0m"; // Industry in bright red
                } 
                // Utility Types with distinct colors
                else if (auto utility = dynamic_cast<UtilityFlyweight*>(cell.component.get())) {
                    std::string type = utility->getName();
                    if (type == "Water Supply") {
                        ss << "\033[1;34m[W]\033[0m"; // Water in blue
                    } else if (type == "Power Plant") {
                        ss << "\033[1;35m[P]\033[0m"; // Power in magenta
                    } else if (type == "Sewage System") {
                        ss << "\033[1;33m[S]\033[0m"; // Sewage in yellow
                    } else if (type == "Waste Management") {
                        ss << "\033[1;32m[M]\033[0m"; // Waste in green
                    }
                }
            } else {
                // Enhanced coverage indicators
                if (!cell.affectingUtilities.empty()) {
                    // Count different types of coverage
                    bool hasWater = false, hasPower = false, 
                         hasSewage = false, hasWaste = false;
                    
                    for (const auto& util : cell.affectingUtilities) {
                        std::string type = util->getName();
                        if (type == "Water Supply") hasWater = true;
                        else if (type == "Power Plant") hasPower = true;
                        else if (type == "Sewage System") hasSewage = true;
                        else if (type == "Waste Management") hasWaste = true;
                    }

                    // Show multiple coverage with different indicators
                    int coverageCount = hasWater + hasPower + hasSewage + hasWaste;
                    if (coverageCount > 1) {
                        // Multiple coverage types
                        ss << "\033[1;37m[" << coverageCount << "]\033[0m"; // White number showing coverage count
                    } else {
                        // Single coverage type
                        if (hasWater) ss << "\033[1;34m[~]\033[0m";      // Water coverage with wave symbol
                        else if (hasPower) ss << "\033[1;35m[⚡]\033[0m"; // Power coverage with lightning
                        else if (hasSewage) ss << "\033[1;33m[≈]\033[0m"; // Sewage with double wave
                        else if (hasWaste) ss << "\033[1;32m[♲]\033[0m";  // Waste with recycle symbol
                    }
                } else {
                    ss << "\033[1;30m[ ]\033[0m"; // Empty cell in dark gray
                }
            }
        }
        ss << "\n";
    }
    
    // Enhanced legend with color coding and symbols
    ss << "\nLegend:\n"
       << "=== Buildings ===\n"
       << "\033[1;32m[H]\033[0m - House\n"
       << "\033[1;33m[C]\033[0m - Commercial\n"
       << "\033[1;31m[I]\033[0m - Industry\n"
       << "\n=== Utilities ===\n"
       << "\033[1;34m[W]\033[0m - Water Supply    \033[1;34m[~]\033[0m - Water Coverage\n"
       << "\033[1;35m[P]\033[0m - Power Plant     \033[1;35m[⚡]\033[0m - Power Coverage\n"
       << "\033[1;33m[S]\033[0m - Sewage System   \033[1;33m[≈]\033[0m - Sewage Coverage\n"
       << "\033[1;32m[M]\033[0m - Waste Management\033[1;32m[♲]\033[0m - Waste Coverage\n"
       << "\033[1;37m[2]\033[0m-\033[1;37m[4]\033[0m - Multiple Coverage Types\n"
       << "\033[1;30m[ ]\033[0m - Empty\n";

    return ss.str();
}
};

#endif