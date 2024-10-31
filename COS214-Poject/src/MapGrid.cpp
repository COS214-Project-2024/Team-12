// MapGrid.cpp
#include "MapGrid.h"
#include "Node.h"
#include <iostream>

MapGrid::MapGrid(int width, int height) : width(width), height(height) {
    std::cout << "Starting grid initialization..." << std::endl;
    
    // First, reserve space for the rows
    grid.resize(height);
    
    // Then initialize each row and its nodes
    for (int y = 0; y < height; y++) {
        // Create a new vector for this row with 'width' columns
        std::vector<std::unique_ptr<Node>> row;
        row.reserve(width);
        
        // Fill the row with nodes
        for (int x = 0; x < width; x++) {
            row.push_back(std::make_unique<Node>(x, y));
        }
        
        // Move the row into place
        grid[y] = std::move(row);
    }
    
    std::cout << "Grid initialization complete: " << width << "x" << height << std::endl;
}

Node* MapGrid::getNode(int x, int y) const {
    if (x >= 0 && x < width && y >= 0 && y < height && grid[y][x]) {
        return grid[y][x].get();
    }
    std::cout << "Warning: Attempted to access invalid node at (" << x << "," << y << ")" << std::endl;
    return nullptr;
}

void MapGrid::placeComponent(CityComponent* component, int x, int y) {
    std::cout << "Attempting to place component at (" << x << "," << y << ")" << std::endl;
    
    if (!component) {
        std::cout << "Error: Null component" << std::endl;
        return;
    }

    if (x < 0 || x >= width || y < 0 || y >= height) {
        std::cout << "Error: Out of bounds coordinates (" << x << "," << y << ")" << std::endl;
        return;
    }

    Node* node = getNode(x, y);
    if (!node) {
        std::cout << "Error: Could not access node at (" << x << "," << y << ")" << std::endl;
        return;
    }

    if (node->getComponent()) {
        std::cout << "Error: Location already occupied at (" << x << "," << y << ")" << std::endl;
        return;
    }

    node->setComponent(component);
    component->setLocation(x, y);
    std::cout << "Successfully placed component at (" << x << "," << y << ")" << std::endl;
}