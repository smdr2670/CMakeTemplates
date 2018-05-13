cmake_minimum_required (VERSION 2.8)
# https://stackoverflow.com/questions/44345811/glad-h-giving-error-that-opengl-header-is-included
# http://discourse.glfw.org/t/glfw-with-cmake-on-windows-glfw-include-dirs-or-glfw-libraries-not-set/890
project (OpenGLExample)


IF(NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
ENDIF(NOT CMAKE_BUILD_TYPE)

# Using FingGLFW.cmake to intergrate the GLFW module properly
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

if(WIN32)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
endif(WIN32)

set(OPENGLEXAMPLES_SOURCES
    App.cpp
    glad.c
)

# glad.h is in the include dir
include_directories("include/")

# Preprocessor define needed for glad.h
add_definitions(-DGLFW_INCLUDE_NONE)

# find the required packages
find_package(glfw3 3.2 REQUIRED)
# message(STATUS "Found GLFW3 in ${GLFW3_INCLUDE_DIR}")

# Set Properties -> General -> Configuration Type 
add_executable(OpenGLExample ${OPENGLEXAMPLES_SOURCES})

if(WIN32)
  set(LIBS opengl32 )
else()
  set(LIBS )
endif(WIN32)

set(LIBS ${LIBS} glfw)

target_link_libraries(OpenGLExample ${LIBS})

