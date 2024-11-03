// Location.h
#ifndef LOCATION_H
#define LOCATION_H

#include <cmath>

struct Location {
    int x, y;
    
    Location() : x(0), y(0) {}
    Location(int xCoord, int yCoord) : x(xCoord), y(yCoord) {}
    
    bool operator==(const Location& other) const {
        return x == other.x && y == other.y;
    }
     bool operator!=(const Location& other) const {
        return !(*this == other);
    }
    double distanceTo(const Location& other) const {
        return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));
    }
};

#endif