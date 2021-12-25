cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

# ##############################################################################
# Project settings
# ##############################################################################
project(
  quantum-lapse
  VERSION 0.1
  DESCRIPTION "Alpha"
  LANGUAGES CXX)

# CMAKE definitions
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Let's nicely support folders in IDEs
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Folder structure
set(QL_SOURCE_DIR ${PROJECT_SOURCE_DIR}/source)
set(QL_TEST_DIR ${PROJECT_SOURCE_DIR}/test)
set(QL_BENCHMARK_DIR ${PROJECT_SOURCE_DIR}/benchmark)
set(QL_DOCUMENTATION_DIR ${PROJECT_SOURCE_DIR}/documentation)

# ##############################################################################
# OPTIONS
# ##############################################################################
option(QL_BUILD_TEST "Build test suite" ON)
option(QL_BUILD_BENCHMARK "Build benchmark suite" ON)
option(QL_BUILD_DOCUMENTATION "Build docsygen documentation" ON)
option(QL_DEVEL_TARGETS "Build custom utility targets for development" ON)

# ##############################################################################
# MAIN target
# ##############################################################################
# Require out-of-source builds
file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
if(EXISTS "${LOC_PATH}")
  message(
    FATAL_ERROR
      "You cannot build in a source directory (or any directory with a CMakeLists.txt file). Please make a build subdirectory. Feel free to remove CMakeCache.txt and CMakeFiles."
  )
endif()

# Dependency manager
include(FetchContent)

# ##############################################################################
# TEST target
# ##############################################################################
if(QL_BUILD_TEST)
include(CTest)
enable_testing()
  add_subdirectory(${QL_TEST_DIR})
endif(QL_BUILD_TEST)

# ##############################################################################
# BENCHMARK target
# ##############################################################################
if(QL_BUILD_BENCHMARK)
  add_subdirectory(${QL_BENCHMARK_DIR})
endif(QL_BUILD_BENCHMARK)

# ##############################################################################
# DOCUMENTATION target
# ##############################################################################
if(QL_BUILD_DOCUMENTATION)
  find_package(Doxygen)
  if(DOXYGEN_FOUND)
    # set input and output files
    set(DOXYGEN_IN ${QL_DOCUMENTATION_DIR}/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile) # Need to change this
                                                          # once install is
                                                          # configured

    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)

    # note the option ALL which allows to build the docs together with the
    # application
    add_custom_target(
      documentation ALL
      COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
      WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
      COMMENT "Generating API documentation with Doxygen")
  else(DOXYGEN_FOUND)
    message(
      "Doxygen need to be installed to generate the doxygen documentation")
  endif(DOXYGEN_FOUND)
endif(QL_BUILD_DOCUMENTATION)

# ##############################################################################
# DEVELOPMENT targets
# ##############################################################################
if(QL_DEVEL_TARGETS)
  # Format sources
  find_program(CLANG_FORMAT clang-format DOC "A tool to format the code")
  if(CLANG_FORMAT)
    file(
      GLOB_RECURSE
      FORMAT_FILES
      ${QL_SOURCE_DIR}/*.hpp
      ${QL_SOURCE_DIR}/*.cpp
      ${QL_TEST_DIR}/*.hpp
      ${QL_TEST_DIR}/*.cpp
      ${QL_BENCHMARK_DIR}/*.hpp
      ${QL_BENCHMARK_DIR}/*.cpp)
    add_custom_target(devel_format COMMAND ${CLANG_FORMAT} -i --style=Google
                                           ${FORMAT_FILES})
  endif(CLANG_FORMAT)

  # clean build
  add_custom_target(devel_clean_build
                    COMMAND rm -rf ${PROJECT_SOURCE_DIR}/build/.[!.]* *)
endif(QL_DEVEL_TARGETS)
