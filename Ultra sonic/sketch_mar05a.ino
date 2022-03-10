int trig = 3 ;
int echo = 2 ; 
double duration ; 
int distance ; 

void setup() {
pinMode(echo,INPUT) ; 
pinMode(trig,OUTPUT) ; 
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
