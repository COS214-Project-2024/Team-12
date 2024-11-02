#ifndef COMMAND_H
#define COMMAND_H

#include <memory>
#include "MapGrid.h"
#include "Location.h"
#include "CityComponent.h"

class Command {
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
    virtual void undo() = 0;
};

class PlaceComponentCommand : public Command {
private:
    MapGrid& grid;
    Location location;
    std::shared_ptr<CityComponent> component;
    std::shared_ptr<CityComponent> previousComponent;

public:
    PlaceComponentCommand(MapGrid& grid, Location loc, std::shared_ptr<CityComponent> comp)
        : grid(grid), location(loc), component(comp) {}

    void execute() override {
        previousComponent = grid.getComponent(location);
        grid.placeComponent(location, component);
    }

    void undo() override {
        grid.placeComponent(location, previousComponent);
    }
};

#endif
