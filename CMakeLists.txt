# Set the minimum version of CMake
cmake_minimum_required(VERSION 3.10)

# Set the project name
project(CitySimulator)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find threading package explicitly
find_package(Threads REQUIRED)

# Add the source files for city_simulator
add_executable(city_simulator
    COS214-Poject/src/main.cpp
    COS214-Poject/src/CityComposite.cpp
    COS214-Poject/src/GameState.cpp
    COS214-Poject/src/MapGrid.cpp
    COS214-Poject/src/CityComponent.cpp
    COS214-Poject/src/ResidentialBuilding.cpp
    COS214-Poject/src/CommercialBuilding.cpp
    COS214-Poject/src/Industry.cpp
    COS214-Poject/src/House.cpp
    COS214-Poject/src/UtilityFlyweight.cpp
    COS214-Poject/src/UtilityFactory.cpp
    COS214-Poject/src/WaterSupply.cpp
    COS214-Poject/src/PowerPlant.cpp
    COS214-Poject/src/SewageSystem.cpp
    COS214-Poject/src/WasteManagement.cpp
    COS214-Poject/src/IncomeResourceProduct.cpp
    COS214-Poject/src/ConstructionResourceProduct.cpp
    COS214-Poject/src/NPCSystem.cpp
    COS214-Poject/src/Government.cpp
    COS214-Poject/src/NPCManager.cpp
    COS214-Poject/src/ReactingNPCS.cpp
    COS214-Poject/src/NeutralState.cpp
    COS214-Poject/src/DonationState.cpp
    COS214-Poject/src/CrimeState.cpp
    COS214-Poject/src/ProductiveState.cpp
    COS214-Poject/src/RevoltState.cpp
    COS214-Poject/src/Flat.cpp
    COS214-Poject/src/TownHouse.cpp
    COS214-Poject/src/ZoneComposite.cpp
    COS214-Poject/src/Estate.cpp
    COS214-Poject/src/Shops.cpp
    COS214-Poject/src/Malls.cpp
    COS214-Poject/src/Office.cpp
    COS214-Poject/src/concreteTaxCollector.cpp
)

# Create the main executable
# add_executable(city_simulator ${SOURCES})
# some change to test the ci/cd
# qwiuerbfpqiufhbp  24iuerhf-p  424ehf0qy8gwp

# Add Google Test
add_subdirectory(gtests)
include_directories(gtests/googletest/include)

# Add the test executable with necessary source files
add_executable(runTests
    tests/NPCManagerTests.cpp
    tests/NPCStatesTests.cpp
    tests/ReactingNPCTests.cpp
      # Link the same sources as city_simulator

    COS214-Poject/src/Government.cpp
    COS214-Poject/src/NPCManager.cpp
    COS214-Poject/src/ReactingNPCS.cpp
    COS214-Poject/src/NeutralState.cpp
    COS214-Poject/src/DonationState.cpp
    COS214-Poject/src/CrimeState.cpp
    COS214-Poject/src/ProductiveState.cpp
    COS214-Poject/src/RevoltState.cpp
)

# Link gtest libraries and Threads to the test executable
target_link_libraries(runTests gtest gtest_main ${CMAKE_THREAD_LIBS_INIT})

# Enable testing
enable_testing()
add_test(NAME runTests COMMAND runTests)
