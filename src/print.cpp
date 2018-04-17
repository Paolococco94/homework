/**

**********************************
*********** TERZO NODO ***********
**********************************

*/

#include <signal.h>
#include <ros/console.h>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include <string>
#include <string.h>

std::string comando; // global variable where save the command coming from the node2 "select.cpp"
std::string dato;    // global variable where save the data coming from the node1 "publisher.cpp"

std::string aa = "A"; // value that identifies the whole string  
std::string nn = "N"; // value that identifies the name
std::string ee = "E"; // value that identifies the age
std::string cc = "C"; // value that identifies the graduation  
std::string zz = "Z"; // value that identifies exit of program

// Topic messages callback	
void chatterCallback(const std_msgs::String::ConstPtr& msg){  
	dato = msg->data;
	
}


void chatterCallback2(const std_msgs::String::ConstPtr& msg2){  
	comando = msg2->data; 
        
}


// string printing function 
void check(std::string dato,std::string comando){
 std::string name;
 std::string age;
 std::string course;
 
		
	if (comando.compare(aa)==0){	
		ROS_INFO("string: %s\n", dato.c_str());  
	}	
	
	else if(comando.compare(nn)==0){
	 	name = dato.substr(0, 11);
		ROS_INFO("name: %s\n", name.c_str()); 
	}
	

	else if(comando.compare(ee)==0){
		age = dato.substr(12,2);
		ROS_INFO("age: %s\n", age.c_str());
	}
	

	else if  (comando.compare(cc)==0){
		course = dato.substr(15);
		ROS_INFO("course: %s\n", course.c_str());	 	
	}
	
        
	else if  (comando.compare(zz)==0){
			ROS_INFO("EXIT PROGRAM\n");			
			ros::shutdown();
	}

	else
		ROS_INFO("comando selezionato non valido\n");
		
	
}


int main(int argc, char **argv){
// initialization

ros::init(argc, argv, "print");
ros::NodeHandle n;

while(ros::ok()){
// listener for the data
   ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
	while(dato == ""){ 
	ros::spinOnce();
	}
// listener for the comand  
  ros::Subscriber sub2 = n.subscribe("chatter2", 1000, chatterCallback2);
  	while(comando ==""){
 	ros::spinOnce();
	}

	check(dato,comando);	
	comando = ""; //la stringa comando deve essere vuota dopo la funzione check
		      //altrimenti il cliclo [while(comando=="")] non viene eseguito
		      //dopo il lancio del programma 

}

return 0;
}

