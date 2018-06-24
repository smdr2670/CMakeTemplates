#Change this if you need to target a specific CMake version
cmake_minimum_required(VERSION 2.6)

project(CMakeTemplates)

#Options
option(ENABLE_OPENCV "Use OpenCV example" ON)
option(ENABLE_OPENGL "Use OpenGL example" OFF)
option(ENABLE_BOOST "Use Boost example" OFF)
option(ENABLE_QT "Use QT example" OFF)


if(ENABLE_OPENCV)
	add_subdirectory(OpenCV)
endif()

if(ENABLE_BOOST)
	add_subdirectory(Boost)
endif()

if(ENABLE_QT)
	add_subdirectory(Qt)
endif()

if(ENABLE_OPENGL)
	add_subdirectory(OpenGL)
endif()
