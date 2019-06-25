# cytoCL
Command line tools for cytolib

System requirement
============
1. cmake
2. g++ (>=4.9)
3. boost c++ library
4. cytolib c++ library (see https://github.com/RGLab/cytolib/blob/trunk/inst/INSTALL.txt)

Installation
============

   The Installation uses cmake.

   1. `cd' to the source directory 'src/fcstool' containing the `CMakeLists.txt' 
      to configure the package for your system. 

     To install the library to custom directory, use '-DCMAKE_INSTALL_PREFIX' option
     
     To locate `cytolib` library, use '-DCYTOLIB_INCLUDE_DIR' option
     e.g. 'cmake -DCMAKE_INSTALL_PREFIX=/usr/local -DCYTOLIB_INCLUDE_DIR=/home/mylib/include' 
     
     it will install the library to  /usr/local/include 
     

  2. Type `make install' to install the package.

 