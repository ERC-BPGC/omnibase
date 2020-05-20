---
title: Installation
permalink: /docs/installation/
---


Presently, the omnibase simulator can be installed only by building the packages. To use this simulator follow the instructions given below:

- Install ROS melodic from [ROS website](https://www.ros.org/install/).This package can also be built with ROS kinetic. 
Though we haven't tested the simulator with the old version of gazebo.

- Install some system dependencies by:
```bash
sudo apt install python-wstool python-catkin-tools  \
	ros-melodic-joint-state-controller  \
	ros-melodic-effort-controllers  \
	ros-melodic-joint-trajectory-controller  \
	ros-melodic-position-controllers  \
	ros-melodic-velocity-controllers
```

- Clone repo package installations:
```bash
cd ~/catkin_ws/src
git clone https://github.com/ERC-BPGC/omnibase.git
```

- Build the workspace
```
cd ..
catkin build
source devel/setup.bash
```
