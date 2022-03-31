//library used 
#include <SPI.h>
#include <MFRC522.h>

//variables 
int trig = 2 ;
int echo = 3 ; 
int relay1=4 ; 
int relay2=5 ; 
int pro1 = 6 ; 
int pro2 = 7 ; 
int ss = 10 ;
int rst = 9 ;
double duration ; 
int distance ; 
int pro1read ;
int pro2read ; 
//rfid init
MFRC522 rfid(ss, rst);
MFRC522::MIFARE_Key key; 
int cardnum[4];


void setup() {
  pinMode (trig , OUTPUT) ; 
  pinMode (relay1 , OUTPUT) ; 
  pinMode (relay2 , OUTPUT) ;
  pinMode (echo , INPUT) ; 
  pinMode (pro1 , INPUT) ;  
  pinMode (pro2 , INPUT) ;  
  Serial.begin(9600); //serial init 
  SPI.begin(); //spi init 
  rfid.PCD_Init(); 
  for (byte i = 0; i < 6; i++)
  {
    key.keyByte[i] = 0xFF;
  }
}



void loop() {
// ultrasonic 
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = duration * 0.034 / 2;

  if (distance >= 20 && distance <= 100)
  {
    Serial.println (1) ; 

  }

  else
  {
     Serial.println (distance);
  }


  
   // proxmiter


   pro1read= digitalRead (pro1) ;
   pro2read= digitalRead (pro2) ; 

   while (!pro1read) 
   {
    digitalWrite(relay1,HIGH) ; 
     
   }
   
   while (!pro2read) 
   {
    digitalWrite(relay2,HIGH) ; 
     
   }

//rfid 
 //search for new card
if ( ! rfid.PICC_IsNewCardPresent())
    return;
    
 //verfiy if the card had read or not
if ( ! rfid.PICC_ReadCardSerial())  
    return;
  Serial.print("PICC type: ");
  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
  Serial.println(rfid.PICC_GetTypeName(piccType));

   //check if the card is true or not 
   if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI && piccType != MFRC522::PICC_TYPE_MIFARE_1K && piccType != MFRC522::PICC_TYPE_MIFARE_4K)
   {
    Serial.println("Your tag is not of type MIFARE Classic.");
    return;
  }

  if (rfid.uid.uidByte[0] != cardnum[0] || 
    rfid.uid.uidByte[1] != cardnum[1] || 
    rfid.uid.uidByte[2] != cardnum[2] || 
    rfid.uid.uidByte[3] != cardnum[3] ) {
    Serial.println("A new card has been detected.");

//store card number into array
   for (byte i = 0; i < 4; i++) {
      cardnum[i] = rfid.uid.uidByte[i];
    }

  
  }
  else Serial.println("Card read previously.");

  rfid.PICC_HaltA();   // Halt PICC
  rfid.PCD_StopCrypto1();   // Stop encryption on PCD



  

  
  
  
  
  
  
  }
