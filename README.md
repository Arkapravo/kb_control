kb_control
==========
Authors : Koushik Kabiraj (koushik.atti@gmail.com) and Arkapravo Bhaumik (arkapravobhaumik@gmail.com)

Teleoperation in ROS, works in ROS Groovy, ROS Fuerte and ROS Electric.

Running the node in ROS
-----------------------
Run the node with _roslaunch kb_control kb_control.launch_

Running teleoperation in MORSE via ROS nodes
--------------------------------------------
For simulation in MORSE via ROS nodes,  

1. Place the file kb_control/morse/two_atrv.py at /opt/ros/morse/share/morse/examples/scenarii/
2. Start an instance of the master
3. Start the morse simulation, _cd /opt/ros/morse/share/morse/examples/scenarii/ && morse run two_atrv_
4. Start the kb_node, _roslaunch kb_control kb_control_morse.launch_
5. Now you should be able to control castor with ROS and pollux with MORSE  
  a. Click on the blender screen, the arrow keys will move pollux around  
  b. Click on the kb_control terminal window, the arrow keys will move castor around

This is tested on ROS Fuerte and MORSE 0.6
