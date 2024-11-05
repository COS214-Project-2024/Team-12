#ifndef DONATION_STATE_H
#define DONATION_STATE_H

#include "NPCManager.h"
#include "NPCState.h"

#include <string>

/**
 * @class DonationState
 * @brief Represents the state where NPCs are in a donation mood.
 * 
 * This class handles the logic for NPCs when they are willing to donate,
 * affecting the city's economy and happiness levels.
 */
class DonationState : public NPCState {
public:
    /**
     * @brief Handles the donation logic for NPCs in this state.
     * 
     * This method is called to process the actions related to NPC donations,
     * including any impacts on the game state or economy.
     */
    void handle() override;

    /**
     * @brief Gets the name of the current state.
     * 
     * @return A string representing the name of the donation state.
     */
    std::string getStateName() override;

    /**
     * @brief Clones the current DonationState instance.
     * 
     * @return A pointer to a new DonationState instance that is a copy of this state.
     */
    NPCState* clone() const override;

    /**
     * @brief Destructor for the DonationState class.
     * 
     * Cleans up any resources associated with the DonationState.
     */
    ~DonationState() override;
};

#endif
