cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
project(MY_GRAND_PROJECT)
find_package(PCL 1.10 REQUIRED COMPONENTS common io)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})
add_executable(pcl_filtering pcl_filtering.cpp)
target_link_libraries(pcd_write_test ${PCL_LIBRARIES})

