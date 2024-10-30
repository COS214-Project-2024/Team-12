//CONCRETE PRODUCT/PROTOTYPE
#ifndef TRAINS_H
#define TRAINS_H

#include <memory>
#include <string>

#include "Transport.h"

class Trains : public Transport{
private:
    int cargoCapacity;
    double railwayLength;
    int numberOfStations;
public:
    Trains(int cap, double cost, double maintenanceC, std::string name, int cargoC, double railwayL, int numOfStations);
    std::unique_ptr<Transport> clone() const;
};
#endif