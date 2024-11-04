#ifndef REACTING_NPC_H
#define REACTING_NPC_H

#include "NPCObserver.h"
#include "NPCState.h"
#include "NeutralState.h"

#include <iostream>
#include <string>

class NPCState;

/**
 * @brief Concrete observer class representing an NPC that reacts to state changes.
 * 
 * ReactingNPCS observes changes in the game environment and responds by changing its state.
 * It utilizes a state pattern to manage different NPC states and behaviors.
 */
class ReactingNPCS : public NPCObserver {
public:
    /**
     * @brief Default constructor initializing the NPC in a neutral state.
     */
    ReactingNPCS();

    /**
     * @brief Destructor for cleaning up dynamically allocated state.
     */
    virtual ~ReactingNPCS();

    /**
     * @brief Copy constructor for deep copying ReactingNPCS objects.
     * @param other The other ReactingNPCS instance to copy.
     */
    ReactingNPCS(const ReactingNPCS& other);

    /**
     * @brief Updates the NPC's state based on observed changes.
     * 
     * This method is called when there is a change in the observed subject, allowing the NPC
     * to respond accordingly.
     */
    void update() override;

    /**
     * @brief Changes the current state of the NPC.
     * @param newState Pointer to the new NPCState to transition into.
     */
    void changeState(NPCState *newState);
    NPCState* getState()
    {
        return state;
    }

    /**
     * @brief Clones the NPC, creating a copy with the same state.
     * @return A pointer to the cloned NPCObserver object.
     */
    NPCObserver* clone() override;

private:
    NPCState *state; ///< Current state of the NPC
};

#endif // REACTING_NPC_H
