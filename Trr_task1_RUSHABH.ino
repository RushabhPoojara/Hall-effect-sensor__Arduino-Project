int revolutions=0;
int rpm=0;
long startTime=0;
long elapsedTime;  //initial values

void setup()
  {
      pinMode(2, INPUT_PULLUP);  // setting pin to input
      Serial.begin(9600);
  }

void loop()
  {
    int revolutions = 0 ; long rpm = 0;
    
    startTime=millis();
    
    attachInterrupt(0,interruptfunc,RISING);
    delay(1000);
    detachInterrupt(0);

    elapsedTime = millis() - startTime;

 if(revolutions>0) 
     {
      rpm = revolutions*60 / elapsedTime;  // this part of the code calculates the rpm in a way that every time the magnet passes by the sensor, the time between the pulses is measured and rpm is calculated.
     }
 
          
      Serial.println(rpm*1000);
 
   }

void interruptfunc()

  {
  revolutions++;
  
  }
