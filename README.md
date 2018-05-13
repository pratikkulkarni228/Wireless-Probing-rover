# Wireless-Probing-rover

## Motivation:

There are places where humans cannot physically enter. Our project is focused on solving this problem by provising a solution, to send a robot in the area that will give a better idea about the place so that humans can enter in it later.

## Solution:

We build a robot that will act as a RADAR system detecting obstacles in it's way to alarm an individual sitting on a remote workstation, controlling the robot from a distance.
We have fabricated three major components viz. Hand mounted module, Robot and Receiver at the remote workstation.
The remote workstation will map the data gathered from the robot in 2D using the Processing development environment.

## Requirements:

1. Arduino Boards (Mega, Leonardo and Uno)
2. Sensors (ADXL335 - Accelerometer, HC-Sr04 - Ultrasonic sensor, RF434 - Radio frequency transmitter and receiver)
3. 0 PCBs
4. VirtualWire library
5. Other hardware (Servo motor, DC motors, Wires, Batteries etc.)

## Procedure:

### 1. Construction of Hand-mounted module:

The hand mounted module will send data from the accelerometer, tracking the movements of the bearers hand, to the robot at a remote location using RF434.
We use Arduino Uno for gathering data from ADXL335 accelerometer and sending this data using RF434 Tx to the robot.

### 2. Construction of Robot:

The robot has DC motors that are guided based on the input received from the hand mounted module, for receiving, RF434 Rx is used.
Also, there is one servo motor mounted on the robot that controls the motion of the ultrasonic sensor.
The ultrasonic sensor gathers the distance from the robot to the obstacle and the exact angle of at which the servo was when the obstacle was detected, and sends it on a different channel using RF434 Tx to the remote workstation.

### 3. Remote workstation:

The workstation receives data from the robot using RF434 Rx and prints the angle and distace obtained on the serial monitor.
This data is picked by the processing development environment from the serial monitor and is shown on a graph in real-time.

