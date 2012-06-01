
/*
 * Distance ultrasonic sensor
 * values in centimeters
 * only prints in serial monitor
 */

#define ECHOPIN 6        // Pin to receive echo pulse
#define TRIGPIN 8        // Pin to send trigger pulse

/*
 * setup function
 * Initialize the serial line (D0 & D1) at 115200.
 * Then set the pin defined to receive echo in INPUT 
 * and the pin to trigger to OUTPUT.
 */
 
void setup()
{
  Serial.begin(115200);
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
}

/*
 * loop function.
 * 
 */
void loop()
{
  float distance = lerDistancia();

  Serial.println(distance);

  delay(200);

}

float lerDistancia(){
  
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);
    
  float distance = pulseIn(ECHOPIN, HIGH);
  distance = distance/58;
  
  return   distance;
}

