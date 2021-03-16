/* Buzzer connected to pin 13
 * Servos Respectively to pins 9,10,11
 * LDR inputs to analog pins A0,A1,A2
 * Digital of LCD to digital pins 5,4,3,2 of Arduino
 *
 *
 * Made by Suvam Dey, for CS Project   
 * 
 * Recommended Board:Arduino Nano (328)
 *
 *Hopefully this Will Work
 *
 *
 *
*/



#include <Servo.h> 
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

#define melodyPin 13
//Mario main theme melody
int melody[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7,
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0,

  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,

  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0,

  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,

  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0
};
//Mario main them tempo
int tempo[] = {
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
};
/*           End of Super Mario Definition
*
*
*
*
*
*
*
*/





 
Servo myservo0;  // create servo object to control a servo 
Servo myservo1; 




                // a maximum of eight servo objects can be created 
 
int Ran,pos = 0, Score=0;
long unsigned int Count;    // variable to store the servo position 
 



void setup() 
{ lcd.begin(16, 2); 
  myservo0.attach(9);  // attaches the servo on pin 9 to the servo object 
  myservo1.attach(10); 
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(13,OUTPUT);
 Serial.begin(9600); 
} 
 
 
void loop() 
{ 
  Count=millis()/1000;
  lcd.setCursor(0, 1); 
  lcd.print(Count); 
if(Count <= 40){
  
  
  Ran=random(46);

Serial.println(Ran);

                    if(Ran%2==0){
                         for(pos = 0; pos < 90; pos += 1)  // goes from 0 degrees to 180 degrees 
                              {                                  // in steps of 1 degree 
                                myservo0.write(pos);              // tell servo to go to position in variable 'pos' 
                                delay(5);                       // waits 15ms for the servo to reach the position 
                              } 
                              delay(20);
                              //Checks for Target
                              if(digitalRead(A0)==HIGH){
                                Score += 10;
                                digitalWrite(13,HIGH);
                                delay(60);
                                digitalWrite(13,LOW);
                                }                          
                                             
                              
                         for(pos = 90; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
                              {                                
                                myservo0.write(pos);              // tell servo to go to position in variable 'pos' 
                                delay(10);                       // waits 15ms for the servo to reach the position 
                              } 
           }
                     else{
                         for(pos = 0; pos < 90; pos += 1)  // goes from 0 degrees to 180 degrees 
                            {                                  // in steps of 1 degree 
                              myservo1.write(pos);              // tell servo to go to position in variable 'pos' 
                              delay(10);                       // waits 15ms for the servo to reach the position 
                            } 
                            if(digitalRead(A1)==HIGH){
                                Score += 10;
                                digitalWrite(13,HIGH);
                                delay(60);
                                digitalWrite(13,LOW);
                                }                          
                           

                            for(pos = 90; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
                            {                                
                              myservo1.write(pos);              // tell servo to go to position in variable 'pos' 
                              delay(10);                       // waits 15ms for the servo to reach the position 
                            } 
                     }
              }
              
              else
              {
              lcd.setCursor(1, 0); 
              lcd.print(Score); 
              sing(1);
              }
}


//   This is The Song Section
/*
*
*
*
*
*
*
*
*
*
*
*
*
*/
  int song = 0;

 void sing(int s) {
  // iterate over the notes of the melody:
  song = s;

    
    int size = sizeof(melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {

      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / tempo[thisNote];

      buzz(melodyPin, melody[thisNote], noteDuration);

      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);

      // stop the tone playing:
      buzz(melodyPin, 0, noteDuration);

    
  }
}

   
   
   void buzz(int targetPin, long frequency, long length) {

  long delayValue = 1000000 / frequency / 2; // calculate the delay value between transitions
  //// 1 second's worth of microseconds, divided by the frequency, then split in half since
  //// there are two phases to each cycle
  long numCycles = frequency * length / 1000; // calculate the number of cycles for proper timing
  //// multiply frequency, which is really cycles per second, by the number of seconds to
  //// get the total number of cycles to produce
  for (long i = 0; i < numCycles; i++) { // for the calculated length of time...
    digitalWrite(targetPin, HIGH); // write the buzzer pin high to push out the diaphram
    delayMicroseconds(delayValue); // wait for the calculated delay value
    digitalWrite(targetPin, LOW); // write the buzzer pin low to pull back the diaphram
    delayMicroseconds(delayValue); // wait again or the calculated delay value
  }
     
}
                    
