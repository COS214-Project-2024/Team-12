#ifndef DONATION_STATE_H
#define DONATION_STATE_H

#include "NPCManager.h"
#include "NPCState.h"

class DonationState : public NPCState{
	public:
	void handle() override;
};

#endif