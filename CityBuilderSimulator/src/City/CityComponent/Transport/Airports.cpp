#include <iostream>
#include <string>

#include "Airports.h"

Airports::Airports(int cap, double cost, double maintenanceC, std::string name,int numOfFlightspDay, double runwayL, int terminalC) 
    : Transport(5000, 10000000.00, 300000.00,"Airport") {
        this->numberOfFlightsPerDay = numberOfFlightsPerDay;
        this->runwayLength = runwayL;
        this->terminalCapacity = terminalC;
}

std::unique_ptr<Transport> Airports::clone() const {
    return std::make_unique<Airports>(*this);

}

