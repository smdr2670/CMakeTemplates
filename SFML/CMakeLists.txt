#Change this if you need to target a specific CMake version
cmake_minimum_required(VERSION 2.6)

set(PROJECT_NAME HelloSFNL)
# Enable debug symbols by default
# must be done before project() statement
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()
# (you can also set it on the command line: -D CMAKE_BUILD_TYPE=Release)

project(${PROJECT_NAME})


# define project-includes
set(INCLUDE_DIR "include/")
include_directories(${INCLUDE_DIR})

#define project-sources

file(GLOB SOURCES "src/*.cpp")

# Define executable

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADER_FILES})

# Detect and add SFML
#set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "C:/SFML-2.4.2/cmake/Modules/") # Hard-coded search 
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED network audio graphics window system)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()





