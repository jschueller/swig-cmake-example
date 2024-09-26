cmake_minimum_required (VERSION 3.13)

set (CMAKE_BUILD_TYPE Release CACHE STRING "Build type")

project(cmake-example)


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

find_package (Python 3.6 COMPONENTS Interpreter Development.Module REQUIRED)
if (NOT DEFINED PYTHON_SITE_PACKAGES)
  if (WIN32)
    set (PYTHON_SITE_PACKAGES Lib/site-packages)
  else ()
    set (PYTHON_SITE_PACKAGES lib/python${PYTHON_VERSION_MAJOR}.${PYTHON_VERSION_MINOR}/site-packages)
  endif ()
endif ()

find_package (SWIG REQUIRED)
include (${SWIG_USE_FILE})

set(CMAKE_SWIG_FLAGS "" CACHE STRING "swig flags")

add_custom_command (OUTPUT  ${CMAKE_CURRENT_BINARY_DIR}/swig_runtime.hxx
                     COMMAND ${SWIG_EXECUTABLE}
                     ARGS -python -external-runtime ${CMAKE_CURRENT_BINARY_DIR}/swig_runtime.hxx
                     COMMENT "Swig header")
add_custom_target (generate_swig_runtime DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/swig_runtime.hxx)


set_property(SOURCE openturns.i PROPERTY CPLUSPLUS ON)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

include_directories(${Python_INCLUDE_DIRS})

swig_add_library (openturns LANGUAGE python SOURCES openturns.i PythonFieldFunction.cxx)
add_dependencies (${SWIG_MODULE_openturns_REAL_NAME} generate_swig_runtime)

include (TargetLinkLibrariesWithDynamicLookup)
target_link_libraries_with_dynamic_lookup (${SWIG_MODULE_openturns_REAL_NAME} ${Python_LIBRARIES})

install (TARGETS ${SWIG_MODULE_openturns_REAL_NAME} DESTINATION ${PYTHON_SITE_PACKAGES})
install (FILES ${CMAKE_CURRENT_BINARY_DIR}/openturns.py DESTINATION ${PYTHON_SITE_PACKAGES})

enable_testing ()

macro (ot_add_test name)
  add_test (NAME ${name} COMMAND ${Python_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/t_${name}.py)
  set_tests_properties (${name} PROPERTIES ENVIRONMENT "PYTHONPATH=${CMAKE_INSTALL_PREFIX}/${PYTHON_SITE_PACKAGES}")
endmacro ()
ot_add_test (fieldfunction)
ot_add_test (mesh)
ot_add_test (description)


add_executable(t_mesh t_mesh.cxx)
# if (APPLE)
#   target_link_libraries(t_mesh c++)
# endif ()
