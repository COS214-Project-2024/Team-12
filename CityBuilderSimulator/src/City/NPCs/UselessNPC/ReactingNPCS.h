#ifndef REACTING_NPC_H
#define REACTING_NPC_H

#include "NPCObserver.h"
#include "NPCState.h"
#include "NeutralState.h"

#include <iostream>
#include <string>

class NPCState;

class ReactingNPCS : public NPCObserver
{
public:
    ReactingNPCS();

    ~ReactingNPCS();

    void update() override;

    void changeState(NPCState *newState)
    {
        // Decrement the count for the current (old) state
        NPCManager::getInstance().decrementCount(state->getStateName());

        // Delete the old state and set the new state
        delete state;
        state = newState;

        // Increment the count for the new state
        NPCManager::getInstance().incrementCount(state->getStateName());
    }
private:
    NPCState *state;
};

#endif