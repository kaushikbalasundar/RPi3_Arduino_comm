
/* 
The following code is written to communicate between arduino mega and rpi3 via 
# UART communication. The following steps are to be followed in the raspberry pi

# 1. sudo apt-get update
# 2. sudo apt-get upgrade 
# 3. sudo apt-get install minicom 
# 4. cd /boot
# 5. ls -l cmdline.txt
# 6. sudo cp cmdline.txt cmdline.txt.backup (make a backup copy)
# 7. ls -l cmdline.txt* (to see all the files under cmd line)
# 8. Delete the reference for ttyAMA0
# 9. cd /etc
# 10. ls -l inttab.backup & delete the reference for ttyAMA0 (present all the way at the bottom)
# (comment the line that contains this. It is present towards the end)
# 11. sudo minicom -b 9600 -o -D /dev/ttyAMA0
# echo 8 > /dev/ttyAMA0
# echo 9 > /dev/ttyAMA0
# sending the numbers 8 and 9 via serial 
# Flash the following code onto your arduino: 
*/



int const redPin = 9;
int const yellowPin = 8;
int const greenPin = 7;

void setup()
{
pinMode(redPin,OUTPUT);
pinMode(yellowPin,OUTPUT);
pinMode(greenPin,OUTPUT);
TurnOffAll();
Serial.begin(9600);

}

void loop()
{
if(Serial.available()>0)
{
int pinNumber = GetPinNumber();
Serial.readString();
Serial.print("Value Serial got:");
Serial.println(pinNumber);
TurnOffAll();
TurnCorrespondedLED(pinNumber);
delay(250);
}

}

int GetPinNumber()
{
int pinNumber = 0;

while(Serial.available()>0)
{
char val = Serial.read();
Serial.println(val);
pinNumber*=10;
pinNumber+= (val-'0');
delay(25);
}

return pinNumber;
}

void TurnCorrespondedLED(int pinNumber)
{
if(pinNumber == redPin || pinNumber == yellowPin || pinNumber == greenPin)
digitalWrite(pinNumber,HIGH);

}

void TurnOffAll()
