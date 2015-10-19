//This is the 4 leds
int led1=2;
int led2=5;
int led3=3;
int led4=4;


//This is the 4 buttons
int up=8;
int down=9;
int left=10;
int right=11;

//Tracking current LED Position
int currentLEDPos=1;

//Keeping track if a button is pressed or not
int buttonState1=LOW;
int buttonState2=LOW;
int buttonState3=LOW;
int buttonState4=LOW;
int lastButtonState1 = 0;
int lastButtonState2 = 0;
int lastButtonState3 = 0;
int lastButtonState4 = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  
  pinMode(up, INPUT);
  pinMode(down, INPUT);
  pinMode(left, INPUT);
  pinMode(right, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Making the LED light up at the position it should light up
  if (currentLEDPos==1)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }
  else if (currentLEDPos==2)
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }
  else if (currentLEDPos==3)
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
  }
  else
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
  }
  
  //Coding for up button
  //Checking if the button is released
  buttonState1=digitalRead(up);
  if (buttonState1 != lastButtonState1)
  {//If the button state has changed.
    if (buttonState1==LOW)
    {//If the button has been released
      if (currentLEDPos==1)
      {
        currentLEDPos=3;
      }
      else if (currentLEDPos==2)
      {
        currentLEDPos=4;
      }
      else
      {
        //Do Nothing
      }
    }
  }
  
  //Coding for Down button
  //Checking if the button is released
  buttonState2=digitalRead(down);
  if (buttonState2 != lastButtonState2)
  {//If the button state has changed.
    if (buttonState2==LOW)
    {//If the button has been released
      if (currentLEDPos==3)
      {
        currentLEDPos=1;
      }
      else if (currentLEDPos==4)
      {
        currentLEDPos=2;
      }
      else
      {
        //Do Nothing
      }
    }
  }
  
  //Coding for left button
  //Checking if the button is released
  buttonState3=digitalRead(left);
  if (buttonState3 != lastButtonState3)
  {//If the button state has changed.
    if (buttonState3==LOW)
    {//If the button has been released
      if (currentLEDPos==2)
      {
        currentLEDPos=1;
      }
      else if (currentLEDPos==4)
      {
        currentLEDPos=3;
      }
      else
      {
        //Do Nothing
      }
    }
  }
  //Coding for right button
  //Checking if the button is released
  buttonState4=digitalRead(right);
  if (buttonState4 != lastButtonState4)
  {//If the button state has changed.
    if (buttonState4==LOW)
    {//If the button has been released
      if (currentLEDPos==1)
      {
        currentLEDPos=2;
      }
      else if (currentLEDPos==3)
      {
        currentLEDPos=4;
      }
      else
      {
        //Do Nothing
      }
    }
  }
  
  lastButtonState1 = buttonState1;
  lastButtonState2 = buttonState2;
  lastButtonState3 = buttonState3;
  lastButtonState4 = buttonState4;
  
  
}
