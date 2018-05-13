# Set the minimum version of CMake 
cmake_minimum_required (VERSION 3.1)

# Set project name
project(BoostExample)

# Specify Boost version, its required modules 
# https://stackoverflow.com/questions/3897839/how-to-link-c-program-with-boost-using-cmake
find_package(Boost 1.42.0 COMPONENTS program_options REQUIRED)

# just print out the variables to see their values
message("Boost_DIR : " ${Boost_DIR})
message("BOOST_ROOT: " $ENV{BOOST_ROOT})

if(Boost_FOUND)
	message(STATUS "Success!")
	INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
	LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})
endif()

file(GLOB BOOSTCVEXAMPLE_SOURCES	"*.cpp")
file(GLOB BOOSTCVEXAMPLE_INCLUDES	"*.h")

include_directories("include/")

source_group("" FILES ${BOOSTCVEXAMPLE_SOURCES} ${BOOSTCVEXAMPLE_INCLUDES})
#source_group("Source Files" FILES "main.cpp")

link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

# Set Properties -> General -> Configuration Type 
add_executable(BoostExample ${BOOSTCVEXAMPLE_SOURCES} ${BOOSTCVEXAMPLE_INCLUDES})

# https://stackoverflow.com/questions/11801186/cmake-unable-to-determine-linker-language-with-c
set_target_properties(BoostExample PROPERTIES LINKER_LANGUAGE CXX)
# Properties -> Linker -> Input -> Additional Dependencies
target_link_libraries(BoostExample 
	${Boost_LIBRARIES}  
)
