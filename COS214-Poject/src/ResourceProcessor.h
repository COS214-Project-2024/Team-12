#ifndef RESOURCEPROCESSOR_H
#define RESOURCEPROCESSOR_H

/**
 * @brief Abstract base class for processing and managing resources.
 *
 * The ResourceProcessor class defines the interface for processing,
 * storing, and displaying resource-related information. Derived classes
 * will implement the specific processing and storage logic for different types of resources.
 */
class ResourceProcessor {
public:
    /**
     * @brief Processes a specified amount of resource.
     * @param amount The amount of resource to process.
     */
    virtual void process(int amount) = 0;

    /**
     * @brief Stores a specified amount of resource.
     * @param amount The amount of resource to store.
     */
    virtual void store(int amount) = 0;

    /**
     * @brief Displays the current status of the resource processor.
     *
     * This function provides information about the processor's
     * current state, typically including storage and processing details.
     */
    virtual void display() const = 0;

    /**
     * @brief Retrieves the current amount of resource in storage.
     * @return int The current storage level.
     */
    virtual int getCurrentStorage() const = 0;

    /// Virtual destructor for ResourceProcessor, allowing derived classes to clean up resources.
    virtual ~ResourceProcessor() = default;
};

#endif // RESOURCEPROCESSOR_H
