#ifndef NEUTRAL_STATE_H
#define NEUTRAL_STATE_H

#include "NPCManager.h"
#include "NPCState.h"

class NeutralState : public NPCState{
	public:
	void handle() override;
};

#endif