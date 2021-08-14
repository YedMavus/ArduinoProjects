/*
  Blink, but more useful.

  This code uses an arduino as a timer to alert homeowners to switch off mater Pump on time (set to 20minutes by default). 
  To change the time to alarm, vary the numerical value after ```# define timer``` [must be expressed in seconds]
  The 13th PIN has an LED connected to it by default, so we have used the same here. To the 13th Pin, a buzzer or an AC relay may be connected 
  (to automate the switching off process - will require modification of code and addition of another pin for this specific process).
  
  Code and idea by Suvam Dey
  github.com/YedMavus
  
*/
# define timer 1200000
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  //long int TIME = timer * 60 * 1000;
  for(int i = 0; i<5; i++)
   {
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(100);                       // wait for 0.1sec
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    delay(100);                       // wait for 0.1sec
   }
  digitalWrite(LED_BUILTIN, LOW);
  delay(timer); // "timer" milliseconds of delay
  // Begining of the alarm function, by continiously blinking
  while(true)
  {
     digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(500);                       // wait for 0.5 sec
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    delay(500);                       // wait for 0.5 sec
    
  }
}
