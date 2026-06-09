//     UNOte Device
#include <LiquidCrystal.h>

LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

// buttons
const int A = 6;
const int B = 7;
const int C = 8;
const int D = 9;
const int E = A2;
const int F = A3;
const int G = A4;


#define T_C 523.2511
#define T_D 587.3295
#define T_E 659.2551
#define T_F 698.4565
#define T_G 783.991
#define T_A 440
#define T_B 493.8833

const int Buzz  = 10;
const int LED_R = 13;
const int LED_G = A5;


const int R_btn = A1;
const int L_btn = A0;

int randNumber;
const int delayTime = 300;

bool generate_note = true;
bool read_note = true;
bool end_ = false;

String note = "";
String note_user = "";


// My saved Notes




void setup()
{
   Serial.begin(9600);
  
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
 
  
  pinMode(R_btn, INPUT);
  pinMode(L_btn, INPUT);
  
  
  pinMode(A, INPUT);
  digitalWrite(A,HIGH);
  
  pinMode(B, INPUT);
  digitalWrite(B,HIGH);
  
  pinMode(C, INPUT);
  digitalWrite(C,HIGH);
  
  pinMode(D, INPUT);
  digitalWrite(D,HIGH);
  
   pinMode(E, INPUT);
  digitalWrite(E,HIGH);
  
  pinMode(F, INPUT);
  digitalWrite(F,HIGH);
  
  pinMode(G, INPUT);
  digitalWrite(G,HIGH);
  
  
  
  
  
  lcd_1.begin(16, 2); // Set up the number of columns and rows on the LCD.

  // Print a message to the LCD.
  lcd_1.print("Lets test your");
  lcd_1.setCursor(0, 1);
  lcd_1.print("music sense!");
  delay(3000);
  lcd_1.clear();
  lcd_1.setCursor(0, 0);
  lcd_1.print("Try to guess ");
  lcd_1.setCursor(0, 1);
  lcd_1.print("the correct note");
  delay(2000);
  
  
  
}

void loop()
{ 
    
  while(!digitalRead(R_btn)&& !digitalRead(L_btn))
  {
  lcd_1.setCursor(0, 0);
  lcd_1.print("are you ready?");
  lcd_1.setCursor(0, 1);
  lcd_1.print("Yes<--    -->Yes");
  
  }
  
  
  
  if (digitalRead(R_btn)|| digitalRead(L_btn))
  {
    
    
  while(!digitalRead(R_btn))
  {
    for (int i =0; i<4;)
    {
      // HBD
      if (i==0)
      {
      lcd_1.clear();
      lcd_1.setCursor(0, 0);
      lcd_1.print("*Happy Birthday*");
      lcd_1.setCursor(0, 1);
      lcd_1.print("OK<-- -->Change");
        
        while (i==0)
        {
      
          delay(3);
        
        if(digitalRead(R_btn))
        {
        read_saved_tones_HBD();
          
           while(!end_)
   {
     readInput();
   }
   endIt();
   
   end_ = false;
          
          
        }
        else if(digitalRead(L_btn))
        {
        i++;
        }}
      }
      // Twinkle
      else if (i==1)
      {
      lcd_1.clear();
      lcd_1.setCursor(0, 0);
      lcd_1.print("Twinkle Twinkle");
      lcd_1.setCursor(0, 1);
      lcd_1.print("OK<-- -->Change");
        
        while (i==1){
        delay(3);
        
        if(digitalRead(R_btn))
        {
        read_saved_tones_Twinkle();
          
            while(!end_)
   {
     readInput();
   }
   endIt();
   
   end_ = false;
          
          
        }
        else if(digitalRead(L_btn))
        {
        i++;
        }}
      }
      // n3
      else if (i==2)
      {
        lcd_1.clear();
      lcd_1.setCursor(0, 0);
      lcd_1.print("Random note");
      lcd_1.setCursor(0, 1);
      lcd_1.print("OK<-- -->Change");
        while (i==2){
      
          delay(3);
        
        if(digitalRead(R_btn))
        {
        doRandom();
          while(!end_)
   {
     readInput();
   }
   endIt();
   
   end_ = false;
        }
        else if(digitalRead(L_btn))
        {
        i++;
        }}
      }
      // to i =0
      else if(i==3)
      {
        i=0;
      }
      
      
    }
  }
    
    
    
  }
 note = "";
   note_user = ""; 
 
}

void doRandom() 
{
 
 
  lcd_1.clear();
  lcd_1.setCursor(0, 0);
  lcd_1.print("Listen then ");
  lcd_1.setCursor(0, 1);
  lcd_1.print("Enter the note");
    
    
  for (int i = 0; i <= 6; i++) {
    randNumber = random(0, 6);
    
    if (randNumber == 0)
    {
    playA();
      delay(delayTime);
    }
    else if (randNumber == 1)
    {
    playB();
      delay(delayTime);
    }
    else if (randNumber == 2)
    {
    playC();
      delay(delayTime);
    }
    else if (randNumber == 3)
    {
    playD();
      delay(delayTime);
    }
    
    else if (randNumber == 4)
    {
    playE();
      delay(delayTime);
    }
    else if (randNumber == 5)
    {
    playF();
      delay(delayTime);
    }
    
    else if (randNumber == 6)
    {
    playG(); 
      delay(delayTime);
    }
    noTone(Buzz);
    delay(delayTime);
    
  }
  
  Serial.println(note);
  
  
 
 
  
  

}

void readInput()
{
 
  
    
  if (note_user.length() <= (note.length()-1) ) {
  
  // READ PART 
   if(digitalRead(A) == HIGH)
  {
    note_user += 'A';
    tone(Buzz,T_A);
    
    digitalWrite(LED_G,HIGH);
    digitalWrite(LED_R,HIGH);
    delay(delayTime);
     digitalWrite(LED_G,LOW);
    digitalWrite(LED_R,LOW);
  }

  if(digitalRead(B) == HIGH)
  {
    note_user += 'B';
    tone(Buzz,T_B);
    digitalWrite(LED_G,HIGH);
    digitalWrite(LED_R,HIGH);
    delay(delayTime);
     digitalWrite(LED_G,LOW);
    digitalWrite(LED_R,LOW);
  }
  if(digitalRead(C) == HIGH)
  {
    note_user += 'C';
    tone(Buzz,T_C);
   digitalWrite(LED_G,HIGH);
    digitalWrite(LED_R,HIGH);
    delay(delayTime);
     digitalWrite(LED_G,LOW);
    digitalWrite(LED_R,LOW);
  }

  if(digitalRead(D) == HIGH)
  {
    note_user += 'D';
    tone(Buzz,T_D);
    digitalWrite(LED_G,HIGH);
    digitalWrite(LED_R,HIGH);
    delay(delayTime);
     digitalWrite(LED_G,LOW);
    digitalWrite(LED_R,LOW);
  }
    
     if(digitalRead(E) == HIGH)
  {
    note_user += 'E';
    tone(Buzz,T_E);
    digitalWrite(LED_G,HIGH);
    digitalWrite(LED_R,HIGH);
    delay(delayTime);
     digitalWrite(LED_G,LOW);
    digitalWrite(LED_R,LOW);
  }
    
     if(digitalRead(F) == HIGH)
  {
    note_user += 'F';
    tone(Buzz,T_F);
    digitalWrite(LED_G,HIGH);
    digitalWrite(LED_R,HIGH);
    delay(delayTime);
     digitalWrite(LED_G,LOW);
    digitalWrite(LED_R,LOW);
  }
    
     if(digitalRead(G) == HIGH)
  {
    note_user += 'G';
    tone(Buzz,T_G);
    digitalWrite(LED_G,HIGH);
    digitalWrite(LED_R,HIGH);
    delay(delayTime);
     digitalWrite(LED_G,LOW);
    digitalWrite(LED_R,LOW);
  }

  noTone(Buzz);
 
    
  }
  else if (note_user.length()==note.length())
  {
 
  Serial.println(read_note);
     
     
     end_ = true;
  }
  
}


void endIt()
{
if (end_){
  if(note_user == note)
  {
  lcd_1.clear();
  lcd_1.setCursor(0, 0);
  lcd_1.print("*** GOOD JOB ***");
  end_= false;
  digitalWrite(LED_G,HIGH);
  digitalWrite(LED_R,LOW);
    
    lcd_1.setCursor(0, 1);
      lcd_1.print("Again<- ->Change");
 
    
  }
  else if(note_user != note)
  {
  lcd_1.clear();
  lcd_1.setCursor(0, 0);
  lcd_1.print("false");
  lcd_1.setCursor(0, 1);
  lcd_1.print("note=");
  lcd_1.setCursor(5, 1);
  lcd_1.print(note);
  end_= false;
  digitalWrite(LED_R,HIGH);
  digitalWrite(LED_G,LOW);
    delay(6000);
    
    lcd_1.setCursor(0, 1);
      lcd_1.print("Again<- ->Change");
 
   
    
  }
  
   note = "";
   note_user = "";
  }
  
}

void saved()
{


}


void playA()
{
    note += 'A';
    tone(Buzz,T_A);
    
}

void playB()
{
note += 'B';
    tone(Buzz,T_B);
    
}

void playC()
{
note += 'C';
    tone(Buzz,T_C);
   
}

void playD()
{
 note += 'D';
    tone(Buzz,T_D);
     
}

void playE()
{
note += 'E';
    tone(Buzz,T_E);
    
}

void playF()
{
 note += 'F';
    tone(Buzz,T_F);
     
}

void playG()
{
note += 'G';
    tone(Buzz,T_G);
   
}


void read_saved_tones_HBD()
{
  
  playG();//delay(100);
  delay(delayTime/2);
  
  
  playG();//delay(100);
  delay(delayTime/2);
  
  
  playA();//delay(200);
  delay(delayTime);
  
  
  playG();//delay(200);
  delay(delayTime);
  
  
  playC();//delay(200);
  delay(delayTime);
  
  
  playB();//delay(400);
  delay(delayTime*2);
 
  
  
  /*playG();delay(100);
  playG();delay(100);
  playA();delay(200);
  playG();delay(200);
  playD();delay(200);
  playC();delay(400);
  
  playG();delay(100);
  playG();delay(100);
  playG();delay(200);
  playE();delay(200);
  playC();delay(200);
  playB();delay(200);
  playA();delay(600);
  
  playF();delay(100);
  playF();delay(100);
  playE();delay(200);
  playC();delay(200);
  playD();delay(200);
  playC();delay(400);*/
  
  noTone(Buzz);

}
void read_saved_tones_n3()
{
  

}
void read_saved_tones_Twinkle()
{
  playC();//delay(100);
  delay(delayTime);
  noTone(Buzz);
  delay(50);
  
  playC();//delay(100);
  delay(delayTime);
   noTone(Buzz);
  delay(50);
  
  
  playG();//delay(200);
  delay(delayTime);
    noTone(Buzz);
  delay(50);

  
  playG();//delay(200);
  delay(delayTime);
  noTone(Buzz);
  delay(50);
  
  playA();//delay(200);
  delay(delayTime);
  noTone(Buzz);
  delay(50);
  
  playA();//delay(400);
  delay(delayTime);
  noTone(Buzz);
  delay(50);
  
  playG();//delay(400);
  delay(delayTime*2);
  noTone(Buzz);
  delay(50);
  /////////////////////////////////
  
 /* playF();//delay(100);
  delay(delayTime);
  noTone(Buzz);
  delay(50);
  
  playF();//delay(100);
  delay(delayTime);
  noTone(Buzz);
  delay(50);
  
  
  playE();//delay(200);
  delay(delayTime);
  noTone(Buzz);
  delay(50);
  
  playE();//delay(200);
  delay(delayTime);
  noTone(Buzz);
  delay(50);
  
  playD();//delay(200);
  delay(delayTime);
  noTone(Buzz);
  delay(50);
  
  playD();//delay(400);
  delay(delayTime);
  noTone(Buzz);
  delay(50);
  
  playC();//delay(400);
  delay(delayTime*2);
noTone(Buzz);
  delay(50);*/
  
  noTone(Buzz);
}
  
