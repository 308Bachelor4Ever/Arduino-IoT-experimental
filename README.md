# Arduino-IoT-experimental
## Purpose of this repository
This repository is part of a school project for the subject “Internet Technologies” (IS-308 at the University of Agder). The content is mostly experimental, and prototype in nature for testing different IoT implementations based on user stories. 

## How-to
We try making the entry point for using this repository as simple as possible for implementing in an own project. 

Simply download the Arduino IDE (www.arduino.cc), and install the libraries from the “libraries” folder in this repository (Add .ZIP Library… in Arduino IDE). 

![](attachements/Screenshot%202018-11-23%20at%2014.12.06.png)

Also, be sure to unzip the files in the “tools” folder and add the files to the Arduino user directory, usually located in: 
Windows:
`C:\Users\$YOURUSER\Documents\Arduino`

macOS:
`~/Documents/Arduino`

Linux:
`~/Arduino`

Once you have installed the necessary libraries you should be able to compile and run each .ino file found in each project folder. 

Note: do not update libraries. This could break the project, and could require a degree of refactoring. Update libraries in the repo and notify in the commit if you are updating code against newer libraries. Do at your own risk!

## Start using WiFi functionality
Open the BlinkLED folder in this repository and follow the instructions. This is to configure the WiFi-module. 
