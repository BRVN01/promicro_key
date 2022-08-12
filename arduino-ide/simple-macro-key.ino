#include <Keyboard.h>

//Entradas digitais
#define pin6 6
#define pin7 7
#define pin8 8
#define pin9 9
#define pin10 10
#define pin16 16

void setup() {
  //Entradas digitais
  pinMode(pin9, INPUT_PULLUP);
  pinMode(pin8, INPUT_PULLUP);
  pinMode(pin7, INPUT_PULLUP);
  pinMode(pin6, INPUT_PULLUP);
  pinMode(pin10, INPUT_PULLUP);
  pinMode(pin16, INPUT_PULLUP);

  //Inicia o objeto keyboard
  Keyboard.begin();
 
}//end setup
 
 
void loop() {
  if(digitalRead(pin9) == LOW)
  { 
//    Keyboard.write('`');
//    Send Left-Shift + '
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press('`'); 
    Keyboard.releaseAll();
    delay(200);//Atraso de 100ms
  }
 
  if(digitalRead(pin8) == LOW)
  { 
//    Send Left-Shift + F24
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_F24); 
    Keyboard.releaseAll();
    delay(100);
  }
 
  if(digitalRead(pin7) == LOW)
  { 
//    Send Left-Ctrl + Left-Shift + a
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('A'); 
    Keyboard.releaseAll();
    delay(100);
  }
 
  if(digitalRead(pin6) == LOW){ 

//    Send Left-Ctrl + Left-Shift + b
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('B'); 
    Keyboard.releaseAll();
    delay(100);
  }

  if(digitalRead(pin10) == LOW){ 

//    Send Left-Ctrl + c
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('c'); 
    Keyboard.releaseAll();
    delay(100);
  }

  if(digitalRead(pin16) == LOW){ 
//    Send number 1
    Keyboard.write('1'); 
    Keyboard.releaseAll();
    delay(100);
  }
 
}//endloop
