cmake_minimum_required(VERSION 3.0.0)
project(omnibase_gazebo)

find_package(catkin REQUIRED COMPONENTS
  gazebo_msgs
  geometry_msgs
  roscpp
  sensor_msgs
  std_msgs
)


# catkin_simple(ALL_DEPS_REQUIRED)

# cs_install()
# cs_export()