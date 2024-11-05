// Location.h
#ifndef LOCATION_H
#define LOCATION_H

#include <cmath>

/**
 * @brief Represents a 2D coordinate location on a grid.
 * 
 * The `Location` struct stores x and y coordinates, providing utilities to
 * compare, validate, and calculate the distance between locations.
 */
struct Location {
    int x; ///< X-coordinate of the location.
    int y; ///< Y-coordinate of the location.
    
    /**
     * @brief Default constructor initializing location to (0, 0).
     */
    Location() : x(0), y(0) {}

    /**
     * @brief Parameterized constructor to initialize location with specific coordinates.
     * @param xCoord The x-coordinate.
     * @param yCoord The y-coordinate.
     */
    Location(int xCoord, int yCoord) : x(xCoord), y(yCoord) {}
    
    /**
     * @brief Equality operator to compare two locations.
     * @param other Another location to compare with.
     * @return True if the locations have the same coordinates.
     */
    bool operator==(const Location& other) const {
        return x == other.x && y == other.y;
    }

    /**
     * @brief Inequality operator to compare two locations.
     * @param other Another location to compare with.
     * @return True if the locations have different coordinates.
     */
    bool operator!=(const Location& other) const {
        return !(*this == other);
    }

    /**
     * @brief Less-than operator to order locations, primarily for use in sorted containers.
     * @param other Another location to compare with.
     * @return True if this location is less than the other based on x and y coordinates.
     */
    bool operator<(const Location& other) const {
        if (x != other.x)
            return x < other.x;
        else
            return y < other.y;
    }
    
    /**
     * @brief Calculates the Euclidean distance to another location.
     * @param other The other location.
     * @return The distance to the other location.
     */
    double distanceTo(const Location& other) const {
        return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));
    }

    /**
     * @brief Checks if the location is valid (non-negative coordinates).
     * @return True if the location has non-negative x and y values.
     */
    bool isValid() const {
        return x >= 0 && y >= 0;
    }
};

#endif // LOCATION_H
