# Set the minimum version of CMake 
cmake_minimum_required (VERSION 3.1)

# Set project name
project(QtExample)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc (Meta Object Compiler) and 
# uic (User Interface Compiler) automatically when needed.
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

# Find the QtWidgets library
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)

file(GLOB QTEXAMPLES_SOURCES	"*.cpp")
file(GLOB QTEXAMPLES_INCLUDES	"*.h")
file(GLOB QTEXAMPLES_UIS		"*.ui")

# We need add -DQT_WIDGETS_LIB when using QtWidgets in Qt 5.
add_definitions(${Qt5Widgets_DEFINITIONS})

qt5_wrap_ui(UIS_HDRS
	QTEXAMPLES_UIS
)

source_group("" FILES ${QTEXAMPLES_SOURCES} ${QTEXAMPLES_INCLUDES})
#source_group("Source Files" FILES "main.cpp")

include_directories(
		${OpenCV_INCLUDE_DIRS}
)

link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

# Set Properties -> General -> Configuration Type 
add_executable(QtExample ${QTEXAMPLES_SOURCES} ${QTEXAMPLES_INCLUDES})

# https://stackoverflow.com/questions/11801186/cmake-unable-to-determine-linker-language-with-c
set_target_properties(QtExample PROPERTIES LINKER_LANGUAGE CXX)

# Properties -> Linker -> Input -> Additional Dependencies
# Use the Widgets module from Qt 5.
target_link_libraries(QtExample Qt5::Widgets)