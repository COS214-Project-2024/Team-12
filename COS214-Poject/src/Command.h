#ifndef COMMAND_H
#define COMMAND_H

#include <memory>
#include "MapGrid.h"
#include "Location.h"
#include "CityComponent.h"

/**
 * @brief Abstract base class representing a command in the command pattern.
 */
class Command {
public:
    /**
     * @brief Virtual destructor for the Command base class.
     */
    virtual ~Command() = default;

    /**
     * @brief Executes the command.
     */
    virtual void execute() = 0;

    /**
     * @brief Undoes the command.
     */
    virtual void undo() = 0;

    /**
     * @brief Clones the command, creating a new unique pointer to a Command.
     * @return A unique pointer to a copy of the command.
     */
    virtual std::unique_ptr<Command> clone() const = 0; 
};

/**
 * @brief Command to place a CityComponent on a MapGrid at a specified Location.
 */
class PlaceComponentCommand : public Command {
private:
    MapGrid& grid; ///< Reference to the MapGrid where the component is placed.
    Location location; ///< The location on the MapGrid for the component.
    std::shared_ptr<CityComponent> component; ///< The component to place on the MapGrid.
    std::shared_ptr<CityComponent> previousComponent; ///< Stores the previous component at the location.

public:
    /**
     * @brief Constructs a PlaceComponentCommand with specified MapGrid, Location, and component.
     * @param grid Reference to the MapGrid.
     * @param loc The location to place the component.
     * @param comp Shared pointer to the CityComponent to be placed.
     */
    PlaceComponentCommand(MapGrid& grid, Location loc, std::shared_ptr<CityComponent> comp)
        : grid(grid), location(loc), component(comp) {}

    /**
     * @brief Executes the command, placing the component on the MapGrid.
     */
    void execute() override {
        previousComponent = grid.getComponent(location);
        grid.placeComponent(location, component);
    }

    /**
     * @brief Undoes the command, restoring the previous component at the location.
     */
    void undo() override {
        grid.placeComponent(location, previousComponent);
    }

    /**
     * @brief Clones the PlaceComponentCommand.
     * @return A unique pointer to a new PlaceComponentCommand instance.
     */
    std::unique_ptr<Command> clone() const override {
        auto cmd = std::make_unique<PlaceComponentCommand>(grid, location, component);
        cmd->previousComponent = previousComponent;
        return cmd;
    }
};

#endif
