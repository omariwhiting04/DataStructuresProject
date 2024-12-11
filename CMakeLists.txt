cmake_minimum_required(VERSION 3.10)
project(DataStructuresProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.h")

include_directories(include)

add_executable(DataStructuresProject ${SOURCES} ${HEADERS})

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
target_link_libraries(DataStructuresProject sfml-graphics sfml-window sfml-system)
