# cytoCL
Command line tools for cytolib

System requirement
============
1. cmake
2. g++ (>=4.9)
3. libblas, liblapack, ZLIB, boost c++ library
4. cytolib c++ library (see https://github.com/RGLab/cytolib/blob/trunk/inst/INSTALL.txt)

Installation
============

```bash
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
# e.g. `cmake -DCMAKE_INSTALL_PREFIX=/usr/local -DCYTOLIB_INCLUDE_DIR=~/mylib/include` 
   
$ make

#to install the package
$ make install

# if you have tests, then the following
$ ctest 
```
   

 Example
============
```bash
./fcstool 
usage: fcstool [--version] [--help] <subcommand> [<args>]

These are common fcstool subcommand:

init 	Create a new subdirectory and parse all the fcs files into structured format (e.g. h5)
check 	perform various QC checks across files
print 	print the content of single fcs file
diff 	Show difference between two files
merge 	Join two or more files together
add 	add the content of single h5 file
Rm 	remove the content of single h5 file

see 'fcstool <command>' to read about a specific subcommand.

# to view summary of a FCS file
$ ./fcstool print CytoTrol_CytoTrol_1.fcs
cytoframe 'CytoTrol_CytoTrol_1.fcs'
with 119531 cells and 12 observables: 
name            desc  minRange  maxRange
FSC-A                        0   2.6e+05
FSC-H                        0   2.6e+05
FSC-W                        0   2.6e+05
SSC-A                        0   2.6e+05
B710-A   CD4 PcpCy55         0   2.6e+05
R660-A      CD38 APC         0   2.6e+05
R780-A     CD8 APCH7         0   2.6e+05
V450-A      CD3 V450         0   2.6e+05
V545-A   HLA-DR V500         0   2.6e+05
G560-A       CCR7 PE         0   2.6e+05
G780-A  CD45RA PECy7         0   2.6e+05
Time                         0   2.6e+05
171 keywords

#to show channels
$ ./fcstool print CytoTrol_CytoTrol_1.fcs -c
'FSC-A' 'FSC-H' 'FSC-W' 'SSC-A' 'B710-A' 'R660-A' 'R780-A' 'V450-A' 'V545-A' 'G560-A' 'G780-A' 'Time'

# to show markers
$ ./fcstool print CytoTrol_CytoTrol_1.fcs -m
'' '' '' '' 'CD4 PcpCy55' 'CD38 APC' 'CD8 APCH7' 'CD3 V450' 'HLA-DR V500' 'CCR7 PE' 'CD45RA PECy7' ''

#to head data matrix
$ ./fcstool print CytoTrol_CytoTrol_1.fcs -d
     FSC-A     FSC-H     FSC-W     SSC-A    B710-A    R660-A    R780-A    V450-A    V545-A    G560-A    G780-A
   1.4073e+05   1.3338e+05   6.9151e+04   9.1114e+04   2.2311e+04   3.5576e+04   1.4302e+04   1.6233e+04   7.6446e+03   4.1136e+03   1.2672e+04   2.0000e-01
   2.6195e+04   2.6207e+04   6.5507e+04   1.0115e+04   5.0400e+00   4.4793e+02   6.8256e+02   4.3700e+01   7.7900e+01  -9.1200e+01   1.8240e+01   4.0000e-01
   6.4294e+04   5.1594e+04   8.1668e+04   1.7462e+05   3.7128e+02   8.5162e+02  -6.6360e+01   3.3535e+02   9.7185e+02   2.7360e+02   2.7168e+02   6.0000e-01
   1.2839e+05   1.0361e+05   8.1210e+04   1.5063e+05   1.4944e+03   5.6722e+03   2.9791e+03   1.4924e+03   2.8791e+04   7.7184e+02   9.8880e+02   6.0000e-01
   1.2772e+05   1.1962e+05   6.9975e+04   7.6955e+04   2.5452e+03   2.2728e+03   1.2464e+05   8.6089e+03   4.1904e+03   1.4307e+04   5.8978e+04   7.0000e-01
   1.3435e+05   1.2565e+05   7.0072e+04   7.0116e+04   2.3053e+04   1.7585e+03   5.2811e+03   4.8498e+03   2.8595e+03   2.2493e+03   1.5610e+03   7.0000e-01
   9.5774e+04   9.1070e+04   6.8921e+04   5.0827e+04   4.6368e+02   6.1778e+02   3.6166e+03   3.0400e+02   6.1075e+03   1.3133e+03   2.5986e+04   9.0000e-01
   3.1508e+04   3.1511e+04   6.5530e+04   1.2004e+04   4.9560e+01  -6.3990e+01   2.5359e+02  -2.2800e+01  -7.3150e+01   4.2240e+01   1.5360e+01   1.3000e+00
   8.4330e+04   7.7826e+04   7.1013e+04   6.6053e+04   2.3016e+03   1.3754e+03   1.0522e+05   6.8305e+03   3.3962e+03   1.1682e+04   5.0029e+04   1.5000e+00
   1.0155e+05   9.6602e+04   6.8895e+04   4.4621e+04   1.4494e+04   4.6673e+03   7.2696e+03   7.7045e+03   3.7506e+03   1.0162e+04   3.2567e+04   1.5000e+00
``` 

 