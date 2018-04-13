/**

**********************************
********* PRIMO NODO ***********
**********************************

*/


#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>


int main(int argc, char **argv){
  ros::init(argc, argv, "publisher");
  ros::NodeHandle n;
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
  ros::Rate loop_rate(1);
  
	  while (ros::ok()){
    		std_msgs::String msg;
		std::stringstream ss;
		ss << "paolo_cocco 23 informatica";		
		msg.data = ss.str();
	        chatter_pub.publish(msg);
                ros::spinOnce();
		loop_rate.sleep();
	        }

  return 0;

}


