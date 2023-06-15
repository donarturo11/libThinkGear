cmake_minimum_required(VERSION 3.22)
project(libThinkGear VERSION 1.0.0 LANGUAGES CXX C)
set(CMAKE_CXX_STANDARD 20)

option(BUILD_SHARED "Whether to build the shared library" ON)
option(BUILD_STATIC "Whether to build the static library" ON)
option(COMPILE_PROJECTS "Build test" OFF)

include_directories(src)
include_directories(tests)
set (THINKGEAR_SOURCES 
    src/ThinkGear.c
    src/DummyCallbacks.c
    src/ThinkGearHandleValues.c
    src/ThinkGearStreamParser.c    
    )

set (THINKGEAR_HEADERS
     src/ThinkGear.h
    )
if(BUILD_STATIC)
    message("Build static library")
    add_library (thinkgear STATIC ${THINKGEAR_SOURCES})    
    target_include_directories(thinkgear PRIVATE include PUBLIC $<INSTALL_INTERFACE:include>)
    set_target_properties(thinkgear PROPERTIES PUBLIC_HEADER "${THINKGEAR_HEADERS}")
    list(APPEND THINKGEAR_TARGETS thinkgear)
endif()
if(BUILD_SHARED)
    message("Build shared library")
    add_compile_definitions(EXPORT)
    add_library (thinkgear_SHARED SHARED ${THINKGEAR_SOURCES})
    set_target_properties(thinkgear_SHARED PROPERTIES OUTPUT_NAME thinkgear)
    target_include_directories(thinkgear_SHARED PRIVATE include PUBLIC $<INSTALL_INTERFACE:include>)
    set_target_properties(thinkgear_SHARED PROPERTIES PUBLIC_HEADER "${THINKGEAR_HEADERS}")
    list(APPEND THINKGEAR_TARGETS thinkgear_SHARED)
endif()

install(FILES ${THINKGEAR_HEADERS} DESTINATION include/ThinkGear)
install(TARGETS ${THINKGEAR_TARGETS} EXPORT thinkgear-config
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
	RUNTIME DESTINATION bin
	PUBLIC_HEADER DESTINATION include/ThinkGear/ThinkGear.h)

install(EXPORT thinkgear-config DESTINATION lib/cmake/thinkgear)

if (COMPILE_PROJECTS)
    message("COMPILE PROJECTS!")
    add_subdirectory(projects/parse_test)
    add_subdirectory(projects/device_test)
endif()
