/*
 * 
 * Distance ultrasonic sensor
 * values used to define the
 * frequence of a blinking led
 * 
 */


#define ECHOPIN 6        // Pin to receive echo pulse
#define TRIGPIN 8        // Pin to send trigger pulse
#define LEDPIN 13

/*
 * setup function
 * Initialize the serial line (D0 & D1) at 115200.
 * Then set the pin defined to receive echo in INPUT 
 * and the pin to trigger to OUTPUT.
 */
 
void setup()
{

  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  pinMode(LEDPIN, OUTPUT);
}

/*
 * loop function.
 * 
 */
void loop()
{
  float distance = lerDistancia();

  digitalWrite(LEDPIN, HIGH);  
  delay(abs(distance));
  digitalWrite(LEDPIN, LOW);  
  
  delay(100);

}

float lerDistancia(){
  
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);
    
  float distance = pulseIn(ECHOPIN, HIGH);
  distance = distance/100;
  
  return   distance;
}




