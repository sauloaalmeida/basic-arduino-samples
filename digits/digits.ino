//4 Led Digits display with decimal point


#define SEG_A 11
#define SEG_B 7
#define SEG_C 4
#define SEG_D 2
#define SEG_E 1
#define SEG_F 10
#define SEG_G 5
#define SEG_DP 3

#define DIGITO_1 6
#define DIGITO_2 8
#define DIGITO_3 9
#define DIGITO_4 12
#define TODOS_DIGITOS 0

int TEMPO_APAGADO = 1;
int TEMPO_ACESO = TEMPO_APAGADO*2;


void setup() { 
 
  // initialize the digital pin as an output.
  pinMode(SEG_A, OUTPUT);     
  pinMode(SEG_B, OUTPUT);       
  pinMode(SEG_C, OUTPUT);     
  pinMode(SEG_D, OUTPUT);     
  pinMode(SEG_E, OUTPUT);     
  pinMode(SEG_F, OUTPUT);       
  pinMode(SEG_G, OUTPUT);     
  pinMode(SEG_DP, OUTPUT);       
  pinMode(DIGITO_1, OUTPUT);    
  pinMode(DIGITO_2, OUTPUT);    
  pinMode(DIGITO_3, OUTPUT);    
  pinMode(DIGITO_4, OUTPUT);      
}

void loop() {
  //all(DIGITO_1);
  
//  zero(DIGITO_1);
//  um(DIGITO_2);  
//  dois(DIGITO_3);
//  tres(DIGITO_4);  

  quatro(DIGITO_1);
  cinco(DIGITO_2);  
  seis(DIGITO_3);
  sete(DIGITO_4);    
  decimal(DIGITO_3); 
//  oito(DIGITO_1);
//  nove(DIGITO_2);  
 

}

void acende_digito(int digito){
  if (digito == DIGITO_1) {
      digitalWrite(DIGITO_1, LOW);
      digitalWrite(DIGITO_2, HIGH);
      digitalWrite(DIGITO_3, HIGH);      
      digitalWrite(DIGITO_4, HIGH);            
  }    
  else if  (digito == DIGITO_2){
      digitalWrite(DIGITO_2, LOW);
      digitalWrite(DIGITO_1, HIGH);
      digitalWrite(DIGITO_3, HIGH);      
      digitalWrite(DIGITO_4, HIGH);      
  }
  else if  (digito == DIGITO_3){
      digitalWrite(DIGITO_3, LOW);
      digitalWrite(DIGITO_1, HIGH);
      digitalWrite(DIGITO_2, HIGH);      
      digitalWrite(DIGITO_4, HIGH);      
  }  
  else if  (digito == DIGITO_4){
      digitalWrite(DIGITO_4, LOW);
      digitalWrite(DIGITO_1, HIGH);
      digitalWrite(DIGITO_2, HIGH);      
      digitalWrite(DIGITO_3, HIGH);      
  }
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
  delay(temp_aceso);              // wait for a second aceso

  digitalWrite(SEG_A, LOW);    // set the LED off
  digitalWrite(SEG_B, LOW);   // set the LED off
  digitalWrite(SEG_C, LOW);   // set the LED off
  digitalWrite(SEG_D, LOW);   // set the LED off
  digitalWrite(SEG_E, LOW);   // set the LED off
  digitalWrite(SEG_F, LOW);
  digitalWrite(SEG_G, LOW);
  digitalWrite(SEG_DP, LOW);    
  delay(temp_apagado);              // wait for a second apagado
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
  delay(temp_aceso);              // wait for a second

  digitalWrite(SEG_A, LOW);    // set the LED off
  digitalWrite(SEG_B, LOW);   // set the LED off
  digitalWrite(SEG_C, LOW);   // set the LED off
  digitalWrite(SEG_D, LOW);   // set the LED off
  digitalWrite(SEG_E, LOW);   // set the LED off
  digitalWrite(SEG_F, LOW);
  digitalWrite(SEG_G, LOW);
  delay(temp_apagado);              // wait for a second
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
  delay(temp_aceso);              // wait for a second

  digitalWrite(SEG_B, LOW);   // set the LED off
  digitalWrite(SEG_C, LOW);   // set the LED off
  delay(temp_apagado);              // wait for a second
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
  delay(temp_aceso);              // wait for a second

  digitalWrite(SEG_A, LOW);   // set the LED off  
  digitalWrite(SEG_B, LOW);   // set the LED off
  digitalWrite(SEG_G, LOW);   // set the LED off
  digitalWrite(SEG_E, LOW);   // set the LED off
  digitalWrite(SEG_D, LOW);   // set the LED off  
  delay(temp_apagado);              // wait for a second
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
  delay(temp_aceso);              // wait for a second aceso

  digitalWrite(SEG_A, LOW);    // set the LED off
  digitalWrite(SEG_B, LOW);   // set the LED off
  digitalWrite(SEG_C, LOW);   // set the LED off
  digitalWrite(SEG_D, LOW);   // set the LED off
  digitalWrite(SEG_G, LOW);
  delay(temp_apagado);              // wait for a second apagado
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
  delay(temp_aceso);              // wait for a second aceso

  digitalWrite(SEG_B, LOW);   // set the LED off
  digitalWrite(SEG_C, LOW);   // set the LED off
  digitalWrite(SEG_F, LOW);
  digitalWrite(SEG_G, LOW);
  delay(temp_apagado);              // wait for a second apagado
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
  delay(temp_aceso);              // wait for a second aceso

  digitalWrite(SEG_A, LOW);    // set the LED off
  digitalWrite(SEG_C, LOW);   // set the LED off
  digitalWrite(SEG_D, LOW);   // set the LED off
  digitalWrite(SEG_F, LOW);
  digitalWrite(SEG_G, LOW);
  delay(temp_apagado);              // wait for a second apagado
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
  delay(temp_aceso);              // wait for a second aceso

  digitalWrite(SEG_C, LOW);   // set the LED off
  digitalWrite(SEG_D, LOW);   // set the LED off
  digitalWrite(SEG_E, LOW);   // set the LED off
  digitalWrite(SEG_F, LOW);
  digitalWrite(SEG_G, LOW);
  delay(temp_apagado);              // wait for a second apagado
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
  delay(temp_aceso);              // wait for a second aceso

  digitalWrite(SEG_A, LOW);    // set the LED off
  digitalWrite(SEG_B, LOW);   // set the LED off
  digitalWrite(SEG_C, LOW);   // set the LED off
  delay(temp_apagado);              // wait for a second apagado
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
  delay(temp_aceso);              // wait for a second aceso

  digitalWrite(SEG_A, LOW);    // set the LED off
  digitalWrite(SEG_B, LOW);   // set the LED off
  digitalWrite(SEG_C, LOW);   // set the LED off
  digitalWrite(SEG_D, LOW);   // set the LED off
  digitalWrite(SEG_E, LOW);   // set the LED off
  digitalWrite(SEG_F, LOW);
  digitalWrite(SEG_G, LOW);
  delay(temp_apagado);              // wait for a second apagado
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
  delay(temp_aceso);              // wait for a second aceso

  digitalWrite(SEG_A, LOW);    // set the LED off
  digitalWrite(SEG_B, LOW);   // set the LED off
  digitalWrite(SEG_C, LOW);   // set the LED off
  digitalWrite(SEG_F, LOW);
  digitalWrite(SEG_G, LOW);
  delay(temp_apagado);              // wait for a second apagado
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
  delay(temp_aceso);              // wait for a second aceso


  digitalWrite(SEG_DP, LOW);    
  delay(temp_apagado);              // wait for a second apagado
}
