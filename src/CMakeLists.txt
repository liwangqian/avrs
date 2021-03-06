# src/CMakeLists.txt

add_subdirectory(utils)
add_subdirectory(tracker)

# C++ source files
set(CXX_SOURCE_FILES 
    dxfreader.cpp
    airabsorption.cpp
    surface.cpp
    room.cpp
    listener.cpp
    soundsource.cpp
    ism.cpp
    convolver.cpp
    virtualenvironment.cpp
    headfilter.cpp
    player.cpp
    input.cpp
    configuration.cpp
    fdn.cpp
    system.cpp
	main.cpp
)

set(LIBRARIES
	${FFTW3_LIBRARY}
	${STK_LIBRARY}
	${ALSA_LIBRARIES}
	${M_LIBRARY}
	${CMAKE_THREAD_LIBS_INIT}
	${DXFLIB_LIBRARY}	
	${ARMADILLO_LIBRARY} 
	${ANN_LIBRARY}
	${Boost_LIBRARIES}
	avrs_utils 
	avrs_trackersim
	${RTAI_LIBRARY}
)

if(WIIMOTE_SUPPORT)
    set(LIBRARIES ${LIBRARIES}
        avrs_trackerwiimote
	    ${BLUETOOTH_LIBRARY}
	    ${CWIID_LIBRARY}
	)
endif()

# Executable file
add_executable(${PROJECT_NAME} ${CXX_SOURCE_FILES})

# Link executable file to libraries
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})

# Move to bin directory
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
