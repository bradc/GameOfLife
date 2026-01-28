# CMakeLists.txt
cmake_minimum_required(VERSION 3.10) # Specifies the minimum required CMake version
set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")

project(gol VERSION 1.0.0 LANGUAGES CXX)           # Defines the project name and version

set(CMAKE_CXX_STANDARD_REQUIRED ON)  # Enforces the required C++ standard
set(CMAKE_CXX_STANDARD 20)           # Sets the C++ standard to C++20
set(CMAKE_CXX_SCAN_FOR_MODULES ON)

set(SOURCES
    src/main.cpp
    src/life.cpp
    src/utility.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})       # Adds an executable target named 'hello' from main.cpp
target_include_directories(${PROJECT_NAME} PRIVATE include)