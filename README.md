# omnibase

| -                              | Tag                                                                                                                                                             |
|---------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------|
| License                               | [![License](https://img.shields.io/badge/License-BSD%203--Clause-blue.svg)](https://opensource.org/licenses/BSD-3-Clause)                                       |
| Travis Build Status                   | [![Build Status](https://travis-ci.org/ERC-BPGC/omnibase.svg?branch=master)](https://travis-ci.org/ERC-BPGC/omnibase)                                           |
| Jenkins Build Status (ROS Build Farm) | [![Build Status](http://build.ros.org/job/Mdev__omnibase__ubuntu_bionic_amd64/badge/icon)](http://build.ros.org/job/Mdev__omnibase__ubuntu_bionic_amd64/) |

## About: 
Omnibase is a simulator of a 4 wheel drive robot. The robot is an omniwheeled robot and can move in any direction in the X-Y plane.  

For more detailed documentation click [here](https://erc-bpgc.github.io/omnibase/).

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

- Package installation from rosdep:
```bash
sudo apt update
sudo apt install ros-melodic-omnibase-control 
sudo apt install ros-melodic-omnibase-gazebo 
sudo apt install ros-melodic-omnibase-description
```

- Package installation from source:
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

