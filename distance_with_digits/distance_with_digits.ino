/*
 * Distance ultrasonic sensor
 * values in meter
 * only prints in serial monitor
 * printed in a 4 led digits display
 * PS.: prints only 2 digits - m.d (meter . decimeter)
 * 
 */


#define ECHOPIN 6        // Pin to receive echo pulse
#define TRIGPIN 8        // Pin to send trigger pulse

#define SEG_A 11
#define SEG_B 7
#define SEG_C 4
#define SEG_D 2
#define SEG_E 1
#define SEG_F 10
#define SEG_G 5
#define SEG_DP 3

#define DIGITO_3 9
#define DIGITO_4 12
#define TODOS_DIGITOS 0

int TEMPO_APAGADO = 1;
int TEMPO_ACESO = 30000;

/*
 * setup function
 * Initialize the serial line (D0 & D1) at 115200.
 * Then set the pin defined to receive echo in INPUT 
 * and the pin to trigger to OUTPUT.
 */
 
void setup()
{
  //Serial.begin(115200);
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  
// initialize the digital pin as an output.
  pinMode(SEG_A, OUTPUT);     
  pinMode(SEG_B, OUTPUT);       
  pinMode(SEG_C, OUTPUT);     
  pinMode(SEG_D, OUTPUT);     
  pinMode(SEG_E, OUTPUT);     
  pinMode(SEG_F, OUTPUT);       
  pinMode(SEG_G, OUTPUT);     
  pinMode(SEG_DP, OUTPUT);       
  pinMode(DIGITO_3, OUTPUT);    
  pinMode(DIGITO_4, OUTPUT);       
  
}

/*
 * loop function.
 * 
 */
void loop()
{
  float distance = lerDistancia();
  
  //Serial.println(distance);
  //Serial.print(parteInteira(distance));
  decimal(DIGITO_4); 
  displayDigito(parteInteira(distance),DIGITO_4);
  displayDigito(parteDecimal(distance),DIGITO_3);
 // delayMicroseconds(2);

}

float lerDistancia(){
  
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);
    
  float distance = pulseIn(ECHOPIN, HIGH);
  distance = distance/58;
  
  return distance;
}


void displayDigito(int value, int digito){

  switch(value){
  case 1:
    um(digito);
    break;
  case 2:
    dois(digito);
    break;    
  case 3:
    tres(digito);
    break;    
  case 4:
    quatro(digito);
    break;    
  case 5:
    cinco(digito);
    break;    
  case 6:
    seis(digito);
    break;    
  case 7:
    sete(digito);
    break;    
  case 8:
    oito(digito);
    break;    
  case 9:
    nove(digito);
    break;    
  case 0:
    zero(digito);
    break;        
  }
  
}


void acende_digito(int digito){
 if  (digito == DIGITO_3){
      digitalWrite(DIGITO_3, LOW);
      digitalWrite(DIGITO_4, HIGH);      
  }  
  else if  (digito == DIGITO_4){
      digitalWrite(DIGITO_4, LOW);
      digitalWrite(DIGITO_3, HIGH);      
  }
}


int parteDecimal(float value){

  int newValue = value*100;
  
  if(value>=1000){
    return 9;
  }else if (value >= 100 && value <= 999){
    return (newValue/1000)%10;
  }
    return newValue/1000;    
}

int parteInteira(float value){

  if(value >=1000){
    return 9;
  }
  
  if(value >= 100 && value < 1000){
    return value/100;
  }
   
  //se for menor que 100 retorna 0
  return 0;
  
}

void all(){
  all (TODOS_DIGITOS);
}

void all(int digito){
  all (TEMPO_ACESO,TEMPO_APAGADO,digito);
}

void all(int temp_aceso, int temp_apagado,int digito){

  acende_digito(digito);
  digitalWrite(SEG_A, HIGH);   // set the LED on
  digitalWrite(SEG_B, HIGH);   // set the LED on
  digitalWrite(SEG_C, HIGH); 
  digitalWrite(SEG_D, HIGH); 
  digitalWrite(SEG_E, HIGH);
  digitalWrite(SEG_F, HIGH);
  digitalWrite(SEG_G, HIGH);
  digitalWrite(SEG_DP, HIGH); 
  delayMicroseconds(temp_aceso);              // wait for a second aceso

  digitalWrite(SEG_A, LOW);    // set the LED off
  digitalWrite(SEG_B, LOW);   // set the LED off
  digitalWrite(SEG_C, LOW);   // set the LED off
  digitalWrite(SEG_D, LOW);   // set the LED off
  digitalWrite(SEG_E, LOW);   // set the LED off
  digitalWrite(SEG_F, LOW);
  digitalWrite(SEG_G, LOW);
  digitalWrite(SEG_DP, LOW);    
  delayMicroseconds(temp_apagado);              // wait for a second apagado
}

void zero(){
  zero (TODOS_DIGITOS);
}

void zero(int digito){
  zero (TEMPO_ACESO,TEMPO_APAGADO,digito);
}

void zero(int temp_aceso, int temp_apagado,int digito){

  acende_digito(digito);
  digitalWrite(SEG_A, HIGH);   // set the LED on
  digitalWrite(SEG_B, HIGH);   // set the LED on
  digitalWrite(SEG_C, HIGH); 
  digitalWrite(SEG_D, HIGH); 
  digitalWrite(SEG_E, HIGH);
  digitalWrite(SEG_F, HIGH);
  delayMicroseconds(temp_aceso);              // wait for a second

  digitalWrite(SEG_A, LOW);    // set the LED off
  digitalWrite(SEG_B, LOW);   // set the LED off
  digitalWrite(SEG_C, LOW);   // set the LED off
  digitalWrite(SEG_D, LOW);   // set the LED off
  digitalWrite(SEG_E, LOW);   // set the LED off
  digitalWrite(SEG_F, LOW);
  digitalWrite(SEG_G, LOW);
  delayMicroseconds(temp_apagado);              // wait for a second
}


void um(){
  um(TODOS_DIGITOS);
}

void um(int digito){
  um (TEMPO_ACESO,TEMPO_APAGADO,digito);
}

void um(int temp_aceso, int temp_apagado,int digito){

  acende_digito(digito);
  digitalWrite(SEG_B, HIGH);   // set the LED on
  digitalWrite(SEG_C, HIGH); 
  delayMicroseconds(temp_aceso);              // wait for a second

  digitalWrite(SEG_B, LOW);   // set the LED off
  digitalWrite(SEG_C, LOW);   // set the LED off
  delayMicroseconds(temp_apagado);              // wait for a second
}

void dois(){
  dois(TODOS_DIGITOS);
}

void dois(int digito){
  dois (TEMPO_ACESO,TEMPO_APAGADO,digito);
}

void dois(int temp_aceso, int temp_apagado,int digito){

  acende_digito(digito);
  digitalWrite(SEG_A, HIGH);   // set the LED on
  digitalWrite(SEG_B, HIGH);   // set the LED on
  digitalWrite(SEG_G, HIGH); 
  digitalWrite(SEG_E, HIGH);   // set the LED on
  digitalWrite(SEG_D, HIGH);   
  delayMicroseconds(temp_aceso);              // wait for a second

  digitalWrite(SEG_A, LOW);   // set the LED off  
  digitalWrite(SEG_B, LOW);   // set the LED off
  digitalWrite(SEG_G, LOW);   // set the LED off
  digitalWrite(SEG_E, LOW);   // set the LED off
  digitalWrite(SEG_D, LOW);   // set the LED off  
  delayMicroseconds(temp_apagado);              // wait for a second
}

void tres(){
  tres (TODOS_DIGITOS);
}

void tres(int digito){
  tres (TEMPO_ACESO,TEMPO_APAGADO,digito);
}

void tres(int temp_aceso, int temp_apagado,int digito){

  acende_digito(digito);
  digitalWrite(SEG_A, HIGH);   // set the LED on
  digitalWrite(SEG_B, HIGH);   // set the LED on
  digitalWrite(SEG_C, HIGH); 
  digitalWrite(SEG_D, HIGH); 
  digitalWrite(SEG_G, HIGH);
  delayMicroseconds(temp_aceso);              // wait for a second aceso

  digitalWrite(SEG_A, LOW);    // set the LED off
  digitalWrite(SEG_B, LOW);   // set the LED off
  digitalWrite(SEG_C, LOW);   // set the LED off
  digitalWrite(SEG_D, LOW);   // set the LED off
  digitalWrite(SEG_G, LOW);
  delayMicroseconds(temp_apagado);              // wait for a second apagado
}

void quatro(){
  quatro (TODOS_DIGITOS);
}

void quatro(int digito){
  quatro (TEMPO_ACESO,TEMPO_APAGADO,digito);
}

void quatro(int temp_aceso, int temp_apagado,int digito){

  acende_digito(digito);
  digitalWrite(SEG_B, HIGH);   // set the LED on
  digitalWrite(SEG_C, HIGH); 
  digitalWrite(SEG_F, HIGH);
  digitalWrite(SEG_G, HIGH);
  delayMicroseconds(temp_aceso);              // wait for a second aceso

  digitalWrite(SEG_B, LOW);   // set the LED off
  digitalWrite(SEG_C, LOW);   // set the LED off
  digitalWrite(SEG_F, LOW);
  digitalWrite(SEG_G, LOW);
  delayMicroseconds(temp_apagado);              // wait for a second apagado
}

void cinco(){
  cinco (TODOS_DIGITOS);
}

void cinco(int digito){
  cinco (TEMPO_ACESO,TEMPO_APAGADO,digito);
}

void cinco(int temp_aceso, int temp_apagado,int digito){

  acende_digito(digito);
  digitalWrite(SEG_A, HIGH);   // set the LED on
  digitalWrite(SEG_C, HIGH); 
  digitalWrite(SEG_D, HIGH); 
  digitalWrite(SEG_F, HIGH);
  digitalWrite(SEG_G, HIGH);
  delayMicroseconds(temp_aceso);              // wait for a second aceso

  digitalWrite(SEG_A, LOW);    // set the LED off
  digitalWrite(SEG_C, LOW);   // set the LED off
  digitalWrite(SEG_D, LOW);   // set the LED off
  digitalWrite(SEG_F, LOW);
  digitalWrite(SEG_G, LOW);
  delayMicroseconds(temp_apagado);              // wait for a second apagado
}

void seis(){
  seis (TODOS_DIGITOS);
}

void seis(int digito){
  seis (TEMPO_ACESO,TEMPO_APAGADO,digito);
}

void seis(int temp_aceso, int temp_apagado,int digito){

  acende_digito(digito);
  digitalWrite(SEG_C, HIGH); 
  digitalWrite(SEG_D, HIGH); 
  digitalWrite(SEG_E, HIGH);
  digitalWrite(SEG_F, HIGH);
  digitalWrite(SEG_G, HIGH);
  delayMicroseconds(temp_aceso);              // wait for a second aceso

  digitalWrite(SEG_C, LOW);   // set the LED off
  digitalWrite(SEG_D, LOW);   // set the LED off
  digitalWrite(SEG_E, LOW);   // set the LED off
  digitalWrite(SEG_F, LOW);
  digitalWrite(SEG_G, LOW);
  delayMicroseconds(temp_apagado);              // wait for a second apagado
}

void sete(){
  sete (TODOS_DIGITOS);
}

void sete(int digito){
  sete (TEMPO_ACESO,TEMPO_APAGADO,digito);
}

void sete(int temp_aceso, int temp_apagado,int digito){

  acende_digito(digito);
  digitalWrite(SEG_A, HIGH);   // set the LED on
  digitalWrite(SEG_B, HIGH);   // set the LED on
  digitalWrite(SEG_C, HIGH); 
  delayMicroseconds(temp_aceso);              // wait for a second aceso

  digitalWrite(SEG_A, LOW);    // set the LED off
  digitalWrite(SEG_B, LOW);   // set the LED off
  digitalWrite(SEG_C, LOW);   // set the LED off
  delayMicroseconds(temp_apagado);              // wait for a second apagado
}

void oito(){
  oito (TODOS_DIGITOS);
}

void oito(int digito){
  oito (TEMPO_ACESO,TEMPO_APAGADO,digito);
}

void oito(int temp_aceso, int temp_apagado,int digito){

  acende_digito(digito);
  digitalWrite(SEG_A, HIGH);   // set the LED on
  digitalWrite(SEG_B, HIGH);   // set the LED on
  digitalWrite(SEG_C, HIGH); 
  digitalWrite(SEG_D, HIGH); 
  digitalWrite(SEG_E, HIGH);
  digitalWrite(SEG_F, HIGH);
  digitalWrite(SEG_G, HIGH);
  delayMicroseconds(temp_aceso);              // wait for a second aceso

  digitalWrite(SEG_A, LOW);    // set the LED off
  digitalWrite(SEG_B, LOW);   // set the LED off
  digitalWrite(SEG_C, LOW);   // set the LED off
  digitalWrite(SEG_D, LOW);   // set the LED off
  digitalWrite(SEG_E, LOW);   // set the LED off
  digitalWrite(SEG_F, LOW);
  digitalWrite(SEG_G, LOW);
  delayMicroseconds(temp_apagado);              // wait for a second apagado
}

void nove(){
  nove (TODOS_DIGITOS);
}

void nove(int digito){
  nove (TEMPO_ACESO,TEMPO_APAGADO,digito);
}

void nove(int temp_aceso, int temp_apagado,int digito){

  acende_digito(digito);
  digitalWrite(SEG_A, HIGH);   // set the LED on
  digitalWrite(SEG_B, HIGH);   // set the LED on
  digitalWrite(SEG_C, HIGH); 
  digitalWrite(SEG_F, HIGH);
  digitalWrite(SEG_G, HIGH);
  delayMicroseconds(temp_aceso);              // wait for a second aceso

  digitalWrite(SEG_A, LOW);    // set the LED off
  digitalWrite(SEG_B, LOW);   // set the LED off
  digitalWrite(SEG_C, LOW);   // set the LED off
  digitalWrite(SEG_F, LOW);
  digitalWrite(SEG_G, LOW);
  delayMicroseconds(temp_apagado);              // wait for a second apagado
}

void decimal(){
  decimal (TODOS_DIGITOS);
}

void decimal(int digito){
  decimal (TEMPO_ACESO,TEMPO_APAGADO,digito);
}

void decimal(int temp_aceso, int temp_apagado,int digito){

  acende_digito(digito);
  digitalWrite(SEG_DP, HIGH); 
  delayMicroseconds(temp_aceso);              // wait for a second aceso


  digitalWrite(SEG_DP, LOW);    
  delayMicroseconds(temp_apagado);              // wait for a second apagado
}

