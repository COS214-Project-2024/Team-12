#include "MapGrid.h"
#include "Node.h"
#include "Transport.h"

#include <memory>
#include <vector>

MapGrid::MapGrid(int width, int height) : width(width), height(height) {}

void MapGrid::initializeGrid()
{
	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			grid[y][x] = std::make_unique<Node>(x, y);
		}
	}
}

Node *MapGrid::getNode(int x, int y)
{
	if (x >= 0 && x < width && y >= 0 && y < height)
	{
		return grid[y][x].get();
	}
	return nullptr;
}

void MapGrid::connectNodes(const Location &start, const Location &end, std::unique_ptr<Transport> transport)
{
	Node *startNode = getNode(start.x, start.y);
	Node *endNode = getNode(end.x, end.y);
	if (startNode && endNode)
	{
		startNode->addConnection(endNode, std::move(transport));
		endNode->addConnection(startNode, std::make_unique<Transport>(*transport)); // Bi-directional
	}
}

bool MapGrid::isAdjacent(const Location& loc1, const Location& loc2){

	int dx = std::abs(loc1.x - loc2.x);
	int dy = std::abs(loc1.y - loc2.y);
	return (dx <= 1 && dy <= 1) && !(dx == 0 && dy == 0);
}

void MapGrid::placeComponent(CityComponent* component, int x, int y) {
    if (x < 0 || x >= width || y < 0 || y >= height) {
        std::cout << "Error: Coordinates (" << x << ", " << y << ") are out of bounds.\n";
        return;
    }

    Node* node = grid[y][x].get();

    if (node->getComponent() != nullptr) {
        std::cout << "Error: Location (" << x << ", " << y << ") is already occupied.\n";
        return;
    }

    node->setComponent(component);
    component->setLocation(x, y);  // Update the component’s location
    std::cout << "Component placed at (" << x << ", " << y << ")\n";
}

