# Configures the project to be built
# TODO // Add the headers somewhere in the install directory

ADD_EXECUTABLE(Main
    Main.cpp
)

TARGET_INCLUDE_DIRECTORIES(Main PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

TARGET_LINK_LIBRARIES(Main
    Project
)


ADD_LIBRARY(Project STATIC
    Project.cpp
)

TARGET_INCLUDE_DIRECTORIES(Project PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

INSTALL(TARGETS Project
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/lib
)

INSTALL(TARGETS Main
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/bin
)






