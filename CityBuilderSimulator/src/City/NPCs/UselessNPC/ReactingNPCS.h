#ifndef REACTING_NPC_H
#define REACTING_NPC_H

#include "NPCObserver.h"
#include "NPCState.h"
#include "NeutralState.h"

#include <iostream>
#include <string>

class NPCState;

class ReactingNPCS : public NPCObserver{
	public:
	ReactingNPCS();

    ~ReactingNPCS();

	void update() override;


	private:
    void changeState(NPCState* newState) {
        delete state;
        state = newState;
    }

    NPCState* state;
};

#endif