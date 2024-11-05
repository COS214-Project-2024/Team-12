#ifndef NPC_STATE_H
#define NPC_STATE_H

#include <string>

/**
 * @brief Abstract base class representing a state in the NPC state machine.
 * 
 * The NPCState class provides an interface for NPC states, allowing 
 * each state to define its own behavior, retrieve its name, and be cloned.
 */
class NPCState {
public:
    /**
     * @brief Pure virtual function to handle the behavior associated with the state.
     * 
     * Derived classes must implement this function to define the specific actions 
     * associated with each state.
     */
    virtual void handle() = 0;

    /**
     * @brief Pure virtual function to get the name of the state.
     * 
     * Provides a string representing the name of the state.
     * 
     * @return std::string Name of the state.
     */
    virtual std::string getStateName() = 0;

    /**
     * @brief Pure virtual function to clone the state.
     * 
     * Allows derived state types to create a copy of themselves.
     * 
     * @return NPCState* Pointer to the cloned state instance.
     */
    virtual NPCState* clone() const = 0;

    /**
     * @brief Virtual destructor.
     * 
     * Ensures that derived classes are properly destroyed.
     */
    virtual ~NPCState() = default;
};

#endif // NPC_STATE_H
