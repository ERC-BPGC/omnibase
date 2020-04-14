#include <omnibase_control/controller.h>
#include <ros/ros.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "controller");
  ros::NodeHandle nh;
  ros::NodeHandle nh_private("~");

  controller contrl(nh, nh_private);
  ros::spin();
}