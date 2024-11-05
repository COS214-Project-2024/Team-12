//CONCRETE PRODUCT/PROTOTYPE
#ifndef ROADS_H
#define ROADS_H

#include <iostream>
#include <string>

#include "Transport.h"
//introduced enum class
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
    Roads(int cap, double cost, double maintenanceC, std::string name, int trafficC, roadType road);
    std::unique_ptr<Transport> clone() const;

};
#endif