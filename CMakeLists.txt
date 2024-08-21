cmake_minimum_required(VERSION 3.10)

# Project name
project(MemoryManagementSystem)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files
set(SOURCES
    main.cpp
    MemoryManager.cpp
    Task.cpp
    Performance.cpp
    IO.cpp
    Test.cpp
)

# Add header files
set(HEADERS
    MemoryManager.h
    Task.h
    Performance.h
    IO.h
    Test.h
    config.h
)

# Create the executable
add_executable(MemoryManagementSystem ${SOURCES} ${HEADERS})
