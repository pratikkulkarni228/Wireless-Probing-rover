Wireless Probing- rover is a Arduino based rover.
It contains 3 interdependent modules, named - Hand mounted module, Rover, Receiving station

Hand Mounted module(HMM) is responsible for controlling the rover movements by sending a stream of commands wirelessly. 
The HMM gauges the movement of hand by onboard accelerometer and sends the commands through "RF 434Mhz" simultaneously. 

Rover has 2 independent parts -
1. Motion control module 
2. Ultrasonic sensor module
both works in collaboration with each other and uses 1 Arduino Mega as a central hub
The movement data stream recieved from HMM is then decoded and movement is initiated with low latency.
2 motor drivers LM35 are used to drive motors.
On the other part the Ultrasonic sensors read the distance values and creates a data stream in specific format (Angle,distance.)
distance of object on that angle. This stream is the transfered to Receiving station.

Receiving station has another RF 434 receiver which recieves the data stream from rover, this data stream is the decoded by the computer connected
and then displayed on screen along with the angular and distance visuals.
