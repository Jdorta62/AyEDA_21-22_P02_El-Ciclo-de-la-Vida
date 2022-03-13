# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Algorimo y Estructura de Datos Avanzado
#
# @author José Gregorio Dorta
# @date 06/03/2021
# @brief CMakeLists.txt practica 1
# CMakeLists.txt defines the whole build
# CMake reads CMakeLists.txt sequentially
#
# Build process:
#   1. cd <project_folder>
#   2. mkdir build
#   3. cd build
#   4. cmake ..
#   5. make


cmake_minimum_required(VERSION 3.1)  

# set the project name 
project(Prueba               
    VERSION 1.0
    DESCRIPTION "file .exe practica1 de AyEDA, implementación del juego de la vida"
    LANGUAGES CXX)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14) 						
set(CMAKE_CXX_STANDARD_REQUIRED True)

# tell cmake to output binaries here:
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# Debug and release flags
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# tell cmake where to look for *.h files
include_directories(${PROJECT_SOURCE_DIR}/src)

# create library " libtools "
#add_library(tools src/tools.cc)

# Adds an executable target called "main_p2" to be built from the source files listed in the command invocation.
add_executable(JuegoDeLaVida
    src/CellClass.cc
    src/CellClass.h
    src/GridClass.cc
    src/GridClass.h
    src/StatesClasses/StateClass.h
    src/StatesClasses/StateAdultClass.h
    src/StatesClasses/StateAdultClass.cc
    src/StatesClasses/StateDeadClass.h
    src/StatesClasses/StateDeadClass.cc
    src/StatesClasses/StateEggClass.h
    src/StatesClasses/StateEggClass.cc
    src/StatesClasses/StateLarvaClass.h
    src/StatesClasses/StateLarvaClass.cc
    src/StatesClasses/StatePupaClass.h
    src/StatesClasses/StatePupaClass.cc
    src/CicloDeLaVida.cc)