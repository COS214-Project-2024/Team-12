implementing tax collector from residential and commercial building as they are concrete elements in the visitor design pattern
Tax Collector Functionality
Overview
The Tax Collector functionality is a central part of the taxation system in the CityBuilderSimulator project. This system enables the simulation of tax collection from residential and commercial buildings within the city, using the Visitor Pattern to determine the tax amount based on building type. Taxes collected contribute to the city's overall revenue, which supports further development and management.

How It Works
The taxCollector class is responsible for visiting each building type—ResidentialBuilding and CommercialBuilding—and collecting taxes based on the building's specific attributes, such as number of residents, income, or property value. This is achieved by implementing the visit method in taxCollector, which processes each building type differently.

Key Classes
taxCollector: The main class responsible for collecting taxes. It uses the Visitor Pattern to interact with ResidentialBuilding and CommercialBuilding objects.
ResidentialBuilding and CommercialBuilding: Concrete classes representing building types within the city. Each building type implements an accept method, allowing the taxCollector to visit and perform tax collection.
Government: Manages the city's finances and receives the taxes collected by the taxCollector.
Class and Method Details
taxCollector Class
Attributes:

std::shared_ptr<Government> government: A pointer to the central government entity, which receives the collected taxes.
taxPayed: A boolean attribute in each ResidentialBuilding that tracks whether the tax for that building has been paid.
Methods:

visit(ResidentialBuilding* building): Collects tax from a residential building. The amount may be based on attributes like the number of bedrooms, location, or other valuation criteria.
visit(CommercialBuilding* building): Collects tax from a commercial building. The amount may be based on metrics like business income, size, or other financial factors.
resetTaxStatus(): Resets the taxPayed status for each residential building after a certain time, allowing them to be taxed again during the next cycle.
ResidentialBuilding and CommercialBuilding Classes
Methods:
accept(taxCollector* collector): Accepts the taxCollector as a visitor, allowing it to collect taxes from the building.
payTax(): Marks the tax status of the building as paid, preventing further collections until the next cycle.
resetTaxPayed(): Resets the taxPayed status, allowing taxes to be collected in subsequent cycles.