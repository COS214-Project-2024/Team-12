#include "Node.h"

#include <unordered_map>
#include <memory>

/**
 * @brief Constructs a Node with a specific location.
 * 
 * @param x The x-coordinate of the node.
 * @param y The y-coordinate of the node.
 */
Node::Node(int x, int y) : location(x, y), component(nullptr) {}

/**
 * @brief Adds a connection from this node to another node.
 * 
 * This function establishes a connection between the current node and the given
 * node using the specified transport method.
 * 
 * @param node Pointer to the destination node.
 * @param transport Unique pointer to the Transport object used for the connection.
 */
void Node::addConnection(Node* node, std::unique_ptr<Transport> transport) {
    if (node) {
        connections[node] = std::move(transport);
    }
}

/**
 * @brief Retrieves the CityComponent associated with this node.
 * 
 * @return CityComponent* Pointer to the component stored in this node.
 */
CityComponent* Node::getComponent() const {
    return component;
}

/**
 * @brief Sets the CityComponent for this node.
 * 
 * @param comp Pointer to the CityComponent to be stored in this node.
 */
void Node::setComponent(CityComponent* comp) {
    component = comp;
}

/**
 * @brief Gets the location of the node.
 * 
 * @return const Location& Reference to the node's location.
 */
const Location& Node::getLocation() const {
    return location;
}
