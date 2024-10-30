#include <iostream>
#include <string>
#include "Trains.h"

Trains::Trains(int cap, double cost, double maintenanceC, std::string name, int cargoC, double railwayL, int numOfStations): Transport(120, 5000000.00, 50000.00, "Train") {
        this->cargoCapacity = cargoC;
        this->railwayLength = railwayL;
        this->numberOfStations = numOfStations;
}

std::unique_ptr<Transport> Trains::clone() const {
    return std::make_unique<Trains>(*this);

}