# RPi3_Arduino_comm
Communicate between Rpi3 and Arduino Uno/Mega using UART

## OPTION1: USING MINICOM

### Original reference

http://www.robopapa.com/Projects/RaspberryPiArduinoCommunication

### Components required: 

1. Raspberry Pi 3
2. Arduino Mega/Uno
3. Logic Level converter 
4. Jumper wires
5. LEDs
6. Breadboard 

### Instructions to be followed on Raspberry Pi 3 

The following steps are to be followed in the raspberry pi

1. `sudo apt-get update`
2. `sudo apt-get upgrade` 
3. `sudo apt-get install minicom` 
4. `cd /boot`
5. `ls -l cmdline.txt`
6. `sudo cp cmdline.txt cmdline.txt.backup` (make a backup copy)
7. `ls -l cmdline.txt*` (to see all the files under cmd line)
8. Delete the reference for ttyAMA0
9.` cd /etc`
10. `ls -l inttab.backup & delete the reference for ttyAMA0` (present all the way at the bottom)
(comment the line that contains this. It is present towards the end)
11. `sudo minicom -b 9600 -o -D /dev/ttyAMA0`

13.  Complete connections as described below using the Logic level converter and 

IMPORTANT: Use a logic level converter to convert the 5V logic of the arduino
to the 3.3V logic used by the raspberry pi 3.

The LV indicates the low voltage side and HV indicates the high voltage side

The connections are as follows: 

3.3V and 5V devices need to have a common GND 

Tx (Arduino)    --->      HV pin 1 on LLC
Rx (Arduino)    --->      HV pin 2 on LLC 

Tx(Rpi3)        --->      LV pin 2 on LLC
Rx(Rpi3)        --->      LV pin 1 on LLC 

LED GNDs        --->      Arduino GND
LED 1 Cathode   --->      Arduino Pin 7
LED 2 Cathode   --->      Arduino Pin 8
LED 3 Cathode   --->      Arduino Pin 9

14. Sending numbers 8 and 9 via serial

`echo 7 > /dev/ttyAMA0`

`echo 8 > /dev/ttyAMA0`

`echo 9 > /dev/ttyAMA0`


# OPTION 2: WITHOUT USING MINICOM

### Original References:

https://classes.engineering.wustl.edu/ese205/core/index.php?title=Serial_Communication_between_Raspberry_Pi_%26_Arduino
https://www.teachmemicro.com/raspberry-pi-serial-uart-tutorial/#

### Components Required: 

1. Arduino Uno/Mega
2. Raspberry Pi 
3. 5V to 3.3V Logic Level Converter
4. Jumpers

### Connections: 

![Follow this connection diagram](https://i0.wp.com/www.teachmemicro.com/wp-content/uploads/2018/06/Arduino-UNO-Raspberry-Pi-connection_bb.jpg?ssl=1)

We are using a logic level converter to convert the 5V signals sent by the Arduino into 3.3V signals that can be received safely by the 
Raspberry Pi 3 without damaging the RPi3. 

### Procedure1 : Rpi3 to Arduino Uno 

1. Upload rpitoarduino.py into your Raspberry pi 3 and execute the program. The script will send "hello" to the Arduino
2. Open the SerialEvent on the Arduino IDE.  Go to File > Examples > 04.Communication > SerialEvent.  
3. Open Serial monitor and set the baud rate to 9600
4. Execute rpitoarduino.py script on your pi and you should be able to see hello being printed on the serial monitor of your arduino
at the baud rate of 9600. 
5. Measure the pulse width of the signal using oscilloscope and record. 

### Procedure2: Arduino to  Rpi3 

1. Upload arduinotorpi.py onto your Raspberry Pi 3. 
2. Upload arduinotorpi.uno onto your Arduino board 
3. Execute both codes on the devices and you should be able to see hello being printed on the terminal of your raspberry pi 3 at the baud rate of 9600. 
4. Measure the pulse width of the signal being sent by Arduino to Raspberry Pi 3 at the baud rate of 9600 and record. 

Hypothesis: Pulse duration of both the  cases need to be the same as the same data is being sent.





