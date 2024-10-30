#include "Location.h"

Location::Location(int xCoord, int yCoord) : x(xCoord), y(yCoord) {}

bool Location::operator==(const Location& other) const{
	return x == other.x && y == other.y;
}