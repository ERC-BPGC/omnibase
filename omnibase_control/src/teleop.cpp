#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <map>

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

// Global Vars



// -------------------------------

std::map<char, std::vector<float>> moveBindings
{	
	// lin_x, lin_y, ang_z
	{'w', {0.5, 0, 0}},
	{'x', {-0.5, 0, 0}},
	{'a', {0, 0.5, 0}},
	{'d', {0, -0.5, 0}},
	{'s', {0, 0, 0}},
	{'q', {0, 0, -0.5}},
	{'e', {0, 0, 0.5}},
};

void print_message(){
	std::cout << "Reading from keyboard and publishing on cmd_vel..." << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;

	std::cout << "To move around use:" << std::endl;
	std::cout << "       w     " << std::endl;
	std::cout << "  a    s    d" << std::endl;
	std::cout << "       x     " << std::endl;
	
	std::cout << "To rotate the bot use:" << std::endl;
	std::cout << "q/e for anti-clockwise/clockwise rotation" << std::endl;

	std::cout << "\nPress the key again to increase the velocity..." << std::endl;
}


// For non-blocking keyboard inputs
int getch()
{
  int ch;
  struct termios oldt;
  struct termios newt;

  // Store old settings, and copy to new settings
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;

  // Make required changes and apply the settings
  newt.c_lflag &= ~(ICANON | ECHO);
  newt.c_iflag |= IGNBRK;
  newt.c_iflag &= ~(INLCR | ICRNL | IXON | IXOFF);
  newt.c_lflag &= ~(ICANON | ECHO | ECHOK | ECHOE | ECHONL | ISIG | IEXTEN);
  newt.c_cc[VMIN] = 1;
  newt.c_cc[VTIME] = 0;
  tcsetattr(fileno(stdin), TCSANOW, &newt);

  // Get the current character
  ch = getchar();

  // Reapply old settings
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

  return ch;
}

void print_vel(const geometry_msgs::Twist &vel)
{
	std::cout << "Currently: lin_x is " << vel.linear.x << " lin_y is " << vel.linear.y << " and ang_z is " << vel.angular.z << std::endl;
}

int main(int argc, char** argv)
{
	ros::init(argc, argv, "teleop_keyboard");
	ros::NodeHandle nh;
	ros::NodeHandle nh_private("~");

	ROS_INFO("Starting Teleop Node\n");

	ros::Publisher vel_pub = nh.advertise<geometry_msgs::Twist>("cmd_vel", 1);
	geometry_msgs::Twist vel;

	print_message();

	char key(' ');
	float x(0), y(0), ang_z(0);


	while(ros::ok()){
		key = getch();

		if (moveBindings.count(key) > 0) // key exists in the map
		{
			if (key != 's')
			{
				x = x + moveBindings[key][0];
				y = y + moveBindings[key][1];
				ang_z = ang_z + moveBindings[key][2];
			}
			else{
				x = moveBindings[key][0];
				y = moveBindings[key][1];
				ang_z = moveBindings[key][2];

				std::cout << "\n\n" << std::endl;
				print_message();
			}
		}
		if (key == '\x03') // Ctrl+C 
		{
			ROS_INFO("CLOSING TELEOP NODE\n");
			break;
		}

		vel.linear.x = x;
		vel.linear.y = y;
		vel.linear.z = 0;
		vel.angular.x = 0;
		vel.angular.y = 0;
		vel.angular.z = ang_z;

		vel_pub.publish(vel);
		print_vel(vel);
		ros::spinOnce();
	}
}
