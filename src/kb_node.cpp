// Authors : Koushik Kabiraj (koushik.atti@gmail.com) and Arkapravo Bhaumik (arkapravobhaumik@gmail.com)
// Date : 15 Jan 2013 
// Keyboard Teleoperation using kbhit() function -- it sends commands only when the key board is hit -- its non blocking
// Run this node with the following command -- rosrun kb_control kb_node with a master or alternatively, roslaunch kb_control kb_control.launch
// Works on ROS Electric, ROS Fuerte and ROS Groovy
// Dependencies : roscpp, geometry_msgs
// Default values gave initial velocity in the range of 23cm/s to 28cm/s for a Roomba 560 robot on a concrete floor

#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <stdio.h>

int kbhit(void)
{
	struct termios oldt, newt;
	int ch;
	int oldf;

	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

	ch = getchar();

	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	fcntl(STDIN_FILENO, F_SETFL, oldf);

	if(ch != EOF)
		{
		ungetc(ch, stdin);
		return 1;
		}

	return 0;
}
int main(int argc, char** argv)
{
    ros::init(argc, argv, "move_robot_1");
    //printf("Node Started \n");
    ros::NodeHandle nh;
    ros::Publisher vel_pub;
    int i;
    char j;
    float l_vel,a_vel;
    geometry_msgs::Twist cmdvel;
    vel_pub = nh.advertise<geometry_msgs::Twist>("cmd_vel",1);
    //printf("Connected to topic\n");
    cmdvel.linear.y=0;
    cmdvel.linear.z=0;
    cmdvel.angular.x=0;
    cmdvel.angular.y=0;
    cmdvel.angular.z=0;
    l_vel=0.25;
    a_vel=1; 	
    //printf("Started to publish \n");
    j=0;

    puts("** KEYBOARD CONTROLLED TELEOPERATION **");
    puts("#.1 use arrow keys to navigate");
    puts("#.2 x/z to increase/decrease speed by 25%");
    puts("#.3 press spacebar to stop the robot");

    while(1)
    {
        
         while(!kbhit());
         j=getchar();
	
        if(j==65)  //ascii code for forward arrow
        {
            printf("forward\n");
	    cmdvel.linear.x=l_vel;
            cmdvel.angular.z=0;
	    i=1;	
		
        }       
        else if(j==67)//ascii code for left arrow
        {
            printf("right\n");
            cmdvel.linear.x=0;
            cmdvel.angular.z=-a_vel;
	    i=2;	
        }
        else if(j==66)//ascii code for backward arrow
        {
            printf("backward\n");
            cmdvel.linear.x=-l_vel;
            cmdvel.angular.z=0;
            i=3; 
        }
        else if(j==68)//ascii code for right arrow
        {
            printf("left\n");
	    cmdvel.linear.x=0;
            cmdvel.angular.z=a_vel;
             i=4;   
        }
        else if(j==' ')
        {
            printf("stop\n");
	    cmdvel.linear.x=0;
            cmdvel.angular.z=0;
            vel_pub.publish(cmdvel);

            break;
            
        }
	else if(j=='x')
	{
	    l_vel=l_vel*1.25;
	    a_vel=a_vel*1.25;
	    printf("speed increased\n");		
		if(i==1)
		{
			cmdvel.linear.x=l_vel;
            		cmdvel.angular.z=0;
                }
		else if(i==2)
		{
			cmdvel.linear.x=0;
            		cmdvel.angular.z=-a_vel;
                }
		else if(i==3)
		{
			cmdvel.linear.x=-l_vel;
            		cmdvel.angular.z=0;
                }
		else if(i==4)
		{
			cmdvel.linear.x=0;
            		cmdvel.angular.z=a_vel;
                }
	}
        else if(j=='z')
	{
	    l_vel=l_vel/1.25;
	    a_vel=a_vel/1.25;
            printf("speed reduced\n");
		if(i==1)
		{
			cmdvel.linear.x=l_vel;
            		cmdvel.angular.z=0;
                }
		else if(i==2)
		{
			cmdvel.linear.x=0;
            		cmdvel.angular.z=-a_vel;
                }
		else if(i==3)
		{
			cmdvel.linear.x=-l_vel;
            		cmdvel.angular.z=0;
                }
		else if(i==4)
		{
			cmdvel.linear.x=0;
            		cmdvel.angular.z=a_vel;
                }
	}	
     
        vel_pub.publish(cmdvel);    
    }

    ros::spin();
    return 0;
}
