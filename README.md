# omnibase

[![License](https://img.shields.io/badge/License-BSD%203--Clause-blue.svg)](https://opensource.org/licenses/BSD-3-Clause)
[![Build Status](https://travis-ci.org/ERC-BPGC/omnibase.svg?branch=master)](https://travis-ci.org/ERC-BPGC/omnibase)

## Installations:
- Install ROS melodic from [ROS website](https://www.ros.org/install/).

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

# Install dependencies from rosinstall using wstool
wstool init
wstool merge omnibase/omnibase_https.rosinstall

# Finally download and update the repos
wstool update

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

