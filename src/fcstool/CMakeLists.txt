cmake_minimum_required (VERSION 2.6)
project (cytoCL)

file(GLOB SOURCES "src/*.cpp")
include_directories(include ../../libhdf5/h5_build/include ../../protobuf/pb_build/include ../../armadillo)


set ( H5_LIBS libhdf5_cpp.a libhdf5.a libsz.a)
set ( PB_LIBS libprotobuf-lite.a)
set ( FS_LIBS libstdc++fs.a)
link_directories( ../../../libhdf5/h5_build/lib ../../../protobuf/pb_build/lib )
set(LIBS ${LIBS} ${H5_LIBS} ${PB_LIBS} ${FS_LIBS} libdl.so)
add_executable(fcstool ${SOURCES} $<TARGET_OBJECTS:gs_pb_lib>)
target_link_libraries(fcstool ${LIBS} )
install(TARGETS fcstool DESTINATION /usr/local/bin)