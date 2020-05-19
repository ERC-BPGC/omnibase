cmake_minimum_required(VERSION 3.0.0)
project(omnibase_control)

add_definitions(-std=c++14)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  geometry_msgs
  nav_msgs
  rospy
  std_msgs
)

#catkin_simple(ALL_DEPS_REQUIRED)

catkin_package()

include_directories(include ${catkin_INCLUDE_DIRS})

add_library(${PROJECT_NAME} src/controller.cpp)
target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES})

#cs_add_library(
#	${PROJECT_NAME}
#	src/controller.cpp)


# cs_add_executable(controller_node src/controller_node.cpp)
# target_link_libraries(controller_node ${PROJECT_NAME})

add_executable(controller_node src/controller_node.cpp)
target_link_libraries(controller_node ${PROJECT_NAME} ${catkin_LIBRARIES})

# cs_add_executable(teleop_node src/teleop.cpp)
# target_link_libraries(teleop_node ${PROJECT_NAME})

add_executable(teleop_node src/teleop.cpp)
target_link_libraries(teleop_node ${PROJECT_NAME} ${catkin_LIBRARIES})

# cs_install()
# cs_export(LIBRARIES)

install(TARGETS controller_node RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
install(TARGETS teleop_node RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
