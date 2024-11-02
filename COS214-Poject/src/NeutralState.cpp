#include "NeutralState.h"
#include "NPCManager.h"

#include <iostream>
#include <string>

void NeutralState::handle(){
	// do nothing
	std::cout<<"We are in the neutral state I guess we do nothing in here\n";

	//Middle man, state to stop bouncing of states
}

std::string NeutralState::getStateName(){
	return "NeutralState";
}

NPCState* NeutralState::clone() const{
	return new NeutralState(*this);
}