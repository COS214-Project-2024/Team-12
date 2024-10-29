cmake_minimum_required(VERSION 3.10)
project(CityBuilderSimulator)

# Add include directories
include_directories(src/City)
include_directories(tests)

# Google Test as a subdirectory
add_subdirectory(gtests)
include_directories(gtests/googletest/include)

# Define main application executable
add_executable(MyProject src/main.cpp)

# Define test executable
add_executable(MyTests
    tests/NPCManagerTests.cpp
    tests/ReactingNPCTests.cpp
    tests/NPCStatesTests.cpp
    tests/UtilityFactoryTests.cpp
    tests/UtilityFlyweightTests.cpp
    tests/UtilityDecoratorTests.cpp
    tests/GreenTechnologyDecoratorTests.cpp
    src/City/NPCs/UselessNPC/ReactingNPCS.cpp
	src/City/NPCs/NPCManager.cpp
    src/City/NPCs/UselessNPC/DonationState.cpp
    src/City/NPCs/UselessNPC/RevoltState.cpp
    src/City/NPCs/UselessNPC/ProductiveState.cpp
    src/City/NPCs/UselessNPC/CrimeState.cpp
    src/City/NPCs/UselessNPC/NeutralState.cpp
	src/City/Government.cpp 
    src/City/CityComponent/Utility/AdvancedTechnologyDecorator.cpp
    src/City/CityComponent/Utility/GreenTechnologyDecorator.cpp
    src/City/CityComponent/Utility/PowerPlant.cpp
    src/City/CityComponent/Utility/SewageSystem.cpp
    src/City/CityComponent/Utility/UtilityDecorator.cpp
    src/City/CityComponent/Utility/UtilityFactory.cpp
    src/City/CityComponent/Utility/UtilityFlyweight.cpp
    src/City/CityComponent/Utility/WasteManagement.cpp
    src/City/CityComponent/Utility/WaterSupply.cpp
    src/City/CityComponent/Utility/MockUtility.cpp
    src/City/CityComponent/Utility/MockCityComposite.cpp
    src/City/CityComponent/Residential/Estate.cpp
    src/City/CityComponent/Residential/Flat.cpp
    src/City/CityComponent/Residential/House.cpp
    src/City/CityComponent/Residential/ResidentialBuilding.cpp
    src/City/CityComponent/Residential/ResidentialZoneComposite.cpp
    src/City/CityComponent/Residential/Townhouse.cpp
    src/City/CityComponent/CityComposite/CityComposite.cpp
)

# Link Google Test to the test executable
target_link_libraries(MyTests gtest gtest_main)
