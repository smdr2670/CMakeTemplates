#
# Folder structure:
#
# |
# +--include/
# |  |
# |  +--kernel.h
# |
# +--src/
# |  |
# |  +--kernel.cu
# |  +--main.cpp 
# -

cmake_minimum_required(VERSION 2.8)
project(Cuda+CMake)

find_package(CUDA REQUIRED)

set (EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/bin/")

if(CUDA_FOUND)
	########################################################################
	##						Preparing the NVCC compiler 
	########################################################################
	
	# Flag a suitable Compute capability version 
	set(CUDA_NVCC_FLAGS "-gencode arch=compute_50,code=sm_50")
	# add debugging to CUDA NVCC flags.  For NVidia's NSight tools.
	set(CUDA_NVCC_FLAGS_DEBUG ${CUDA_NVCC_FLAGS_DEBUG} "-G")

	# SETUP FOR CPP FILES
	# Caution : Do not set the '-std=c++11' twice
	#			otherwise will get build config FAIL at VS
	# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
	
	########################################################################
	##						Adding the headers 
	########################################################################
	
	# introduce INCLUDE_DIR to the project
	set(INCLUDE_DIR "include/")
	include_directories(${INCLUDE_DIR})
	set(HEADER_FILES ${INCLUDE_DIR}/myKernel.h )
	
	# Wildcarding the .cu files
	file( GLOB  CU  "src/*.cu")
	file(GLOB SOURCES "src/*.cpp")

	# COMPILE AND LINK
	CUDA_ADD_EXECUTABLE(main ${SOURCES} ${HEADER_FILES} ${CU})
else(CUDA_FOUND)
	message("CUDA is not installed on this system")
endif()