# Author : Arkapravo Bhaumik (arkapravobhaumik@gmail.com)
# 27 January 2013, Sunday
# ROS Fuerte, installed at /opt/ros/
# MORSE 0.6 installed at /opt/ros/
# This file should be placed at /opt/ros/morse/share/morse/examples/scenarii

from morse.builder import *

# Append ATRV robot castor to the scene
castor = Robot('atrv')

# Append an actuator to castor
motion = Actuator('v_omega')
motion.translate(z=0.3)
castor.append(motion)

# Append a Gyroscope sensor
gyroscope = Sensor('gyroscope')
gyroscope.translate(z=0.83)
castor.append(gyroscope)

# Configuring the middlewares
gyroscope.configure_mw('ros')
motion.configure_mw('ros')

# Append ATRV robot pollux to the scene
pollux = Robot('atrv')
# pollux.translate (x=1.0, z=0.2)

# Append Keyboard Control to pollux
Keyb = Actuator('keyboard')
Keyb.properties(Speed=3.0)
pollux.append(Keyb)

#Set up environment
env = Environment('indoors-1/indoor-1')
env.aim_camera([1.0470, 0, 0.7854])

