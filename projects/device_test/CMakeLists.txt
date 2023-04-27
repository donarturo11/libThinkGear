project(thinkgear_device_test VERSION 1.0.0 LANGUAGES CXX C)
find_package(Boost)
if (Boost_FOUND)
    set(DEVTEST_SOURCES
        ThinkGearReceiver.cpp
        ThinkGearMonitor.cpp
        ThinkGearMessages.cpp
        TGReceiverNotify.cpp
        main.cpp
        )
    add_executable(${PROJECT_NAME} ${DEVTEST_SOURCES})
    if (BUILD_STATIC)
        target_link_libraries(${PROJECT_NAME} PUBLIC thinkgear)
    else()
        target_link_libraries(${PROJECT_NAME} PUBLIC thinkgear_SHARED)
    endif()
    install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
endif()
