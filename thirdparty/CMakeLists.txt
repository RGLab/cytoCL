    set(THIRDPARTY_INCLUDE_DIR, ${THIRDPARTY_INCLUDE_DIR} armadillo PARENT_SCOPE)
    
    add_subdirectory(libhdf5)
    set(THIRDPARTY_INCLUDE_DIR, ${THIRDPARTY_INCLUDE_DIR} libhdf5/h5_build/include PARENT_SCOPE)
	find_library ( H5_SZ_LIBS NAMEs libsz.a HINTS "libhdf5/h5_build/lib")
	set(LIBS ${H5_SZ_LIBS} ${LIBS} PARENT_SCOPE)
	find_library ( H5_C_LIBS NAMEs libhdf5.a HINTS "libhdf5/h5_build/lib")
	set(LIBS ${H5_C_LIBS} ${LIBS} PARENT_SCOPE)
	find_library ( H5_CXX_LIBS NAMEs libhdf5_cpp.a HINTS "libhdf5/h5_build/lib")
	set(LIBS ${H5_CXX_LIBS} ${LIBS} PARENT_SCOPE)
    
	add_subdirectory(protobuf)
    set(THIRDPARTY_INCLUDE_DIR, ${THIRDPARTY_INCLUDE_DIR} protobuf/h5_build/include PARENT_SCOPE)
    #use find_library instead of include_library to ensure full path to the lib
	find_library ( PB_LIBS NAMEs libprotobuf-lite.a HINTS "protobuf/pb_build/lib")
	set(LIBS ${PB_LIBS} ${LIBS} PARENT_SCOPE)
#	message(${PB_LIBS})
    