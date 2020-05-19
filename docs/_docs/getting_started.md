---
title: About
permalink: /docs/home/
redirect_from: /docs/index.html
---

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

<div class="row">
  <div class="thumbnail">
    <div class="image" align="center">
        <a href="#cerulean/"><img src="https://raw.githubusercontent.com/ERC-BPGC/omnibase/master/docs/_docs/imgs/trotbot_body.jpg" class="img-responsive" width="400" alt="bot"></a>
    </div>    
  </div>
</div>

For simplicity the wheels have been modeled as cylinders. This choice of modelling the wheels give us similar results as of the omniwheels. 
The robot is equiped with a 2-D lidar sensor for obstacle detection. The odometry is obtained from a gazebo plugin
and is very accurate. 