int led1=9;
int led2=10;
int led3=13;
int led4=12;
int led5=11;
int led6=8;
int ledState=LOW;

int ledValue=0;

int pot=A0;
int pot1=A1;
int potValue=0;
int pot1Value=0;

int toggleValue=0;

unsigned long previousMillis = 0;
long interval = 100;

void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  
  //Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentMillis = millis();

  potValue = analogRead(pot);
  ledValue = map(potValue, 0 ,1023, 0 , 6);

  pot1Value=analogRead(pot1);
  interval = map(pot1Value, 0, 1023, 50 , 500);
  
  //Serial.println(pot1Value);
  if (currentMillis - previousMillis >= interval)
  {
    previousMillis= currentMillis;
    if (ledState == LOW)
      ledState = HIGH;
    else
      ledState = LOW;
  }

  if(ledValue == 0)
  {
    digitalWrite(led1, ledState);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
    digitalWrite(led6, HIGH);
  }
  else if (ledValue == 1)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, ledState);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
    digitalWrite(led6, HIGH);
  }
  else if (ledValue == 2)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, ledState);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
    digitalWrite(led6, HIGH);
  }
  else if (ledValue == 3)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, ledState);
    digitalWrite(led5, HIGH);
    digitalWrite(led6, HIGH);
  }
  else if (ledValue == 4)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, ledState);
    digitalWrite(led6, HIGH);
  }
  else
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
    digitalWrite(led6, ledState);
  }
}
