#include <iostream>
#include<string>

#include "Transport.h"

//Constructor
Transport::Transport(int cap, double cost, double maintenanceC, std::string name) {
    this->capacity = cap;
    this->cost = cost;
    this->maintainanceCost = maintenanceC;
    this->name = name;
}

void Transport::accept(taxCollector* TC)
{

}