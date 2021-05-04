/******************************************************************************/
/** File Name:            Robot_FirstDraft
*
* Description:          This program is used to take in the infomation from the PIC18F45K20 and use
*                       it to move the appropriate servo of the DF Bionic Robotic Hand.
*                       Initial configuration of the robotic hand was done using the sample code provided with the robot: 
*                       copyright [DFRobot](https://www.dfrobot.com), 2017
*                       The idea to use characters to help distinguish which finger 
*                       had moved was taken from: https://www.instructables.com/Flex-Sensor-Controlled-Robot/
*                       All code was writen specifically for this project. 
*                       
* Programmer:           Emma Murphy
*
* Date:                 24/02/2021
*
* Version:              1.0*/
/******************************************************************************/   

#include <Servo.h>
#include <SoftwareSerial.h>

Servo Thumbservo;
Servo Pinkyservo;
Servo Ringservo;
Servo Middleservo;
Servo Indexservo;

SoftwareSerial hc06(12, 13);  // arduino pin 12 (TXD of HC06), pin 13 (RXD of HC06)

// variables
char BluetoothData = 0;

// Pin assignments
int thumb = 3; 
int index = 5; 
int middle = 6;
int ring = 9;  
int pinky = 10;

void setup() {

  //Initialize Bluetooth Serial Port
  hc06.begin(9600);

   //Initialize Serial Monitor
  Serial.begin(9600);
  Serial.println("Serial Monitor ready...");
  
  pinMode(thumb, OUTPUT);
  pinMode(index, OUTPUT);
  pinMode(middle, OUTPUT);
  pinMode(ring, OUTPUT);
  pinMode(pinky, OUTPUT);
  
  Thumbservo.attach(3);   //thumb servo
  Indexservo.attach(5);  //index finger servo
  Middleservo.attach(6);  //middle finger servo
  Ringservo.attach(9);  //ring finger servo
  Pinkyservo.attach(10);   //little finger servo
    

  Thumbservo.write(50);   //thumb
  Indexservo.write(50);   //index finger
  Middleservo.write(60);   //middle finger
  Ringservo.write(50);   //ring finger
  Pinkyservo.write(60);   //little finger
  delay(1000);

}

void loop()
{
//Write data from HC06 to Serial Monitor
  if (hc06.available())          // something has arrived on bluetooth
  {
    BluetoothData = hc06.read();

    Serial.print("BT RX: ");
    Serial.println(BluetoothData);
    Serial.println(BluetoothData, DEC);

    
/* The Arduino reads in a value from the HC06 Bluetooth module.
 *  The PIC has sent a certain character based on how much a certain finger has moved.
 */
 /*The characters from a to d tells the Arduino that the thumb has moved.
  * The thumb servo is then moved depending on which character arrived through Bluetooth.
  */
   if (BluetoothData == 'a')  //Closed fist
    {
      Thumbservo.write(160);//thumb
    }
    
   if (BluetoothData == 'b')  //slightly open
    {
      Thumbservo.write(130);//thumb
    }
    
   if (BluetoothData == 'c')  //almost fully open
    {
      Thumbservo.write(95);//thumb
    }
    
   if (BluetoothData == 'd')  //completely open
    {
      Thumbservo.write(60);//thumb
    }      

 /*The characters from e to h tells the Arduino that the index finger has moved.
  * The index servo is then moved depending on which character arrived through Bluetooth.
  */
    if (BluetoothData == 'e')  //closed fist
    {
      Indexservo.write(140);//index
    }

    if (BluetoothData == 'f')  //slightly open
    {
      Indexservo.write(110);//index
    }

    if (BluetoothData == 'g')  //almost fully open
    {
      Indexservo.write(80);//index
    }

    if (BluetoothData == 'h')  //completely open
    {
      Indexservo.write(50);//index
    }
  /*The characters from i to l tells the Arduino that the middle finger has moved.
  * The middle servo is then moved depending on which character arrived through Bluetooth.
  */
    if (BluetoothData == 'i')  //closed fist
    {
      Middleservo.write(150); //middle
    }

    if (BluetoothData == 'j')  //slightly open
    {
      Middleservo.write(120); //middle
    }

    if (BluetoothData == 'k')  //almost fully open
    {
      Middleservo.write(85); //middle
    }

    if (BluetoothData == 'l')  //completely open
    {
      Middleservo.write(50); //middle
    }
  /*The characters from m to p tells the Arduino that the ring finger has moved.
  * The ring servo is then moved depending on which character arrived through Bluetooth.
  */
    if (BluetoothData == 'm')  //closed fist
    {
      Ringservo.write(140); //ring
    }

    if (BluetoothData == 'n')  //slightly open
    {
      Ringservo.write(110); //ring
    }

    if (BluetoothData == 'o')  //almost fully open
    {
      Ringservo.write(80); //ring
    }

    if (BluetoothData == 'p')  //completely open
    {
      Ringservo.write(50); //ring
    }
  /*The characters from q to t tells the Arduino that the pinky finger has moved.
  * The pinky servo is then moved depending on which character arrived through Bluetooth.
  */
    //Pinky Finger
    if (BluetoothData == 'q')  //closed fist
    {
      Pinkyservo.write(150); //pinky
    }

    if (BluetoothData == 'r')  //slightly open
    {
      Pinkyservo.write(120); //pinky
    }

    if (BluetoothData == 's')  //almost fully open
    {
      Pinkyservo.write(85); //pinky
    }

    if (BluetoothData == 't')  //completely open
    {
      Pinkyservo.write(50); //pinky
    }
    
}
}
