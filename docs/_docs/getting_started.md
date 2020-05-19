---
title: Welcome
permalink: /docs/home/
redirect_from: /docs/index.html
---

## About

Omnibase_simulator is an opensource simulator developed by a team of students from [Electronics and Robotics Club](https://erc-bpgc.github.io/) 
at BITS Pilani, Goa Campus.
Omnibase as the name might suggests simulates an omniwheeled robot. The robot can be spawned in the Gazebo physics engine. 


The simulator is divided into 3 packages and 1 meta package:
- omnibase_control
  - This package has script which converts the velocity published on /cmd_topic to wheel velocities.
  - The velocities can be adjusted by using the .yaml files in the config folder. 
  - There's another node written for teleoperation in this package.

- omnibase_gazebo
  - This package has the launch files to spawn the robot. 

- omnibase_description
  - This package has the description files of the robot in URDF format. 
  - In case you want to use different bodies or change the dynamics of the present ones then edit the 
    URDFs in this package. 


