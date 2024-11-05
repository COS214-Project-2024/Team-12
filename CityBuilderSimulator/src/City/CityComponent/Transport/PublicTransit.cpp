#include <iostream>
#include <string>
//updated variables
#include "PublicTransit.h"

PublicTransit::PublicTransit(int cap, double cost, double maintenanceC, std::string name, int passengerC, int freqOfOperation) : Transport(5000, 400000.00, 20000.00, "Public Transit") {
    this->passengerCapacity = 200;
    this->frequencyOfOperation = 5;
}

std::unique_ptr<Transport> PublicTransit::clone() const {
    return std::make_unique<PublicTransit>(*this);

}


