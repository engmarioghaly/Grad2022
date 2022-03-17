int trig = 3 ;
int echo = 2 ;
int relay1=3 ; 
int relay2=4 ;  
int ir1=5 ; 
int ir2=6 ;
int ir3 =7; 
int ir4 =8; 
float temp;
double duration ; 
int distance ; 

void setup() {
pinMode(echo,INPUT) ; 
pinMode(trig,OUTPUT) ; 
pinMode(relay1,OUTPUT) ; 
pinMode(relay2,OUTPUT) ;
pinMode(A0,INPUT) ; 
pinMode(ir1,INPUT) ;
pinMode(ir2,INPUT) ;
pinMode(ir3,INPUT) ; 
pinMode(ir4,INPUT) ;
Serial.begin (9600) ; 
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = duration * 0.034 / 2;
  Serial.println(distance);
  delay (200) ; 
  if (distance < 50 && distance > 10 ) 
  {
    Serial.println(1) ; 
    delay(400) ; 
  }
}

 
  
}
