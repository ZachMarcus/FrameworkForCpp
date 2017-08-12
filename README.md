# Project Framework
A basic starting point for C++ Linux projects

I never seem to add in this functionality into projects until I'm far in.

If starting with all of that preconfigured and set up makes that easy, then this structure is for you.

## This project contains:
 - A CMake structure for out of source builds
 - A full project layout with the structure for tests, src, include
 - A Sample [optparse](https://github.com/myint/optparse "Python's optparse but C++ and header-only") usage in Main.cpp
 - Inclusion of [Config4cpp](http://www.config4star.org/ "Config4*'s homepage")
 - Inclusion of [Log4cxx](https://logging.apache.org/log4cxx "Apache Log4cxx's homepage)
 - Inclusion of [DocTest](https://github.com/onqtam/doctest "Doctest's github homepage")
    - Note that the following line should only occur once per binary:
```
    #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
```
    - Then include the following in each source file:
```
    #include "doctest.h"
```

## Project Dependencies:

 - apr-1.x
 - apr-utils-1.x
 - gzip
 - zip
 - libtool
 - autotools
 - automake
 - log4cxx


### For Debian (tested on Ubuntu 16.04), try
```
    sudo apt install libapr1-dev libaprutil1-dev zip gzip libtool autotools-dev automake liblog4cxx-dev
```

