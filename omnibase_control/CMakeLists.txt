cmake_minimum_required(VERSION 3.0.0)
project(omnibase_control)

add_definitions(-std=c++14)

find_package(catkin_simple REQUIRED COMPONENTS
  roscpp
  geometry_msgs
  nav_msgs
  rospy
  std_msgs
)

catkin_simple(ALL_DEPS_REQUIRED)

catkin_package()

cs_add_library(
	${PROJECT_NAME}
	src/controller.cpp)

cs_add_executable(controller_node src/controller_node.cpp)
target_link_libraries(controller_node ${PROJECT_NAME})

cs_add_executable(teleop_node src/teleop.cpp)
target_link_libraries(teleop_node ${PROJECT_NAME})

cs_install()
cs_export(LIBRARIES)