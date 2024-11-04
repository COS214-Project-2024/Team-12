#ifndef NPC_OBSERVER_H
#define NPC_OBSERVER_H

#include <string>
#include <vector>

/**
 * @brief Abstract base class for NPC observers.
 * 
 * The NPCObserver class provides an interface for objects that observe changes
 * in NPC states and respond to updates accordingly. It also supports cloning,
 * allowing derived observer types to be duplicated.
 */
class NPCObserver {
public:
    /**
     * @brief Pure virtual function to update the observer with new state information.
     * 
     * Derived classes must implement this function to define their response to updates.
     */
    virtual void update() = 0;

    /**
     * @brief Pure virtual function to clone the observer.
     * 
     * Allows derived observer types to create a copy of themselves.
     * 
     * @return NPCObserver* Pointer to the cloned observer instance.
     */
    virtual NPCObserver* clone() = 0;

    /**
     * @brief Virtual destructor.
     * 
     * Ensures that derived classes are properly destroyed.
     */
    virtual ~NPCObserver() = default;
};

#endif // NPC_OBSERVER_H
