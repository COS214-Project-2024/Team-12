#ifndef NEUTRAL_STATE_H
#define NEUTRAL_STATE_H

#include "NPCManager.h"
#include "NPCState.h"

#include <string>

/**
 * @class NeutralState
 * @brief Represents a neutral state in which no specific action is taken by the NPC.
 * 
 * The NeutralState class is part of the NPC state management system and serves as
 * a middle ground or idle state, preventing unnecessary state changes.
 */
class NeutralState : public NPCState {
public:
    /**
     * @brief Handles behavior specific to the neutral state.
     * 
     * In the neutral state, no specific action is performed. It serves as an idle
     * state between other actionable states.
     */
    void handle() override;

    /**
     * @brief Retrieves the name of the neutral state.
     * 
     * @return std::string The name of the state as "NeutralState".
     */
    std::string getStateName() override;

    /**
     * @brief Clones the current NeutralState instance.
     * 
     * @return NPCState* A pointer to a new NeutralState instance cloned from the current instance.
     */
    NPCState* clone() const override;

    /**
     * @brief Destructor for the NeutralState class.
     */
    ~NeutralState() override;
};

#endif
