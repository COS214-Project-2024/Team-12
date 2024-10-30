//CONCRETE PRODUCT/PROTOTYPE
#ifndef PUBLICTRANSIT_H
#define PUBLICTRANSIT_H

#include <iostream>
#include <memory>
#include <string>

#include "Transport.h"

class PublicTransit : public Transport{

private:
    int passengerCapacity;
    int frequencyOfOperation;
public:
    PublicTransit(int cap, double cost, double maintenanceC, std::string name, int passengerC, int freqOfOperation);
    std::unique_ptr<Transport> clone() const;

};
#endif