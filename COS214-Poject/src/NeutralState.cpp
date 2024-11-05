#include "NeutralState.h"
#include "NPCManager.h"

#include <iostream>
#include <string>

/**
 * @brief Destructor for the NeutralState class.
 */
NeutralState::~NeutralState() = default;

/**
 * @brief Handles behavior in the Neutral state.
 * 
 * In the Neutral state, no specific action is taken, serving as a middle ground
 * to prevent unnecessary state changes.
 */
void NeutralState::handle() {
    std::cout << "We are in the neutral state; I guess we do nothing here\n";
}

/**
 * @brief Retrieves the name of the state.
 * 
 * @return std::string The name of the Neutral state as "NeutralState".
 */
std::string NeutralState::getStateName() {
    return "NeutralState";
}

/**
 * @brief Creates a copy of the current NeutralState object.
 * 
 * @return NPCState* A pointer to a new NeutralState object cloned from the current instance.
 */
NPCState* NeutralState::clone() const {
    return new NeutralState(*this);
}
