/*
  Objective: Quick application that will demonstrate lighting up a single LED.
  Written by: Joseph Anger
  Created Date: 10/5/2019
*/

int LED = 13; //Defines the socket our LED signal will be sent from
int DELAYSPEED = 500; //Defines the speed at which we wait between blinks

void setup() {
  // Initialize the object for use
  pinMode(LED, OUTPUT);
}

void loop() {
  // Do something neat with your LED!
  blink(DELAYSPEED);
  //morseCode();
}

/* Basic function that blinks the bulb at a given speed. */
void blink(int interval){
  digitalWrite(LED, HIGH);
  delay(interval);
  digitalWrite(LED, LOW);
  delay(interval);
}

/* Function that sends out the SOS message in morse code using our blink method */
void morseCode(){

  //Our morse code message has 9 signals. 3 short, 3 long, 3 short
  for(int i = 0; i < 9; i++)
  {
    //Shorten the delay times in our pattern for the short durations
    int skewedDelay = DELAYSPEED;

    if(i < 3 || i > 5){
      skewedDelay = DELAYSPEED / 2;
    }

    //Blink the bulb
    blink(skewedDelay);

    //Small extra delay to break apart the paterns for readability
    if(i == 2 || i == 5){
      delay(DELAYSPEED);
    }
  }

  //Signify the end of the code message loop with a longer delay
  digitalWrite(LED, LOW);
  delay(DELAYSPEED * 2);
  
}
