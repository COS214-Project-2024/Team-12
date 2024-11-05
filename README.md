# Ctrl+Build Team
Team-12's description.
City Simulation Project
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

