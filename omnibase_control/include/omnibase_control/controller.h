#include <iostream>
#include <ros/ros.h>
#include <geometry_msgs/TwistStamped.h>
#include <std_msgs/Float64.h>

class controller
{
public:
	controller(ros::NodeHandle & nh, ros::NodeHandle& nh_private);

	void init_vars();

	void cmd_vel_cb(const geometry_msgs::TwistStamped &vel);
	void vel_publish();

	void stop_bot();

private:
	ros::NodeHandle nh_;
  	ros::NodeHandle nh_private_;
	
	ros::Subscriber vel_sub;

	ros::Publisher front_right_cmd_pub;
	ros::Publisher front_left_cmd_pub;
	ros::Publisher back_right_cmd_pub;
	ros::Publisher back_left_cmd_pub;

	geometry_msgs::TwistStamped velocity;
	// std_msgs::Float64 omega;
	std_msgs::Float64 omega_1, omega_2, omega_3, omega_4;
	float x_dot, y_dot;

	int vel_mul = 2;
};