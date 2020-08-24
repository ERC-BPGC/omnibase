cmake_minimum_required(VERSION 3.0.0)
project(omnibase_description)

find_package(catkin REQUIRED COMPONENTS
	rospy
	roscpp
	geometry_msgs
)

catkin_package(
  CATKIN_DEPENDS rospy geometry_msgs roscpp
)

# Install
install(DIRECTORY launch meshes urdf xacro
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)