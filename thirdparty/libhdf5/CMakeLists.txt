	set(h5_lib_file h5_build/lib/libhdf5_cpp.a)
	file(COPY hdf5small_cxx_1.10.3.tar.gz DESTINATION .)
	file(COPY install.sh DESTINATION .)
	add_custom_command(OUTPUT ${h5_lib_file}
						COMMAND bash "install.sh"
						COMMENT "Building the bundled h5 libs")
	add_custom_target(h5libs DEPENDS ${h5_lib_file})
	set_source_files_properties( ${h5_lib_file} PROPERTIES GENERATED TRUE ) 
	
	