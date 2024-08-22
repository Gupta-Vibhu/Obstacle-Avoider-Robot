#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
int lar,i;
int pos = 0;    // variable to store the servo position
int trig=13;
int echo=12;
long duration , cm, inches , y[181];

long func()
{
  digitalWrite(trig,LOW);
  delayMicroseconds(5);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  duration = pulseIn(echo,HIGH);
  return cm = (duration/2)/29.1;
}

void setup()
{
  myservo.attach(7);  		// attaches the servo on pin 7 to the servo object 
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(8, OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11,OUTPUT);

}

void loop()
{
  long x=func();

// Send ping, get distance in cm 

if(x > 10)  
  {
    digitalWrite(9, HIGH);
    digitalWrite(8,LOW);
    digitalWrite(11, HIGH);
    digitalWrite(10,LOW);
  }   			
  else              	
  {
    digitalWrite(8, LOW);
    digitalWrite(9,LOW);
    digitalWrite(10, LOW);
    digitalWrite(11,LOW);

for(pos = 0; pos <= 180; pos += 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos); 
    y[pos] = func();
    Serial.print(y[pos]);
    
    // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 

  pos = 90;
  myservo.write(pos);
  lar=y[0];

  for(pos=1;pos<=180;pos++)
  {
    if(lar<y[pos])
    {
     lar=y[pos];
     i = pos;
    }
  }

   if (lar>10 && i!=90)
   {
    if (i<90)
    {
     while(func()<lar) 
      {
      digitalWrite(11, HIGH);
      digitalWrite(10,LOW);
      digitalWrite(9, LOW);
      digitalWrite(8,HIGH);
      }
       digitalWrite(9, HIGH);
       digitalWrite(8,LOW);
       digitalWrite(11, HIGH);
       digitalWrite(10,LOW);
     }
    
    else
    {
      while(func()<lar)
      {
      digitalWrite(9, HIGH);
      digitalWrite(8,LOW);}
      digitalWrite(10, HIGH);
      digitalWrite(11,LOW);
      }
   digitalWrite(9, HIGH);
   digitalWrite(8,LOW);
   digitalWrite(11, HIGH);
   digitalWrite(10,LOW);
      }
    else
    {
    digitalWrite(8, HIGH);
    digitalWrite(9,LOW);
    digitalWrite(10, HIGH);
    digitalWrite(11,LOW);
                          }
}
  }