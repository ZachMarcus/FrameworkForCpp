# To build the dependencies as external projects

#SET(Config4CppDir "${CMAKE_BINARY_DIR}/dependencies/config4cpp")
#SET(Config4CppInstall "mv ${Config4CppDir}/bin/config2cpp ${CMAKE_BINARY_DIR}/bin/config2cpp ; \
    mv ${Config4CppDir}/bin/config4cpp ${CMAKE_BINARY_DIR}/bin/config4cpp ; \
    mv ${Config4CppDir}/lib/libconfig4cpp.a ${CMAKE_BINARY_DIR}/lib/libconfig4cpp.a")

ADD_SUBDIRECTORY(config4cpp)





