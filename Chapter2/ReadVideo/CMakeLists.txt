cmake_minimum_required (VERSION 2.6)
cmake_policy(SET CMP0012 NEW)
project(ReadVideo)

find_package(OpenCV 3.0.0 REQUIRED)
message("OpenCV version: ${OpenCV_VERSION}")
include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIB_DIR})

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
