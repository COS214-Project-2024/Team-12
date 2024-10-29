#ifndef DONATION_STATE_H
#define DONATION_STATE_H

#include "../NPCManager.h"
#include "NPCState.h"

#include <string>

class DonationState : public NPCState{
	public:
	void handle() override;
	std::string getStateName() override;
	NPCState* clone() const override;
};

#endif