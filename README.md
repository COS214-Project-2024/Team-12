# Ctrl+Build Team
Team-12's description.
City Simulation Project.
This project is a city simulation software that models various aspects of urban management, including residential and commercial buildings, infrastructure, utilities, and citizen interactions. It is built with C++ and demonstrates several design patterns to handle complex city operations and citizen dynamics effectively.

Table of Contents
Overview
Features
Design Patterns Used
Project Structure
Setup Instructions
Usage
Examples
Future Improvements
Overview
The City Simulation Project is designed to provide an interactive experience where users can build, manage, and simulate a city. Key aspects like tax collection, utilities management, citizen happiness, and economic growth are implemented, allowing users to observe how different actions impact the city’s overall well-being.

The software applies three main design patterns: Singleton, Observer, and State. These patterns support complex interactions within the city, ensuring that changes propagate seamlessly and that citizens react to the city's changing conditions.

Features
City Building and Management: Add and manage residential, commercial, and public service buildings.
Utility System: Connect water, power, sewage, and waste management utilities to various zones and buildings.
Dynamic Citizen Reactions: Citizens react to changes in utilities, policies, and overall city environment.
Economic System: Manage tax collection, resource processing, and citizen-driven donations based on their happiness level.

Design Patterns Used
Singleton Pattern
Usage: Centralized access to shared city data (e.g., citizen information and government attributes) across multiple classes.
Purpose: Ensures that all components access a single source of truth for shared data, reducing redundancy and improving efficiency.
Observer Pattern
Usage: Citizens, represented as observers, respond to changes within the city, such as upgrades to utilities or environmental changes.
Purpose: Allows citizens to automatically adjust their state based on city conditions, improving scalability and maintainability.

State Pattern
Usage: Citizens can exist in various states (e.g., Neutral, Donation, Revolt, Productive), each affecting their behavior and the city’s resources.
Purpose: Provides flexibility in modeling citizen behavior and responses to city changes, creating a dynamic environment.

Factory Method Pattern
Usage: The Factory Method is used to create various types of infrastructure components such as residential buildings, commercial buildings, and transport modes.
Purpose: Each building and transport type has its own factory class, allowing for the creation of specific components (e.g., HouseFactory, ShopsFactory, TrainsFactory). This enables easy addition of new types of buildings or transport modes without modifying existing code.
Abstract Factory Pattern
Usage: The Abstract Factory is applied to create different families of resources, including income-generating and construction resources, as well as to provide utilities.
Purpose: It supports the creation of cohesive resource families through specific factories, such as StoneFactory and WoodFactory, which generate consistent resource types. This pattern is also used for utilities to provide consistent access to utility types like water, power, sewage, and waste management through the UtilityFactory.

Prototype Pattern
Usage: The Prototype pattern is used for creating complex or frequently reused objects, particularly in the citizen and resource management systems.
Purpose: Citizens are instantiated from prototypes instead of repeated manual construction, ensuring consistent properties and reducing instantiation costs. Resources, such as Steel, Wood, and Stone, are also created by cloning existing instances with adjusted attributes. This reduces memory allocation time and ensures that new resources maintain the same properties as the original prototypes.
Composite Pattern
Usage: The Composite pattern structures the city as a hierarchical collection of components. CityComposite represents the entire city, containing ZoneComposite elements, which in turn contain individual CityComponent elements, like buildings.
Purpose: This pattern allows the entire city to be managed as a single entity, with composite objects (zones and city) consisting of smaller parts (individual buildings and utilities). It simplifies operations such as tax collection, status display, and resource distribution by enabling them to be applied across the entire hierarchy.

Flyweight Pattern
Usage: The Flyweight pattern is used to manage utilities efficiently by sharing their common attributes among multiple city components.
Purpose: Utilities such as water supply, power, sewage, and waste management often have identical properties across multiple buildings or zones. The Flyweight pattern stores these shared properties in a UtilityFlyweight object, allowing many buildings to reference the same utility instance rather than creating multiple copies. This approach conserves memory and simplifies updates, as changes to a shared utility are automatically reflected across all components that use it.
