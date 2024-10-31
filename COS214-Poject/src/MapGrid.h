#ifndef MAP_GRID_H
#define MAP_GRID_H

#include "Node.h"
#include "Transport.h"
#include <memory>
#include <vector>

class MapGrid{
	private:
	int width;
	int height;
	std::vector<std::vector<std::unique_ptr<Node>>> grid;

	public:
	MapGrid(int width, int height);

	void initializeGrid();

	Node* getNode(int x, int y) const;

	void connectNodes(const Location& start, const Location& end, std::unique_ptr<Transport> transport);

	bool isAdjacent(const Location& loc1, const Location& loc2);

	void placeComponent(CityComponent* component, int x, int y);
};

#endif