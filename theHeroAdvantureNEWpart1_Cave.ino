//BadEnd2 is commented out
//Cave1Scenario5 is commented out
//Reason, RedBoard doesn't have enough memory to store it.

const int leftButton = 2;    
const int rightButton =  3;      
#include <LiquidCrystal.h>
LiquidCrystal lcd(4, 6, 10, 11, 12, 13);
// variables will change:
int HP=0;

void setup() {
  pinMode(leftButton, INPUT);      
  pinMode(rightButton, INPUT);
  delay(2000);
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  int introDecision = intro();
  if (introDecision==1)
  {
    int stage1Decision=stage1Cave();
    if (stage1Decision==0)
    {
      //badEnd2();
      printStr("Bad End 2:");
      printStr2("");
      lcd.clear();
    }
    else
    {      
      printStr("TO BE CONTINUED.");
      printStr2("              ->");
      lcd.clear();
    }
  }
  else
  {
    badEnd1();
  }
  
  printStr("Press any button");
  printStr2("to restart.   ->");
  lcd.clear();
}

//***STORY***

int intro()
{
  printStr("The Hero Wannabe");
  printStr2("is sailing ");
  lcd.clear();
  
  printStr("through the ");
  printStr2("ocean and he");
  lcd.clear();
  
  printStr("came across a");
  printStr2("strange island.");
  lcd.clear();
  
  printStr("Then the Hero");
  printStr2("Wannabe witness");
  lcd.clear();
  
  printStr("a cave on the");
  printStr2("island.");
  lcd.clear();
  
  printStr("1) Goes in the");
  printStr2("cave.");
  lcd.clear();
  
  printStr("2) It's too");
  printStr2("dangerous to go");
  lcd.clear();
  
  printStr("alone, go home.");
  printStr2("");
  lcd.clear();
  
  return makeDecision();
}

//Return 0 when HP remain
//1 = left path
//2 = right path
int stage1Cave()
{
  HP=2;
  printStr("You are inside a");
  printStr2("very dark cave.");
  lcd.clear();
  
  int leftCounter=0;
  int rightCounter=0;
  
  int scenarioCounter=0;
  
  int turn=1;
  while (HP > 0 && turn < 6)
  {
    scenarioCounter++;
    printStr("You see 2 paths");
    printStr2("ahead of you:");
    lcd.clear();
    
    printStr("1) Go Left");
    printStr2("2) Go Right");
    lcd.clear();
    
    int decision=makeDecision();
    
    if (decision==1)
    {
      leftCounter++;
    }
    else
    {
      rightCounter++;
    }
    
    stage1Scenario(scenarioCounter);
    
    String hpRemain="HP remain: "+String(HP);
    printStr(hpRemain);
    printStr2("              ->");
    lcd.clear();
    turn++;
    
  }
  
  if (HP==0)
  {
    return 0;
  }
  else if (leftCounter>rightCounter)
  {
    return 1;
  }
  else
  {
    return 2;
  }
}

void stage1Scenario(int n)
{
  int decision;
  if (n==1)
  {
    printStr("There is a");
    printStr2("rolling boulder");
    lcd.clear();
    
    printStr("behind you, what");
    printStr2("do you do:");
    lcd.clear();
    
    printStr("1) Mamma Mia,Run");
    printStr2("2) Pretend dead");
    lcd.clear();
    
    decision=makeDecision();
    
    if (decision==1)
    {
      printStr("You can't outrun");
      printStr2("the boulder, it");
      lcd.clear();
      
      printStr("crushes you.");
      printStr2("HP-1        ->");
      lcd.clear();
      HP--;
    }
    else
    {
      printStr("The boulder");
      printStr2("rolls the other");
      lcd.clear();
      
      printStr("direction, you");
      printStr2("got out alive.->");
      lcd.clear();
    }
  }
  else if(n==2)
  {
    printStr("There's a giant");
    printStr2("door. There's a");
    lcd.clear();
    
    printStr("sign on it that");
    printStr2("says");
    lcd.clear();
    
    printStr("\"STAY OUT!!!\"");
    printStr2("              ->");
    lcd.clear();
    
    printStr("1) Enter the");
    printStr2("door");
    lcd.clear();
    
    printStr("2) Be a chicken");
    printStr2("and run away");
    lcd.clear();
    
    decision=makeDecision();
    
    if(decision==1)
    {
      printStr("You were greet");
      printStr2("by a gentlemen");
      lcd.clear();
      
      printStr("with a mustache.");
      printStr2("You drink tea");
      lcd.clear();
      
      printStr("with him.");
      printStr2("              ->");
      lcd.clear();
    }
    else
    {
      printStr("The door spits a");
      printStr2("poro at you.HP-1");
      lcd.clear();
      
      HP--;
    }
  }
  else if(n==3)
  {
    printStr("There a Hunter");
    printStr2("that looks like");
    lcd.clear();
    
    printStr("a kitten and the");
    printStr2("hunter gave you");
    lcd.clear();
    
    printStr("a question,");
    printStr2("");
    lcd.clear();
    
    printStr("\"Who is the best");
    printStr2("Hunter in the");
    lcd.clear();
    
    printStr("world?\"");
    printStr2("              ->");
    lcd.clear();
    
    printStr("1) Rexxar");
    printStr2("2) Rengar");
    lcd.clear();
    
    decision=makeDecision();
    
    if (decision==1)
    {
      printStr("\"RAWR! YOU");
      printStr2("FOOL!!!\"");
      lcd.clear();
      
      printStr("The hunter");
      printStr2("attacked you.");
      lcd.clear();
      
      printStr("HP-1");
      printStr2("              ->");
      lcd.clear();
      HP--;
    }
    else
    {
      printStr("\"Meow, i knew i");
      printStr2("was the best");
      lcd.clear();
      
      printStr("hunter.\"");
      printStr2("");
      lcd.clear();
      
      printStr("The Hunter walks");
      printStr2("away.         ->");
      lcd.clear();
    }
  }
  else if(n==4)
  {
    printStr("There is a");
    printStr2("bright pool of");
    lcd.clear();
    
    printStr("water in front");
    printStr2("of you.");
    lcd.clear();
    
    printStr("1) Drink from it");
    printStr2("it looks really");
    lcd.clear();
    
    printStr("clean and");
    printStr2("healthy.");
    lcd.clear();
    
    printStr("2) Ew, who would");
    printStr2("drink these");
    lcd.clear();
    
    printStr("disguesting");
    printStr2("water");
    lcd.clear();
    
    decision=makeDecision();
    
    if (decision==1)
    {
      printStr("It's a healing");
      printStr2("fountain, all");
      lcd.clear();
      
      printStr("your HP");
      printStr2("recovers!!!");
      lcd.clear();
      
      printStrTimed("....", 600);
      lcd.clear();
      
      printStr("Or so you");
      printStr2("thought before");
      lcd.clear();
      
      printStr("you end up");
      printStr2("throwing up and");
      lcd.clear();
      
      printStr("wish you were");
      printStr2("dead. HP-1    ->");
      lcd.clear();
      HP--;
    }
    else
    {
      printStr("The water rise");
      printStr2("up and tries to");
      lcd.clear();
      
      printStr("attack you, but");
      printStr2("you were able to");
      lcd.clear();
      
      printStr("run away in time");
      printStr2("it was a slime->");
      lcd.clear();      
    }
  }
  else
  {
      /*printStr("You see a big");
      printStr2("red button...");
      lcd.clear();
      
      printStr("1) PUSH ITTTTT!");
      printStr2("2) Ignore it");
      lcd.clear();
      
      decision=makeDecision();
      
      if(decision==1)
      {
        printStr("YOU PUSHED IT");
        printStr2Timed("....", 600);
        lcd.clear();
        
        printStr("nothing happens.");
        printStr2("              ->");
        lcd.clear();
      }
      else
      {
        printStr("As you ignore it");
        printStr2("and walk pass");
        lcd.clear();
        
        printStr("it, the button");
        printStr2("explodes near");
        lcd.clear();
        
        printStr("you. HP-1");
        printStr2("              ->");
        lcd.clear();
      }*/
  }
}

void badEnd1()
{
  printStr("The Hero return");
  printStr2("as a loser, with");
  lcd.clear();
  
  printStr("no achievement");
  printStr2("at all. Rejected");
  lcd.clear();
  
  printStr("by the women you");
  printStr2("love, exiled by");
  lcd.clear();
  
  printStr("the kingdom you");
  printStr2("serve. You live");
  lcd.clear();
  
  printStr("the rest of your");
  printStr2("life as a");
  lcd.clear();
  
  printStr("homeless bum.");
  printStr2("              ->");
  lcd.clear();
  
  printStr("Bad End 1:");
  printStr2("Forever Alone");
  lcd.clear();
}

/*void badEnd2()
{
  printStr("Now you are dead");
  printStr2("as your bones");
  lcd.clear();
  
  printStr("remains to rot");
  printStr2("inside the cave.");
  lcd.clear();
  
  printStr("Bad End 2:");
  printStr2("Left2Rot");
  lcd.clear();
}*/

//***METHODS***

//1 = left
//2 = right
int buttonInput()
{
  int buttonPressed=-1;
  while (buttonPressed == -1)
  {
    int leftState = digitalRead(leftButton);
    int rightState = digitalRead(rightButton);
    if (leftState==1)
    {
      buttonPressed=1;
    }
    else if(rightState==1)
    {
      buttonPressed=2;
    }
  }
  return buttonPressed;
}

void printStr(String str)
{
  int len=str.length();
  lcd.setCursor(0,0);
  for (int i=0; i<len; i++)
  {
    lcd.print(str.charAt(i));
    //Serial.print(str.charAt(i));
    delay(50);
  }
}
int printStr2(String str)
{
  int len=str.length();
  lcd.setCursor(0,1);
  for (int i=0; i<len; i++)
  {
    lcd.print(str.charAt(i));
    //Serial.print(str.charAt(i));
    delay(50);
  }
  //press a button to continue
  return buttonInput();
}

void printStrTimed(String str, int time)
{
  int len=str.length();
  lcd.setCursor(0,0);
  for (int i=0; i<len; i++)
  {
    lcd.print(str.charAt(i));
    delay(time);
  }
}

int printStr2Timed(String str, int time)
{
  int len=str.length();
  lcd.setCursor(0,1);
  for (int i=0; i<len; i++)
  {
    lcd.print(str.charAt(i));
    delay(time);
  }
}

int makeDecision()
{
  printStr("(Make your");
  int decision=printStr2("Decision)     ->");
  lcd.clear();
  
  return decision;
}
