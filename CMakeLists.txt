
if(ESP_PLATFORM)
    if(IDF_VERSION_MAJOR GREATER_EQUAL 4)
        idf_component_register(SRC_DIRS src
            INCLUDE_DIRS include)
    else()
        set(COMPONENT_SRCDIRS src)
        set(COMPONENT_ADD_INCLUDEDIRS include)
        set(COMPONENT_REQUIRES log driver)
        register_component()
    endif()
else()
    cmake_minimum_required(VERSION 3.16)
    project(clock_object)
    add_executable(catch_exec tests.cpp catch.hpp src/clock.cpp include/clock.h src/clock_base.cpp include/clock_base.h src/counter_clock.cpp include/counter_clock.h)
    add_executable(main main.cpp src/clock.cpp include/clock.h src/clock_base.cpp include/clock_base.h src/counter_clock.cpp include/counter_clock.h)

endif()
