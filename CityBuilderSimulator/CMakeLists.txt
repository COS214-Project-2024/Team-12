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
    src/City/NPCs/UselessNPC/ReactingNPCS.cpp
	src/City/NPCs/NPCManager.cpp
    src/City/NPCs/UselessNPC/DonationState.cpp
    src/City/NPCs/UselessNPC/RevoltState.cpp
    src/City/NPCs/UselessNPC/ProductiveState.cpp
    src/City/NPCs/UselessNPC/CrimeState.cpp
    src/City/NPCs/UselessNPC/NeutralState.cpp
	src/City/Government.cpp 
)

# Link Google Test to the test executable
target_link_libraries(MyTests gtest gtest_main)
