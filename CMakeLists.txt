# Configures dependencies, platform specifics and output paths

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(MyProject)

# Use this snippet *after* PROJECT(xxx) to allow for customizable install paths
IF(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    SET(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR} CACHE PATH "Nothing else chosenas install dir, choosing current dir."  FORCE)
ENDIF(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)

# Use this to have CMake automatically add necessary shared libraries to the runtime path of your binaries
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)


SET(CMAKE_INCLUDE_CURRENT_DIR ON)

SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

ADD_SUBDIRECTORY(dependencies)
#ADD_SUBDIRECTORY(dependencies/config4cpp)
ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(test)


