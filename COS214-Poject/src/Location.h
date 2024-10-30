#ifndef LOCATION_H
#define LOCATION_H

class Location{
	public:
	int x;
	int y;

	// Default constructor
    Location() : x(0), y(0) {}
	
	Location(int xCoord, int yCoord);
	bool operator==(const Location& other) const;
};

#endif