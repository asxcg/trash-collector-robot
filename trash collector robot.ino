#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3);
//const int buzz = 12;
char receivedChar;
#include<Servo.h> 
Servo servo; //create a servo object
Servo servo1; 
Servo servo2; 
Servo servo3; 
int pos = 0;  //initial position of the servo

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
mySerial.begin(9600);
servo.attach(12);  //pin used by the servo
servo1.attach(11);
servo2.attach(10);
servo3.attach(9);


pinMode(A0,OUTPUT);
pinMode(A1,OUTPUT);
pinMode(A2,OUTPUT);
pinMode(A3,OUTPUT);
//pinMode(buzz,OUTPUT);
//pinMode(6,OUTPUT);
pinMode(4,INPUT);
   servo3.write(0);  
  servo2.write(0);  
  servo.write(90);
  servo1.write(0);
  delay(1000); 
}

void loop() {
  
m1();
}

void m1()
{


 
 if (mySerial.available()) {
    receivedChar =(char)mySerial.read();
    //Serial.print ("Received:");//print on serial monitor
    //Serial.println(receivedChar);//print on serial monitor    
    
    if(receivedChar == 'F')
    {
      Serial.println("forward");
      m_forward();
       
    }
    if(receivedChar == 'B')
    {
      Serial.println("backward");
      m_backward(); 
    }         
     if(receivedChar == 'L')
    {
     Serial.println("left");
      m_left();
    }        
    if(receivedChar == 'R')
    {
     Serial.println("right");
      m_right(); 
    }

    if(receivedChar == '1')
    {
     Serial.println("main servo up");
      mservo_up(); 
    }
    
     if(receivedChar == '2')
    {
     Serial.println("main servo down");
      mservo_down(); 
    }
    if(receivedChar == '3')
    {
     Serial.println("servo close");
      mservo_open(); 
    }
    
     if(receivedChar == '4')
    {
     Serial.println("servo open");
      mservo_close(); 
    }

    if(receivedChar == 'H')
    {
     Serial.println("pump on");
     digitalWrite(6,HIGH); 
    }

    if(receivedChar == 'h')
    {
     Serial.println("pump off");
     digitalWrite(6,LOW); 
    }
    
    if(receivedChar == 'S')
    { 
      Serial.println("stop");
      m_stop();
    }
  } 
 
 }
 

void  m_backward()
{
 digitalWrite(A0,HIGH);
 digitalWrite(A1,LOW);
 digitalWrite(A2,LOW);
 digitalWrite(A3,HIGH); 
}

void m_forward()
{
 digitalWrite(A0,LOW);
 digitalWrite(A1,HIGH);
 digitalWrite(A2,HIGH);
 digitalWrite(A3,LOW); 
}

void m_right()
{
 digitalWrite(A0,LOW);
 digitalWrite(A1,HIGH);
 digitalWrite(A2,LOW);
 digitalWrite(A3,HIGH); 
  
}

void m_left()
{
   digitalWrite(A0,HIGH);
 digitalWrite(A1,LOW);
 digitalWrite(A2,HIGH);
 digitalWrite(A3,LOW); 
}

void  m_stop()
{
 digitalWrite(A0,LOW);
 digitalWrite(A1,LOW);
 digitalWrite(A2,LOW);
 digitalWrite(A3,LOW); 
 //digitalWrite(7,LOW); 
}

void mservo_up()
{
    
    servo.write(0);
    
     servo1.write(90);
    delay(15);
    
}

void mservo_down()
{
 
    servo.write(90);
     servo1.write(0); 
     delay(15); 
}

void mservo_open(){
    servo2.write(90);
    delay(2000);
     metal();
    servo2.write(0);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }


void mservo_close(){

    servo2.write(120);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }                      // waits 15ms for the servo to reach the position
  
void metal(){
  int m = digitalRead(4);
  if(m == HIGH){
   servo3.write(0); 
  }
  else
  {
   servo3.write(180); 
  }
  delay(2000);
}
