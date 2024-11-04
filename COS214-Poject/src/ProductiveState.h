#ifndef PRODUCTIVE_STATE_H
#define PRODUCTIVE_STATE_H

#include "NPCManager.h"
#include "NPCState.h"

#include <string>

/**
 * @class ProductiveState
 * @brief Represents the productive state of NPCs.
 *
 * This class handles the logic for NPCs that are in a productive state,
 * including the calculation of productivity boosts based on the number of
 * productive NPCs.
 */
class ProductiveState : public NPCState {
public:
    /**
     * @brief Handles the logic for productivity boosts.
     *
     * This method calculates the chance of a productivity boost and applies
     * it to the production rate in the Government class if applicable.
     */
    void handle() override;

    /**
     * @brief Retrieves the name of the productive state.
     * 
     * @return A string representing the name of the state.
     */
    std::string getStateName() override;

    /**
     * @brief Clones the current ProductiveState instance.
     * 
     * @return A pointer to the newly created ProductiveState instance.
     */
    NPCState* clone() const override;

    /**
     * @brief Destructor for the ProductiveState class.
     */
    ~ProductiveState();
};

#endif // PRODUCTIVE_STATE_H
