add_library(citybuilder_lib
    # Add your source files here
    example.cpp
)

target_include_directories(citybuilder_lib
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)