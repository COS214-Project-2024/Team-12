#ifndef REVOLT_STATE_H
#define REVOLT_STATE_H

#include "NPCManager.h"
#include "NPCState.h"

#include <string>

/**
 * @class RevoltState
 * @brief Represents the state of NPCs when they are in revolt.
 * 
 * This state class handles the behavior and actions taken by NPCs when they are revolting
 * due to low satisfaction or poor city conditions.
 */
class RevoltState : public NPCState {
public:
    /**
     * @brief Executes actions specific to the revolt state.
     * 
     * This method defines what happens when NPCs are in revolt,
     * potentially affecting the city’s operations and resources.
     */
    void handle() override;

    /**
     * @brief Retrieves the name of this state.
     * @return std::string The name of the state, typically "Revolt".
     */
    std::string getStateName() override;

    /**
     * @brief Clones the current state, creating a new instance with the same properties.
     * @return NPCState* A pointer to the cloned RevoltState object.
     */
    NPCState* clone() const override;

    /**
     * @brief Destructor for the RevoltState class.
     */
    ~RevoltState() override;
};

#endif // REVOLT_STATE_H
