kb_control
==========
Authors : Koushik Kabiraj (koushik.atti@gmail.com) and Arkapravo Bhaumik (arkapravobhaumik@gmail.com)

Teleoperation in ROS, works in ROS Groovy, ROS Fuerte and ROS Electric.

Running the node in ROS
-----------------------
Run the node with 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
roslaunch kb_control kb_control.launch
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
now this node can be used with stage, gazebo and real robots

Running teleoperation in MORSE via ROS nodes
--------------------------------------------
To marry ROS Fuerte with MORSE 0.6 in Ubuntu 12.04 see these instructions, 
http://www.warp1337.com/content/morse-and-ros-detailed-installation-howto-ubuntu-precise

ROS fuerte prefix -- _/opt/ros/fuerte_  
MORSE prefix -- _/opt/ros/morse_

To run the simulation in MORSE via ROS nodes,  

1. Place the file _kb_control/morse/two_atrv.py_ at _/opt/ros/morse/share/morse/examples/scenarii/_
2. Start an instance of the master
3. Start the morse simulation, 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cd /opt/ros/morse/share/morse/examples/scenarii/ && morse run two_atrv.py
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

4. Start the kb_node, 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
roslaunch kb_control kb_control_morse.launch
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

5. Now you should be able to control Castor with ROS and Pollux with MORSE  
  a. Click on the blender screen, the arrow keys will move Pollux around  
  b. Click on the kb_control terminal window, the arrow keys will move Castor around

This is tested on ROS Fuerte and MORSE 0.6

![Image Alt](https://lh4.googleusercontent.com/-p9b3vgPXNh0/UQavBlGL7oI/AAAAAAAACT4/IC9tKKJILJE/s912/pic-3-github.png) 
