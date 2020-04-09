cmake_minimum_required(VERSION 3.0.0)
project(omnibase_description)

find_package(catkin_simple REQUIRED COMPONENTS
	gazebo
	rospy
	roscpp
	rviz
	urdf
	geometry_msgs
)

catkin_simple(ALL_DEPS_REQUIRED)


cs_install()
cs_export()