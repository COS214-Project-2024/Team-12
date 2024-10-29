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

    void changeState(NPCState *newState);
private:
    NPCState *state;
};

#endif