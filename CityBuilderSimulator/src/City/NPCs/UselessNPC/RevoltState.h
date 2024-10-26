#ifndef REVOLT_STATE_H
#define REVOLT_STATE_H

#include "NPCManager.h"
#include "NPCState.h"

class RevoltState : public NPCState{
	public:
	void handle() override;
};

#endif