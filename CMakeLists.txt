cmake_minimum_required(VERSION 3.1)
project(ZeroMq)

set(HEADER_FILES
    ZMQServerComponent.h
)

set(SOURCE_FILES
    ZMQServerComponent.cpp
)

set(EXTRA_FILES
    README.md
)

find_package(SofaFramework REQUIRED)

add_library(${PROJECT_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES} ${EXTRA_FILES})
target_link_libraries(${PROJECT_NAME} -lzmq ${} SofaCore)
set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "-DSOFA_BUILD_ZeroMq")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/..")

install(TARGETS ZeroMq
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)
