#ifndef NODE_H
#define NODE_H

#include "CityComponent.h"
#include "Location.h"
#include "Transport.h"

#include <vector>
#include <unordered_map>
#include <memory>

class Node{
	public:
	Location location;
	CityComponent* component;
	std::unordered_map<Node*, std::unique_ptr<Transport>> connections; // Connections to other nodes with transport types

	Node(int x, int y);

	Node(Node&&) = default;
    Node& operator=(Node&&) = default;
    Node(const Node&) = delete;
    Node& operator=(const Node&) = delete;

	void addConnection(Node* node, std::unique_ptr<Transport> transport);

	CityComponent* getComponent() const;

	void setComponent(CityComponent* comp);

	const Location& getLocation() const;
};

#endif