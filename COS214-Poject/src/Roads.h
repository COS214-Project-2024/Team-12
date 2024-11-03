//CONCRETE PRODUCT/PROTOTYPE
#ifndef ROADS_H
#define ROADS_H

#include <iostream>
#include <string>

#include "Transport.h"

enum class roadType {
    Highway,
    Street,
    Avenue,
    Boulevard,
    Alley,
    Roundabout,
    Bridge,
    Tunnel,
    PedestrianPath
};

class Roads : public Transport {
private:
    int trafficCapacity;
    roadType road;
public:
    //Roads(int cap, double cost, double maintenanceC, std::string name, int trafficC, roadType road);
    std::unique_ptr<Transport> clone() const;

    double getSpeed() const override;
    double getCost() const override;
    double getMaintainanceCost() const override;
    double getCapacity() const override;
    std::string getType() const override;

    Roads() {
    // Constructor body (can be empty)
}

~Roads() {
    // Destructor body (can be empty)
}

};
#endif