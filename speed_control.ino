#include <math.h>  // for the absolute value function
#include <Servo.h>                                //Include Servo library
Servo irservo;                                    // create servo object to control a servo 

#define Svo_Pin 9
const int BOUNDARY = 300;
const int TURN_POWER = 80;
const int FORWARD_DELAY = 1000;

const int random_forward_degree = 10;
const int delay_per_degree = 20;

const int random_turn_base = 120;
const int random_turn_ceiling = 240;
int x = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Start Robot Kelompok 2");
  initMotors();
  irservo.attach(Svo_Pin);
  irservo.write(70);
}

void loop() {
  int a = distanceReading();
  Serial.print("Jarak: ");
  Serial.println(a);
  int bb = speedControl(a);
  Serial.print("Kecepatan: ");
  Serial.println(bb);
  Serial.println("======");
  forward(bb);
  if(a <= 10){
    randomTurn();
  }
}

int speedControl(int a){
  int b;
  if (a < 130){
    return 255;
  }
  if (a > 600){
    return 0;
  }
  if (a >= 130 && a <= 600){
    b = map(a, 600, 130, 0, 255);
    return b;
  }
}

/* randomTurn(): randomly choose an angle to turn
*
*/

void randomTurn(){
  // turn left or right random number
  long randNumber1 = random(1,10);
  // turning degree random number
  long randNumber2 = random(random_turn_base,random_turn_ceiling);
  int turn_time  = (int) randNumber2 * delay_per_degree;

  // turn right
  if (randNumber1 >= 5){
    
    turnR(TURN_POWER);
    delay(500);
    //halt();
  }
  // turn left
  else{
    turnL(TURN_POWER);
    delay(500);
    //halt();
  }
}

/* randomForward(): randomly choose an angle and move forward
*
*/

void randomForward(){
  long rand_turn = random(random_forward_degree);
  long rand_dir = random(1,10);

  if (rand_dir > 5){

    turnR(TURN_POWER);
    delay(rand_turn * delay_per_degree);

  } else {
    turnL(TURN_POWER);
    delay(rand_turn * delay_per_degree);

  }
  forward(TURN_POWER);
  delay(FORWARD_DELAY);
  
}
