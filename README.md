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

```
# enter your project directory
$ cd cytoCL

# it is always a good idea to not pollute the source with build files
# so create a new build directory
$ mkdir build
$ cd build

# run cmake to configure the package for your system
$ cmake ..

#To install the library to custom directory, use `-DCMAKE_INSTALL_PREFIX` option
#To locate custom `cytolib` library, use `-DCYTOLIB_INCLUDE_DIR` option
# e.g. `cmake -DCMAKE_INSTALL_PREFIX=/usr/local -DCYTOLIB_INCLUDE_DIR=/home/mylib/include` 
   
$ make

#to install the package
$ make install

# if you have tests, then the following
$ ctest 
```
   

  

 