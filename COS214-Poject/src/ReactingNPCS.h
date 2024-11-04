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

    virtual ~ReactingNPCS();

     ReactingNPCS(const ReactingNPCS& other);  // Copy constructor for deep copy

    void update() override;

    void changeState(NPCState *newState);
    NPCState* getState()
    {
        return state;
    }

    NPCObserver* clone() override;
private:
    NPCState *state;
};

#endif