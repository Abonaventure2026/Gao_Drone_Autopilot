cmake_minimum_required(VERSION 3.16)
project(Gao_Drone_Autopilot)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(../Gao_4A_Autopilot ${CMAKE_BINARY_DIR}/gao_base)

find_package(Eigen3 REQUIRED)
find_package(yaml-cpp QUIET)
find_package(OpenCV QUIET)

file(GLOB_RECURSE BRANCH_SRCS edge/*.cpp)
add_executable(gao_autopilot ${BRANCH_SRCS})
target_include_directories(gao_autopilot PRIVATE edge)

target_link_libraries(gao_autopilot gao_base Eigen3::Eigen)

if(yaml-cpp_FOUND)
    target_link_libraries(gao_autopilot yaml-cpp)
endif()
if(OpenCV_FOUND)
    target_link_libraries(gao_autopilot ${OpenCV_LIBS})
endif()
