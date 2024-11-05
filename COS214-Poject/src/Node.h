#ifndef NODE_H
#define NODE_H

#include "CityComponent.h"
#include "Location.h"
#include "Transport.h"

#include <vector>
#include <unordered_map>
#include <memory>

/**
 * @brief Represents a node within the city grid, which holds a location, an optional city component,
 * and connections to other nodes via transport methods.
 */
class Node {
public:
    Location location;  ///< Location of the node on the city grid.
    CityComponent* component;  ///< Pointer to a city component assigned to this node.
    std::unordered_map<Node*, std::unique_ptr<Transport>> connections; ///< Connections to neighboring nodes with transport types.

    /**
     * @brief Constructs a Node with specified x and y coordinates.
     * 
     * @param x The x-coordinate of the node.
     * @param y The y-coordinate of the node.
     */
    Node(int x, int y);

    // Move constructor and move assignment operator
    Node(Node&&) = default;
    Node& operator=(Node&&) = default;

    // Deleted copy constructor and copy assignment operator
    Node(const Node&) = delete;
    Node& operator=(const Node&) = delete;

    /**
     * @brief Adds a connection from this node to another node using a specified transport type.
     * 
     * @param node Pointer to the node to connect to.
     * @param transport Unique pointer to the Transport type for the connection.
     */
    void addConnection(Node* node, std::unique_ptr<Transport> transport);

    /**
     * @brief Retrieves the CityComponent associated with this node.
     * 
     * @return CityComponent* Pointer to the component in this node, or nullptr if none is set.
     */
    CityComponent* getComponent() const;

    /**
     * @brief Sets the CityComponent for this node.
     * 
     * @param comp Pointer to the CityComponent to be assigned to this node.
     */
    void setComponent(CityComponent* comp);

    /**
     * @brief Gets the location of the node.
     * 
     * @return const Location& Reference to the node's location.
     */
    const Location& getLocation() const;
};

#endif // NODE_H
