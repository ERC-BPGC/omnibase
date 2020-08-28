---
title: Installation
permalink: /docs/installation/
---

This package has been tested on Ubuntu 18.04 with ROS melodic. So I would suggest you to install 
ROS melodic from the [ROS website](https://www.ros.org/install/). This package can also be built from 
source with ROS kinetic. Though we haven't tested the simulator with the old version of gazebo.

Omnibase simulator can be installed on Ubuntu 18.04 with ROS melodic using the following commands:
```bash
sudo apt update
sudo apt install ros-melodic-omnibase-control 
sudo apt install ros-melodic-omnibase-gazebo 
sudo apt install ros-melodic-omnibase-description
```

To build the simulator from source follow the following instructions:

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

#### Note: 
IF YOU FACE ANY PROBLEMS THEN PLEASE RAISE ISSUES IN THIS REPOSITORY: [omnibase](https://github.com/ERC-BPGC/omnibase)

