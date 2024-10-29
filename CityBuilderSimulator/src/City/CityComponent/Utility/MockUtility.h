#ifndef MOCKUTILITY_H
#define MOCKUTILITY_H

#include "UtilityFlyweight.h"
#include <iostream>

class MockUtility : public UtilityFlyweight {
public:
    MockUtility(const std::string& n, double c, int cap, double radius, bool operational, int l, int consumption, const std::map<std::string, int>& resources);
    void connect(double distance);
    std::unique_ptr<UtilityFlyweight> clone() const ;
    bool isConnected() const;
private:
    bool connected;
};


#endif