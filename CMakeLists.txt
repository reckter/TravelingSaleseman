cmake_minimum_required(VERSION 2.6)
project(Praktikum3)

set(CMAKE_VERBOSE_MAKEFILE on)
set(EXECUTABLE_OUTPUT_PATH bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

set(galib
  src/GA/GASolution.cpp
  src/GA/Genome.cpp
  src/GA/Organism.cpp
)

set(prakt3
  src/Cities.cpp
  src/Praktikum3.cpp
  src/TSPUtil.cpp
)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(ga_library STATIC ${galib})

add_executable(praktikum3 ${prakt3})

target_link_libraries(praktikum3 ga_library)

