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

set(QTEXAMPLE_SOURCES
    main.cpp
    mainwindow.cpp
)

set(QTEXAMPLE_LIBRARIES
    Qt5::Widgets
  )

link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

# Set Properties -> General -> Configuration Type 
add_executable(QtExample ${QTEXAMPLE_SOURCES} )

# https://stackoverflow.com/questions/11801186/cmake-unable-to-determine-linker-language-with-c
set_target_properties(QtExample PROPERTIES LINKER_LANGUAGE CXX)

# Properties -> Linker -> Input -> Additional Dependencies
# Use the Widgets module from Qt 5.
target_link_libraries(QtExample ${QTEXAMPLE_LIBRARIES})