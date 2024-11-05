#ifndef PARK_H
#define PARK_H

#include "LandMark.h"

/**
 * @brief Represents a park in the city simulation.
 * 
 * The Park class inherits from the LandMark class and includes
 * details about the park's type, capacity, price, and utility connections.
 */
class Park : public LandMark {
public:
    /// Default constructor for the Park class.
    Park() = default;

    /**
     * @brief Constructs a Park object with specified parameters.
     * 
     * Initializes the Park with a specified type, capacity, price, and utility connections.
     * 
     * @param type The type of the park.
     * @param capacity The maximum visitor capacity of the park.
     * @param price The cost associated with the park.
     * @param water A shared pointer to the water utility.
     * @param power A shared pointer to the power utility.
     * @param waste A shared pointer to the waste management utility.
     * @param sewage A shared pointer to the sewage management utility.
     */
    Park(const std::string& type, int capacity, double price,
         std::shared_ptr<UtilityFlyweight> water, 
         std::shared_ptr<UtilityFlyweight> power,
         std::shared_ptr<UtilityFlyweight> waste, 
         std::shared_ptr<UtilityFlyweight> sewage);

    /// Destructor for the Park object.
    ~Park();

    /**
     * @brief Displays the current status of the Park.
     * 
     * Outputs the name, capacity, price, and status of the park's utilities.
     */
    void displayStatus() override;

    /**
     * @brief Creates a clone of the Park object.
     * 
     * @return A unique pointer to a new Park object that is a copy of this one.
     */
    std::unique_ptr<LandMark> clone() const;

    /**
     * @brief Retrieves the building type of the park.
     * 
     * @return A string representing the building type, which is "Park".
     */
    std::string getBuildingType() const;
};

#endif
