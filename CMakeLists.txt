cmake_minimum_required(VERSION 3.5)

project(kick_ball_robot)

set(CMAKE_CXX_STANDARD 14)
set(SMAKE_CXX_STANDARD_REQUIRED ON)

find_package(behaviortree_cpp_v3)

add_executable(${PROJECT_NAME} "bt_demo.cpp")
target_link_libraries(${PROJECT_NAME} BT::behaviortree_cpp_v3)