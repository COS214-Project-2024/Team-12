#ifndef MONUMENT_H
#define MONUMENT_H

#include "LandMark.h"

/**
 * @brief Represents a Monument, a type of LandMark with specific characteristics and utilities.
 */
class Monument : public LandMark {
public:
    /**
     * @brief Default constructor for Monument.
     */
    Monument() = default;

    /**
     * @brief Constructs a Monument with specified type, visitor capacity, price, and utility connections.
     * 
     * @param type The type of the monument.
     * @param capacity The visitor capacity of the monument.
     * @param price The price or cost associated with the monument.
     * @param water Shared pointer to the water utility flyweight.
     * @param power Shared pointer to the power utility flyweight.
     * @param waste Shared pointer to the waste management utility flyweight.
     * @param sewage Shared pointer to the sewage management utility flyweight.
     */
    Monument(const std::string& type, int capacity, double price, 
             std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
             std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage);

    /**
     * @brief Destructor for Monument.
     */
    ~Monument();

    /**
     * @brief Displays the status of the Monument, including its type, capacity, price, and utilities.
     */
    void displayStatus();

    /**
     * @brief Clones the Monument, creating a unique pointer to a new Monument with identical properties.
     * 
     * @return std::unique_ptr<LandMark> A unique pointer to the cloned Monument object.
     */
    std::unique_ptr<LandMark> clone() const;

    /**
     * @brief Retrieves the building type for this Monument.
     * 
     * @return std::string A string representing the building type, which is "Monument".
     */
    std::string getBuildingType() const;
};

#endif
