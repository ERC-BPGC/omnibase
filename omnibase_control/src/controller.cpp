#include <omnibase_control/controller.h>
#include <ros/ros.h>


controller::controller(ros::NodeHandle& nh, ros::NodeHandle& nh_private):nh_(nh), nh_private_(nh_private)
{
	init_vars();

	vel_sub = nh_.subscribe("cmd_vel", 5, &controller::cmd_vel_cb, this);

	front_right_cmd_pub = nh_.advertise<std_msgs::Float64>("/omnibase/front_right_joint_velocity_controller/command",10);
	front_left_cmd_pub = nh_.advertise<std_msgs::Float64>("/omnibase/front_left_joint_velocity_controller/command",10);
	back_right_cmd_pub = nh_.advertise<std_msgs::Float64>("/omnibase/back_right_joint_velocity_controller/command",10);
	back_left_cmd_pub = nh_.advertise<std_msgs::Float64>("/omnibase/back_left_joint_velocity_controller/command",10);

	stop_bot();

	ROS_INFO("----------------------------------------------------");
	ROS_INFO("Controller Initialized");
	ROS_INFO("----------------------------------------------------");
}


void controller::init_vars()
{
	omega_1.data = 0;
	omega_2.data = 0;
	omega_3.data = 0;
	omega_4.data = 0;

	x_dot = 0;
	y_dot = 0;
}


void controller::cmd_vel_cb(const geometry_msgs::TwistStamped &vel)
{
	x_dot = vel.twist.linear.x;
	y_dot = vel.twist.linear.y;

	// get the constant from a yaml file
	omega_1.data = vel_mel * (-x_dot - y_dot);
	omega_2.data = vel_mel * (y_dot - x_dot);
	omega_3.data = vel_mel * (-y_dot + x_dot);
	omega_4.data = vel_mel * (y_dot + x_dot);

	// std::cout << "omega_x is: " << omega_x << std::endl;
	// std::cout << "omega_y is: " << omega_y << std::endl;

	vel_publish();
}

void controller::vel_publish()
{	
	front_right_cmd_pub.publish(omega_1);
	front_left_cmd_pub.publish(omega_2);
	back_right_cmd_pub.publish(omega_3);
	back_left_cmd_pub.publish(omega_4);
}

void controller::stop_bot()
{	
	for (int i = 0; i < 100; i++){
		front_right_cmd_pub.publish(omega_1);
		front_left_cmd_pub.publish(omega_2);
		back_right_cmd_pub.publish(omega_3);
		back_left_cmd_pub.publish(omega_4);
	}
}