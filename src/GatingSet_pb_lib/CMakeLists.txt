add_library(gs_pb_lib OBJECT GatingSet.pb.cc)
add_dependencies( gs_pb_lib h5libs pblibs)
