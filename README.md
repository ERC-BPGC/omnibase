# omnibase

## Installations:
- Install ROS melodic from [ROS website](https://www.ros.org/install/).

- Install some system dependencies by:
```bash
sudo apt install python-wstool python-catkin-tools
```

- Package installation:
```bash
# clone repo 
cd ~/catkin_ws/src
git clone https://github.com/ERC-BPGC/omnibase.git

# install dependencies from rosinstall using wstool
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
roslaunch omnibase_gazebo omnibase.launch
```

### TODO:
1) Some tweaks in model
2) Better Organization
3) Documentation

### Future Work:
Writing a gazebo Plugin