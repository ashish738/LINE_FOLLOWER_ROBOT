//INFRARED SENSOR CONNECTION
#define LS 9      // left sensor
#define RS 10      // right sensor

//L298 MOTOR DRIVER CONNECTIONS
#define LM1 8       // left motor forward
#define LM2 7      // left motor  reverse
#define RM1 4     // right motor forward
#define RM2 3    // right motor reverse
#define ENA 5      // ena pin
#define ENB 6       // enb pin
#define BUZ 13      // BUZZER 

//HC-SR04 ULTRASONIC Sensor connection
  const int trigPin = 11;               // TRIGGER pin 
  const int echoPin = 12;               // ECHO pin

  int stop_distance = 15;               // Distance at which the object can be detected

  long duration;
  int distance;

  
void setup()                              // DEFINING THE INPUT AND OUTPUT PINS
{
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT); 
  pinMode(BUZ, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}


void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);                 //GENRATING FREQUENCY FOR THE ULTRASONIC SENSOR
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;                 // CALCULATING THE DISTANCE    

  
  if(!(digitalRead(LS)) && !(digitalRead(RS)))     //TO Move Forward
  {
    delay(30);
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    analogWrite(ENA, 170);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    analogWrite(ENB, 170);
    digitalWrite(BUZ, LOW);
  }
  
  if(digitalRead(LS) && (!(digitalRead(RS))))     // TO Turn LEFT
  {
    delay(30);
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    analogWrite(ENA, 170);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
    analogWrite(ENB, 0);
    digitalWrite(BUZ, LOW);
  }
  
  if(!(digitalRead(LS)) && digitalRead(RS))     //TO Turn RIGHT
  {

    delay(30);
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    analogWrite(ENA, 0);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    analogWrite(ENB, 170);    

    digitalWrite(BUZ, LOW);
  }
  
  if(digitalRead(LS) && digitalRead(RS))     //TO Stop
  {
    delay(30);
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    analogWrite(ENA, 0);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
    analogWrite(ENB, 0);
    digitalWrite(BUZ, HIGH);
  }



 if(distance < stop_distance)             //TO Check the distance between object and car and, stop the car
 {

    
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    analogWrite(ENA, 0);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
    analogWrite(ENB, 0);
    digitalWrite(BUZ, HIGH);


 }
 

}
