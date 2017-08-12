# Project Framework
A basic starting point for C++ Linux projects

I never seem to add in this functionality into projects until I'm far in.
If starting with all of that preconfigured and set up makes that easy, then this structure is for you.

This project contains:
 - A CMake structure for out of source builds
 - A full project layout with the structure for tests, src, include
 - A Sample optparse usage in Main.cpp
 - Built-in Config4cpp - https://github.com/config4star/config4cpp
 - Built-in Log4cxx
 - Built-in Google Test


# Project Dependencies:

apr-1.x
apr-utils-1.x
gzip
zip

For Debian (tested on Ubuntu 16.04), try

    sudo apt install libapr1-dev libaprutil1-dev zip gzip


