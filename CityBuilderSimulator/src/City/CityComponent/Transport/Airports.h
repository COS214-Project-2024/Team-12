//CONCRETE PRODUCT/PROTOTYPE
#ifndef AIRPORTS_H
#define AIRPORTS_H

#include <iostream>
#include <memory>
#include <string>
//added functionality
#include "Transport.h"
class Airports : public Transport {
private:
    int numberOfFlightsPerDay;
    double runwayLength;
    int terminalCapacity;
public:
    Airports(int cap, double cost, double maintenanceC, std::string name,int numOfFlightspDay, double runwayL, int terminalC);
    std::unique_ptr<Transport> clone() const;

};
#endif