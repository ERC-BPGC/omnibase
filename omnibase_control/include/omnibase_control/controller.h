#include <iostream>
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/Float64.h>
#include <nav_msgs/Odometry.h>

#include <tf2/LinearMath/Quaternion.h>
#include <tf2_ros/transform_broadcaster.h>
#include <geometry_msgs/TransformStamped.h>


class controller
{
public:
	controller(ros::NodeHandle & nh, ros::NodeHandle& nh_private);

	void init_vars();

	void cmd_vel_cb(const geometry_msgs::Twist &vel);

	void odom_cb(const nav_msgs::Odometry &);

	void vel_publish();

	void stop_bot();

	void get_params();
	
private:
	ros::NodeHandle nh_;
  	ros::NodeHandle nh_private_;
	
	ros::Subscriber vel_sub;
	ros::Subscriber odom_sub_;
	
	ros::Publisher front_right_cmd_pub;
	ros::Publisher front_left_cmd_pub;
	ros::Publisher back_right_cmd_pub;
	ros::Publisher back_left_cmd_pub;

	geometry_msgs::Twist velocity;
	// std_msgs::Float64 omega;
	std_msgs::Float64 omega_1, omega_2, omega_3, omega_4;
	float x_dot, y_dot;
	float yaw;

	float vel_mul, wheel_rad, diag_dist;

	float max_lin_vel, max_angular_vel;
};