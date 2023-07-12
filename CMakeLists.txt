cmake_minimum_required (VERSION 3.13)

set (CMAKE_BUILD_TYPE Release CACHE STRING "Build type")

project(cmake-example)


enable_language(Fortran)
include (FortranCInterface)

FortranCInterface_HEADER(FC.h)

if(POLICY CMP0042)
  # Set MACOSX_RPATH to ON
  cmake_policy(SET CMP0042 NEW)
endif()
if(POLICY CMP0078)
  cmake_policy(SET CMP0078 NEW)
endif()
if(POLICY CMP0086)
  cmake_policy(SET CMP0086 NEW)
endif()

# RPATH settings
set (CMAKE_INSTALL_RPATH ${CMAKE_INSTALL_PREFIX}/lib)
set (CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

list (APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

