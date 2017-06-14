# Set the minimum version of CMake 
cmake_minimum_required (VERSION 3.1)
# Set the project name as the variable PROJECT_NAME
set(PROJECT_NAME PlainC++)
# Set the actual project name
project ( ${PROJECT_NAME})

########################################################################
##						Adding compiler flags 
########################################################################


# set flags, e.g. increase the warning level, using C++11 explcitly
# set(CMAKE_CXX_FLAGS "-Wall")

########################################################################
##						Adding the headers 
########################################################################

# setting include direction as variable
set(INCLUDE_DIR "include/")
# introduce INCLUDE_DIR to the project
include_directories(${INCLUDE_DIR})

set(HEADER_FILES ${INCLUDE_DIR}/Animal.h )


########################################################################
##						Adding the sources 
########################################################################

# Manually adding the source files
# set(SOURCES src/tutorial.cpp)

# Automatically adding the source files using wildcards
file(GLOB SOURCES "src/*.cpp")


########################################################################
##						Final step 
########################################################################

# Requesting an executable to be built using the source and header files
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADER_FILES} )
