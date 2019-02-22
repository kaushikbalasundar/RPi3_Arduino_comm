# RPi3_Arduino_comm
Communicate between Rpi3 and Arduino Uno/Mega using UART

# Original reference

http://www.robopapa.com/Projects/RaspberryPiArduinoCommunication

# Components required: 

1. Raspberry Pi 3
2. Arduino Mega/Uno
3. Logic Level converter 
4. Jumper wires
5. Breadboard 

# Instructions to be followed on Raspberry Pi 3 

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

12. Sending numbers 8 and 9 via serial

`echo 8 > /dev/ttyAMA0`
`echo 9 > /dev/ttyAMA0`

IMPORTANT: Use a logic level converter to convert the 5V logic of the arduino
to the 3.3V logic used by the raspberry pi 3.

The LV indicates the low voltage side and HV indicates the high voltage side

The connections are as follows: 

3.3V and 5V devices need to have a common GND 

Tx (Arduino) ---> HV pin 1 on LLC
Rx (Arduino) ---> HV pin 2 on LLC 

Tx(Rpi3) ---> LV pin 2 on LLC
Rx(Rpi3) ---> LV pin 1 on LLC 
