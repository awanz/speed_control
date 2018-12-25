/*    MOTOR CONTROL MODULLE     */
/*    ALL ANALOG CONTROL        */

#define LPLUS 5     //M1 Speed Control
#define LMINUS 4    //M1 Direction Control
#define RPLUS 6     //M2 Speed Control
#define RMINUS 7   //M2 Direction Control

int E1 = 5;     //M1 Speed Control
int E2 = 6;     //M2 Speed Control
int M1 = 4;     //M1 Direction Control
int M2 = 7;     //M1 Direction Control

#define LEN 6
#define REN 11


void motorEn(int pl){
  analogWrite(LEN, pl);
  analogWrite(REN, pl);
}

void initMotors(){
  pinMode(LPLUS, OUTPUT); 
  pinMode(RPLUS, OUTPUT); 
  pinMode(LMINUS, OUTPUT); 
  pinMode(RMINUS, OUTPUT); 
  pinMode(LEN, OUTPUT); 
  pinMode(LEN, OUTPUT);
  Serial.println("Inisialisasi Motor");
}

void halt(){
  motorEn(255);
  digitalWrite(E1,0); 
  digitalWrite(M1,LOW);    
  digitalWrite(E2,0);   
  digitalWrite(M2,LOW); 
}

void backward(int powerLevel){
  motorEn(powerLevel);
  analogWrite (E1,powerLevel);      //PWM Speed Control
  digitalWrite(M1,HIGH);    
  analogWrite (E2,powerLevel);    
  digitalWrite(M2,HIGH);
}

void forward(int powerLevel){
  motorEn(powerLevel);
  analogWrite (E1,powerLevel);
  digitalWrite(M1,LOW);   
  analogWrite (E2,powerLevel);    
  digitalWrite(M2,LOW);
}


// turn left indefinitely 
void turnL(int powerLevel){
  motorEn(powerLevel);
  analogWrite (E1,powerLevel);
  digitalWrite(M1,HIGH);    
  analogWrite (E2,powerLevel);    
  digitalWrite(M2,LOW); 
}

// turn right indefinitely 
void turnR(int powerLevel){
  motorEn(powerLevel);
  analogWrite (E1,powerLevel);
  digitalWrite(M1,LOW);    
  analogWrite (E2,powerLevel);    
  digitalWrite(M2,HIGH);
}
