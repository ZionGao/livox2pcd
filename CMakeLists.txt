cmake_minimum_required(VERSION 3.0)
project(livox2pcd)

set(CMAKE_CXX_STANDARD 14)
find_package(PCL REQUIRED)
add_definitions(${PCL_DEFINITIONS})
include_directories(${PCL_INCLUDE_DIRS})

add_subdirectory(sdk_core sdk_core)

add_library(livox2pcd_shared SHARED gen_pcd.cpp lvx_file.cpp gen_pcd.h)
add_executable(livox2pcd main.cpp)
target_link_libraries(livox2pcd livox2pcd_shared)

if (WIN32)
    add_custom_command(TARGET ${DEMO_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${PROJECT_SOURCE_DIR}/third_party/apr/bin/libapr-1.dll"
            $<TARGET_FILE_DIR:${DEMO_NAME}>)
endif()

target_link_libraries(livox2pcd_shared
        PRIVATE
        ${PROJECT_NAME}_static
        ${PCL_LIBS}
        ${PCL_COMMON_LIBRARIES}
        ${PCL_IO_LIBRARIES}
        ${PCL_VISUALIZATION_LIBRARIES}
        ${PCL_RESISTRATION_LIBRARIES}
        ${PCL_FILTERS_LIBRARIES}
        ${PCL_FEATURES_LIBRARIES}
        ${Boost_LIBRARIES}
        )
