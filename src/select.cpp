/**

**********************************
********* SECONDO NODO ***********
**********************************

*/




#include "ros/ros.h"
#include "std_msgs/String.h"
#include <iostream>       // std::cout
#include <string>         // std::string
std::string scelta;

void stampaMenu (){
  std::cout << "\n";
  std::cout << "****************************************************************\n";
  std::cout << "Menù: \n";
  std::cout << "Seleziona operazione da eseguire\n" ;
  std::cout << "Digita 'A' per stampare tutto il messaggio\n" ;
  std::cout << "Digita 'N' per stampare il nome\n" ;
  std::cout << "Digita 'E' per stampare l'età\n" ;
  std::cout << "Digita 'C' per stampare il corso di laurea\n";
  std::cout << "Digita 'Z' per uscire dal programma\n";
  std::cout << "\n";
  std::cout << "****************************************************************\n";
}


int main(int argc, char **argv){
// initialization
	ros::init(argc, argv, "select");
	ros::NodeHandle n;
// publisher for selecting command
	ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter2", 1000);	

  	
	while (ros::ok()){
	stampaMenu();
		std::cin >> scelta;
		ROS_INFO("hai selezionato %s",scelta.c_str());
		std_msgs::String msg2;
		std::stringstream ss2;
		ss2 << scelta;
		msg2.data = ss2.str();
		chatter_pub.publish(msg2);           
		ros::Rate loop_rate(1);
		
		ros::spinOnce();// processing of incoming messages
        			// When a message arrives, ROS pushes your subscriber callback onto a queue.
        			// It does not call it immediately. ROS only processes your callbacks when
        			// you tell it to with ros::spinOnce()
		
		loop_rate.sleep();
		
		if(scelta=="Z"){
		ros::shutdown();
		}		
  }


return 0;

}
