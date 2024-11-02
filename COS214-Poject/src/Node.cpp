#include "Node.h"

#include <unordered_map>
#include <memory>

Node::Node(int x, int y) : location(x,y), component(nullptr) {}

void Node::addConnection(Node* node, std::unique_ptr<Transport> transport){
	if(node) {
		connections[node] = std::move(transport);
	}
}

CityComponent* Node::getComponent() const{
	return component;
}

void Node::setComponent(CityComponent* comp){
	component = comp;
}

const Location& Node::getLocation() const {
	return location;
}