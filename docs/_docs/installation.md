---
title: Installation
permalink: /docs/installation/
---

### Installations:

Presently, the omnibase simulator can be installed only by building this package. To use this package follow the instructions given below:

- Install ROS melodic from [ROS website](https://www.ros.org/install/).This package can also be built with ROS kinetic. 
Though we haven't tested the package with the old version of gazebo.

- Install some system dependencies by:
```bash
sudo apt install python-wstool python-catkin-tools  \
	ros-melodic-joint-state-controller  \
	ros-melodic-effort-controllers  \
	ros-melodic-joint-trajectory-controller  \
	ros-melodic-position-controllers  \
	ros-melodic-velocity-controllers
```

- Package installation:
```bash
# Clone repo 
cd ~/catkin_ws/src
git clone https://github.com/ERC-BPGC/omnibase.git

# Build the workspace
cd ..
catkin build
source devel/setup.bash
```

### Usage:

To use this simulator use:
```bash
# To launch empty world
roslaunch omnibase_gazebo omnibase.launch

# To launch obstacle rich env
roslaunch omnibase_gazebo omnibase_world1.launch

# To test the bot run the teleop_node
rosrun omnibase_control teleop_node
```