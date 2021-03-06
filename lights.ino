/**********************************************************************************************

 * FILE          : lights.ino

 * PROJECT       : Home lightning control system

 * PROGRAMMER    : Prabhjot singh

 * DESCRIPTION   : This program is used to control lights by android mobile using bluetooth 
       interface with arduino 

*******************************************************************************************/


int light_pin=13;
int state;

// FUNCTION      : setup
// DESCRIPTION   : This function runs once to initilize all the things
// PARAMETERS    : Nothing
// RETURNS       : Nothing
void setup() 
{
  Serial.begin(9600);     //set serial communication at baud rate of 9600 
  pinMode(light_pin,OUTPUT);    //set pin in Output mode
}

// FUNCTION      : loop
// DESCRIPTION   : This function runs continously,gets data from serial port,
//       nad based on that data,switches light on/off using light pin 
// PARAMETERS    : Nothing
// RETURNS       : Nothing
void loop() 
{
  /*..if getting data from serial port..*/
  if (Serial.available() > 0)
    state= Serial.read();
  
  /*..if output character from serial port is 1,then turn on light..*/
  if( state == '1' )
    digitalWrite(light_pin,HIGH);
  
  /*..if output character from serial port is 2,then turn off light..*/
  if( state == '2' )
    digitalWrite(light_pin,LOW);
    
  /*..if output character from serial port is 3,then blink light..*/
  if( state == '3')
    {
          digitalWrite(light_pin,HIGH);
        delay(250);
        digitalWrite(light_pin,LOW);
        delay(250);
    }
  delay(100);
}
