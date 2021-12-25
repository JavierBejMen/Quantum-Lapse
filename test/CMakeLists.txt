cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(quantum-lapse)

# ##############################################################################
# Folder configuration
# ##############################################################################
set(QL_TEST_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/source)

# ##############################################################################
# Global dependency googletest
# ##############################################################################
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.11.0)

set(googletest_INSTALL_GTEST OFF)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)
# ##############################################################################
# TESTS
# ##############################################################################
add_subdirectory(${QL_TEST_SOURCE_DIR}/main)
