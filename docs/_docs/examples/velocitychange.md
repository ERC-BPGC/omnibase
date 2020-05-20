---
title: Velocity Parameterization
permalink: /docs/velocity/
---

This example talks about the velocity parameterization functionality, that has been implemented in the controller.


The controller takes the following parameters:
- Radius of the wheels
- Diagonal distance between the wheels
- A velocity multiplying factor
- Maximum linear velocity 
- Maximum angular velocity

So, it can be generalised for any omniwheeled robot. The controller takes in the velocity from 
```/cmd_vel``` topic and converts it into individual wheel velocities. The wheel velocities are 
multiplied by the constant specified in [```yaml```](https://github.com/ERC-BPGC/omnibase/blob/master/omnibase_control/config/params_trot.yaml) file. 

<div class="row">
  <div class="thumbnail">
    <div class="image" align="center">
        <a href="#"><img src="https://raw.githubusercontent.com/ERC-BPGC/omnibase/master/docs/_docs/imgs/controller.jpg" class="img-responsive" width="400" alt="bot"></a>
    </div>    
  </div>
</div>

Above figure shows the ```rqt_graph``` of the controller_node. 