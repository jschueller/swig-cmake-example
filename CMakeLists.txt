cmake_minimum_required (VERSION 3.1.0)

if (NOT DEFINED CMAKE_BUILD_TYPE)
  set (CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Build type")
endif ()


project(cmake-example)

find_package (PythonInterp REQUIRED)
find_package (PythonLibs REQUIRED)
if (NOT DEFINED PYTHON_SITE_PACKAGES)
  if (WIN32)
    set(PYTHON_SITE_PACKAGES Lib/site-packages)
  else ()
    set (PYTHON_SITE_PACKAGES lib/python${PYTHON_VERSION_MAJOR}.${PYTHON_VERSION_MINOR}/site-packages)
  endif ()
endif ()

find_package (SWIG REQUIRED)
include (${SWIG_USE_FILE})

add_custom_command (OUTPUT  ${CMAKE_CURRENT_BINARY_DIR}/swig_runtime.hxx
                     COMMAND ${SWIG_EXECUTABLE}
                     ARGS -python -c++ ${CMAKE_SWIG_FLAGS} -external-runtime ${CMAKE_CURRENT_BINARY_DIR}/swig_runtime.hxx
                     COMMENT "Swig header")
add_custom_target (generate_swig_runtime DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/swig_runtime.hxx)


set_property(SOURCE openturns.i PROPERTY CPLUSPLUS ON)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

include_directories(${PYTHON_INCLUDE_DIRS})

if (CMAKE_VERSION VERSION_LESS 3.8)
   swig_add_module (openturns python openturns.i PythonFieldFunction.cxx)
else ()
  swig_add_library (openturns LANGUAGE python SOURCES openturns.i PythonFieldFunction.cxx)
endif ()
add_dependencies (${SWIG_MODULE_openturns_REAL_NAME} generate_swig_runtime)

option (LINK_PYTHON_LIBRARY "link python lib" ON)
if (LINK_PYTHON_LIBRARY)
  target_link_libraries (${SWIG_MODULE_openturns_REAL_NAME} ${PYTHON_LIBRARIES})
endif ()
get_target_property(_LINK_INTERFACE_LIBRARIES ${SWIG_MODULE_openturns_REAL_NAME} LINK_INTERFACE_LIBRARIES)
message (STATUS "LINK_INTERFACE_LIBRARIES=${_LINK_INTERFACE_LIBRARIES}")

if (APPLE AND CMAKE_CXX_COMPILER_ID MATCHES "Clang" AND NOT LINK_PYTHON_LIBRARY)
  set_target_properties (${SWIG_MODULE_openturns_REAL_NAME} PROPERTIES LINK_FLAGS "-undefined dynamic_lookup")
endif ()

install (TARGETS ${SWIG_MODULE_openturns_REAL_NAME} DESTINATION ${PYTHON_SITE_PACKAGES})
install (FILES ${CMAKE_CURRENT_BINARY_DIR}/openturns.py DESTINATION ${PYTHON_SITE_PACKAGES})
