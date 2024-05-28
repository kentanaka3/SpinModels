cmake_minimum_required(VERSION 3.16)

set(CMAKE_C_COMPILER "g++")
#set(CMAKE_CXX_COMPILER "/opt/homebrew/bin/g++-13")

# Set the project name, version, and primary programming language(s) 
project(SpinModels VERSION 0.1 LANGUAGES CXX)

# Set policy to silence Warnings about timestamps of downloaded files.
# Review occasionally if it may be set to NEW
if(POLICY CMP0135)
  cmake_policy(SET CMP0135 OLD)
endif()

set(SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")
set(INCLUDE_DIR "${PROJECT_SOURCE_DIR}/inc")
set(LIBRARY_DIR "${PROJECT_SOURCE_DIR}/lib")

# Define minimum C++ version for Mac
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define colors for bringing attention to OMP & MPI ON/OFF
if(NOT WIN32)
  string(ASCII 27 Esc)
  set(CReset  "${Esc}[m")
  set(R       "${Esc}[1;31m")
  set(G       "${Esc}[1;32m")
endif()

add_executable(main.x src/main.cpp)
add_library(utilLib SHARED src/utils.cpp)
add_library(IsingLib SHARED lib/ising.cpp)

FIND_PACKAGE(Gnuplot REQUIRED)
IF(GNUPLOT_FOUND)
  message("${G} #       ------- GNUPlot SUPPORT IS ON       #${CReset}")
  add_definitions(-DMyGNUPlot="${PROJECT_SOURCE_DIR}/src/plot.plt")
ELSE()
  message("${G} #               GNUPlot SUPPORT IS ON       #${CReset}")
ENDIF()

# FIND_PACKAGE(OpenMP REQUIRED)
# IF(OpenMP_FOUND)
#   target_link_libraries(IsingLib PUBLIC OpenMP::OpenMP_CXX)
#   target_compile_options(main.x PUBLIC -fopenmp)
#   #target_compile_options(Brain.x PUBLIC -fopenmp)
#   IF(CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
#     target_compile_options(main.x PUBLIC -Xclang)
#   ENDIF()
#   message("${G} #       ------ OPENMP SUPPORT IS ON #${CReset}")
# ELSE()
#   message("${R} #       ------ OPENMP SUPPORT IS OFF #${CReset}")
# ENDIF()

FIND_PACKAGE(MPI REQUIRED)
IF(MPI_FOUND)
  add_compile_definitions(_MPI=yes)
  #find_package(HDF5 REQUIRED COMPONENTS CXX)
  include_directories(${MPI_CXX_INCLUDE_PATH})
  target_link_libraries(IsingLib PUBLIC MPI::MPI_CXX)
  message("${G} #       ------ MPI SUPPORT IS ON #${CReset}")
ELSE()
  message("${R} #       ------ MPI SUPPORT IS OFF #${CReset}")
ENDIF()

include_directories(inc)
target_link_libraries(main.x IsingLib)