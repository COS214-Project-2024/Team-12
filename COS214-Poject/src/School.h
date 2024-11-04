#ifndef SCHOOL_H
#define SCHOOL_H

#include "PublicService.h"
#include <string>
#include <memory>

class School : public PublicService {
private:
    std::string status;
public:
    School(std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power, 
           std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage, 
           const std::string& buildingStatus);
    
    ~School() override = default;

    // Implementation of the provideService method
    void provideService() override;

    // Display methods
    void displayStatus() override;
    char getDisplaySymbol() const override;
};

#endif
