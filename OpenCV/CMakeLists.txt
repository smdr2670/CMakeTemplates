# Set the minimum version of CMake 
cmake_minimum_required (VERSION 3.1)

# Set project name
project(OpenCVExample)

# Specify OpenCV version, its required modules and OPTIONAL_COMPONENTS 
find_package(OpenCV 3.3 REQUIRED core highgui imgproc imgcodecs OPTIONAL_COMPONENTS optflow cudaoptflow PATHS "$ENV{OPENCVDIR}/build")

file(GLOB OPENCVEXAMPLES_SOURCES	"*.cpp")
file(GLOB OPENCVEXAMPLES_INCLUDES	"*.h")

source_group("" FILES ${OPENCVEXAMPLES_SOURCES} ${OPENCVEXAMPLES_INCLUDES})
#source_group("Source Files" FILES "main.cpp")

include_directories(
		${OpenCV_INCLUDE_DIRS}
)

link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

# Set Properties -> General -> Configuration Type 
add_executable(OpenCVExample ${OPENCVEXAMPLES_SOURCES} ${OPENCVEXAMPLES_INCLUDES})

# https://stackoverflow.com/questions/11801186/cmake-unable-to-determine-linker-language-with-c
set_target_properties(OpenCVExample PROPERTIES LINKER_LANGUAGE CXX)
# Properties -> Linker -> Input -> Additional Dependencies
target_link_libraries(OpenCVExample 
	${OpenCV_LIBS}  
)
