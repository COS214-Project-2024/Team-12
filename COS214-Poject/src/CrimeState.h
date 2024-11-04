/**
 * @file CrimeState.h
 * @brief Declaration of the CrimeState class, representing a state of crime among NPCs.
 */

#ifndef CRIME_STATE_H
#define CRIME_STATE_H

#include "NPCManager.h"
#include "NPCState.h"
#include <string>

/**
 * @class CrimeState
 * @brief Represents the crime state for NPCs, impacting their behavior and the city's overall conditions.
 * 
 * In this state, NPCs behave in a manner that reflects an increase in crime rates, potentially affecting city statistics.
 */
class CrimeState : public NPCState {
public:
    /**
     * @brief Handles actions specific to the crime state.
     * 
     * Executes the behavior associated with NPCs in the crime state, impacting relevant NPC or city statistics.
     */
    void handle() override;

    /**
     * @brief Retrieves the name of the current state.
     * 
     * @return A string representing the name of this state, "Crime".
     */
    std::string getStateName() override;

    /**
     * @brief Creates a copy of the current CrimeState instance.
     * 
     * @return A pointer to a newly cloned CrimeState object.
     */
    NPCState* clone() const override;

    /**
     * @brief Default destructor for CrimeState.
     */
    ~CrimeState() override = default;
};

#endif
