/*
 * Distance ultrasonic sensor
 * values is used to turn on/off five leds
 * depending the value of distance
 * 
 */


#define ECHOPIN 6        // Pin to receive echo pulse
#define TRIGPIN 8        // Pin to send trigger pulse
#define LEDPIN 13
#define LEDPIN2 12
#define LEDPIN3 11
#define LEDPIN4 10
#define LEDPIN5 9

 
void setup()
{

  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  pinMode(LEDPIN, OUTPUT);
  pinMode(LEDPIN2, OUTPUT);
  pinMode(LEDPIN3, OUTPUT);
  pinMode(LEDPIN4, OUTPUT);
  pinMode(LEDPIN5, OUTPUT);  
  
}

/*
 * loop function.
 * 
 */
void loop()
{
  int distance = lerDistancia();
  
  acendeLeds(distance);
    
  delay(100);

}

void acendeLeds(int distancia){
  
  if(distancia == 0 || distancia == 1){
      digitalWrite(LEDPIN, HIGH);
      digitalWrite(LEDPIN2, HIGH);
      digitalWrite(LEDPIN3, HIGH);
      digitalWrite(LEDPIN4, HIGH);
      digitalWrite(LEDPIN5, HIGH);
  }else if (distancia == 2){
      digitalWrite(LEDPIN, HIGH);
      digitalWrite(LEDPIN2, HIGH);
      digitalWrite(LEDPIN3, HIGH);
      digitalWrite(LEDPIN4, HIGH);
      digitalWrite(LEDPIN5, LOW);
  }else if (distancia == 3){
      digitalWrite(LEDPIN, HIGH);
      digitalWrite(LEDPIN2, HIGH);
      digitalWrite(LEDPIN3, HIGH);
      digitalWrite(LEDPIN4, LOW);
      digitalWrite(LEDPIN5, LOW);
  }else if (distancia == 4){
      digitalWrite(LEDPIN, HIGH);
      digitalWrite(LEDPIN2, HIGH);
      digitalWrite(LEDPIN3, LOW);
      digitalWrite(LEDPIN4, LOW);
      digitalWrite(LEDPIN5, LOW);
  }else if (distancia == 5){
      digitalWrite(LEDPIN, HIGH);
      digitalWrite(LEDPIN2, LOW);
      digitalWrite(LEDPIN3, LOW);
      digitalWrite(LEDPIN4, LOW);
      digitalWrite(LEDPIN5, LOW);
  }else{
      digitalWrite(LEDPIN, LOW);
      digitalWrite(LEDPIN2, LOW);
      digitalWrite(LEDPIN3, LOW);
      digitalWrite(LEDPIN4, LOW);
      digitalWrite(LEDPIN5, LOW);
  }
}

int lerDistancia(){
  
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);
    
  float distance = pulseIn(ECHOPIN, HIGH);
  distance = (distance/58)/5;
  
  return distance;
}




