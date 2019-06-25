cmake_minimum_required (VERSION 2.6)
project (cytoCL)

file(GLOB SOURCES "src/*.cpp")
include_directories(include ../../libhdf5/h5_build/include ../../protobuf/pb_build/include ../../armadillo ../GatingSet_pb_lib)

set(CYTOLIB_INCLUDE_DIR "" CACHE FILEPATH "Path to cytolib includes")

if(EXISTS CYTOLIB_INCLUDE_DIR/cytolib/global.hpp)
  message(SEND_ERROR "Can't find cytolib/global.hpp in ${CYTOLIB_INCLUDE_DIR}")
endif()

include_directories(${CYTOLIB_INCLUDE_DIR})

set ( H5_LIBS libsz.a libhdf5_cpp.a libhdf5.a )

set ( PB_LIBS libprotobuf-lite.a)
set ( FS_LIBS libstdc++fs.a)
set ( PO_LIBS libboost_program_options.a)
set ( BLAS_LIBS libblas.so liblapack.so)
link_directories( ../../../libhdf5/h5_build/lib ../../../protobuf/pb_build/lib )
set( PROJECT_LINK_LIBS ${H5_LIBS} ${PB_LIBS} ${FS_LIBS} ${BLAS_LIBS}  ${PO_LIBS} libdl.so libz.so)
add_executable(fcstool ${SOURCES} ../GatingSet_pb_lib/GatingSet.pb.cc)
target_link_libraries(fcstool ${PROJECT_LINK_LIBS} )
install(TARGETS fcstool DESTINATION /usr/local/bin)