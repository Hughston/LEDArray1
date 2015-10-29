/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  This example code is in the public domain.
 */

// Pin 13 has an LED connected on most Arduino boards.
// Pin 11 has the LED on Teensy 2.0
// Pin 6  has the LED on Teensy++ 2.0
// Pin 13 has the LED on Teensy 3.0
// give it a name:
// A1 = 13,7;
int a = 2; int b = 3; int c = 4;
int aa = 10; int bb = 9; int cc = 8; int dd = 7; int ee = 6; int ff = 5;
const byte numberOfColumns = 123;
const byte numberOfColumnsOxford = 46;
const byte numberOfColumnsHackspace = 73;


char scrollArrayOxford[6][numberOfColumnsOxford] = {
{1,1,0,0,0,0,0,1,1,0,0,1,1,0,0,1,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,1,1,1,1,1} ,
{1,0,0,0,1,1,0,0,1,1,0,0,1,0,1,1,1,0,0,1,1,0,1,0,0,1,1,0,0,1,0,0,1,1,0,0,1,1,0,0,1,0,0,1,1,1} ,
{1,0,0,1,1,1,1,0,0,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,0,0,1,0,0,0,0,0,0,1,1,0,0,1,1,0,0,1,1} ,
{1,0,0,1,1,1,1,0,0,1,1,0,0,1,1,1,1,0,0,0,0,1,1,0,0,1,1,0,0,1,0,0,1,0,0,1,1,1,0,0,1,1,0,0,1,1} ,
{1,0,0,0,1,1,0,0,1,1,0,1,0,0,1,1,1,0,0,1,1,1,1,0,0,1,1,0,0,1,0,0,1,1,0,0,1,1,0,0,1,0,0,1,1,1} ,
{1,1,0,0,0,0,0,1,1,0,0,1,1,0,0,1,0,0,0,1,1,1,1,1,0,0,0,0,1,1,0,0,1,1,0,0,1,0,0,0,0,0,1,1,1,1} 
};

char scrollArrayHackspace[6][numberOfColumnsHackspace] = {
{1,0,0,0,0,1,0,0,0,0,1,1,1,0,0,1,1,1,1,1,0,0,0,0,0,1,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,1,0,0,1,1,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1} ,
{1,1,0,0,1,1,1,0,0,1,1,1,0,0,1,0,1,1,1,0,0,1,1,0,0,1,1,0,0,1,0,0,1,1,1,0,0,0,1,1,0,0,1,0,0,1,1,0,0,1,0,0,1,0,1,1,1,0,0,1,1,0,0,1,1,0,0,1,1,1,0,1,1},
{1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,1,1,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1},
{1,1,0,0,1,1,1,0,0,1,1,0,0,1,1,1,0,0,1,0,0,1,1,1,1,1,1,0,0,1,0,0,1,1,1,1,1,1,0,0,0,1,1,0,0,1,1,1,1,0,0,1,1,1,0,0,1,0,0,1,1,1,1,1,1,0,0,1,0,1,1,1,1},
{1,1,0,0,1,1,1,0,0,1,1,0,0,1,1,1,0,0,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,1,0,0,1,0,0,1,1,1,1,0,0,1,1,1,0,0,1,0,0,1,1,0,0,1,1,0,0,1,1,1,0,1,1},
{1,0,0,0,0,1,0,0,0,0,1,0,0,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,1,1,0,0,0,1,1,0,0,0,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1}
};


int scrollArrayAnimation1[22][6][6] = {
  {
{1,1,1,1,1,1},
{1,1,1,1,1,1},
{1,1,1,1,1,0},
{1,1,1,1,1,1},
{1,1,1,1,1,1},
{1,1,1,1,1,1}
},
{
{1,1,1,1,1,1},
{1,1,1,1,1,1},
{1,1,1,1,0,1},
{1,1,1,1,0,1},
{1,1,1,1,1,1},
{1,1,1,1,1,1}
},
{
{1,1,1,1,1,1},
{1,1,1,1,1,1},
{1,1,0,0,1,1},
{1,1,0,1,1,1},
{1,1,1,1,1,1},
{1,1,1,1,1,1}
},
{
{1,1,1,1,1,1},
{1,1,0,1,1,1},
{1,0,0,0,1,1},
{1,1,0,1,1,1},
{1,1,1,1,1,1},
{1,1,1,1,1,1}
},
{
{1,1,1,1,1,1},
{1,0,0,0,1,1},
{1,1,0,1,1,1},
{1,0,0,0,1,1},
{1,1,1,1,1,1},
{1,1,1,1,1,1}
},
{
{1,1,0,1,1,1},
{1,1,0,0,1,1},
{0,0,0,0,0,1},
{1,0,0,1,1,1},
{1,1,0,1,1,1},
{1,1,1,1,1,1}
},
{
{1,1,0,1,1,1},
{0,1,0,0,1,1},
{0,0,0,0,0,1},
{1,0,0,1,0,1},
{1,1,0,1,1,1},
{1,1,1,1,1,1}
},
{
{0,1,1,0,0,1},
{0,0,1,0,1,1},
{1,0,0,0,1,1},
{1,0,1,0,0,1},
{0,0,1,1,0,1},
{1,1,1,1,1,1}
},
{
{0,0,1,0,0,1},
{1,0,1,0,1,1},
{1,0,0,0,1,1},
{1,0,0,0,1,1},
{1,0,1,0,1,1},
{0,0,1,0,0,1}
},
{
{0,0,0,1,0,0},
{0,0,1,1,0,0},
{1,0,0,0,0,1},
{0,0,0,0,1,1},
{0,1,1,0,0,1},
{0,1,0,0,0,1}
},
{
{1,1,1,0,0,0},
{1,1,0,0,1,1},
{1,0,0,0,0,1},
{0,0,1,0,0,0},
{1,0,1,1,0,0},
{1,1,0,0,0,1}
},
{
{1,0,0,1,1,0},
{1,0,0,0,0,0},
{1,0,1,0,0,1},
{1,1,1,0,0,1},
{1,0,1,0,0,1},
{1,0,0,0,0,0}
},
{
{1,1,0,0,0,1},
{1,1,1,0,0,1},
{0,1,0,0,0,0},
{0,0,0,0,0,0},
{0,0,0,0,0,1},
{1,1,0,0,1,1}
},
{
{0,1,1,0,0,1},
{0,1,1,0,0,1},
{0,0,1,1,0,0},
{0,0,0,0,0,0},
{1,0,0,0,0,0},
{1,0,0,1,1,0}
},
{
{0,0,1,1,1,1},
{0,0,1,1,1,0},
{0,0,0,0,1,0},
{0,1,0,0,0,0},
{0,1,1,1,0,0},
{1,1,1,1,0,0}
},
{
{0,0,0,0,1,1},
{0,0,0,1,1,1},
{0,0,0,0,1,1},
{0,1,0,0,0,1},
{1,1,1,0,0,0},
{1,1,1,1,0,0}
},
{
{0,0,0,0,0,1},
{0,0,0,1,1,1},
{0,1,0,0,1,1},
{1,1,0,0,1,0},
{1,1,1,0,0,0},
{1,1,0,0,0,0}
},
{
{0,0,0,0,0,0},
{0,0,0,0,1,1},
{1,1,0,0,0,1},
{1,1,1,0,0,1},
{1,1,1,0,0,0},
{1,0,0,0,0,0}
},
{
{0,0,0,0,0,0},
{0,0,0,0,0,0},
{0,1,0,0,1,0},
{1,1,0,0,1,1},
{0,1,0,0,1,0},
{0,0,0,0,0,0}
},
{
{1,0,0,0,0,1},
{0,1,1,0,0,0},
{0,1,0,0,0,0},
{0,0,0,0,1,0},
{0,0,0,1,1,0},
{1,0,0,0,1,1}
},
{
{0,1,1,0,0,0},
{0,1,1,1,0,0},
{0,0,0,0,0,0},
{0,0,0,0,0,0},
{0,0,1,1,1,0},
{0,0,0,1,1,1}
},
{
{1,0,0,0,1,0},
{1,0,0,1,1,1},
{1,0,0,0,0,0},
{1,0,0,0,0,0},
{1,0,0,1,1,1},
{1,0,0,0,1,0}
}
};

// the setup routine runs once when you press reset:
void setup() {
  reset();

}

// the loop routine runs over and over again forever:
void loop() {
  for (int myColumn = -6; myColumn <= numberOfColumnsOxford; myColumn++) {

  for (int frame = 1; frame <= 10; frame++) {
    //int ledArray[6][6] = {
    // {1, 1, 0, 0, 1, 1} , //03.5/5.03   03.6/6.03  03.7/7.03
    //  {1, 1, 1, 0, 0, 1} , //02.5/5.02
     // {0, 1, 0, 0, 0, 0} , //00.5/5.00
     // {0, 0, 0, 0, 1, 0} , //00.5/5.00
     // {1, 0, 0, 1, 1, 1} , //09.5/
     // {1, 1, 0, 0, 1, 1} //08.5/
    //};


    for (int col = 1; col <= 6; col++) {
      reset();
     
      for (int r = 6; r >= 1; r--) {
         if (col+myColumn<=numberOfColumnsOxford && col+myColumn>=0 ){
        processing(scrollArrayOxford[r - 1][col + myColumn], r , col);
     
         }
        // processing(ledArray[r-1][col-1], r , col);
        delay(1.8 / r);
        
      }
    
    }
  }
  }

  /*******************************************************/
  

  for (int animFrame = 1; animFrame <= 22; animFrame++) {
    //int ledArray[6][6] = {
    // {1, 1, 0, 0, 1, 1} , //03.5/5.03   03.6/6.03  03.7/7.03
    //  {1, 1, 1, 0, 0, 1} , //02.5/5.02
     // {0, 1, 0, 0, 0, 0} , //00.5/5.00
     // {0, 0, 0, 0, 1, 0} , //00.5/5.00
     // {1, 0, 0, 1, 1, 1} , //09.5/
     // {1, 1, 0, 0, 1, 1} //08.5/
    //};

 for (int frame = 1; frame <= 10; frame++) {
    for (int col = 1; col <= 6; col++) {
      reset();
     
      for (int r = 6; r >= 1; r--) {  
        processing(scrollArrayAnimation1[animFrame][r - 1][col-1], r , col);

        // processing(ledArray[r-1][col-1], r , col);
        delay(1.8 / r);
        
      }
    }
    }
  }
  

/*******************************************************/
  
  for (int myColumn = -2; myColumn <= numberOfColumnsHackspace; myColumn++) {

  for (int frame = 1; frame <= 10; frame++) {
    //int ledArray[6][6] = {
    // {1, 1, 0, 0, 1, 1} , //03.5/5.03   03.6/6.03  03.7/7.03
    //  {1, 1, 1, 0, 0, 1} , //02.5/5.02
     // {0, 1, 0, 0, 0, 0} , //00.5/5.00
     // {0, 0, 0, 0, 1, 0} , //00.5/5.00
     // {1, 0, 0, 1, 1, 1} , //09.5/
     // {1, 1, 0, 0, 1, 1} //08.5/
    //};


    for (int col = 1; col <= 6; col++) {
      reset();
     
      for (int r = 6; r >= 1; r--) {
         if (col+myColumn<=numberOfColumnsHackspace && col+myColumn>=0 ){
        processing(scrollArrayHackspace[r - 1][col + myColumn], r , col);
         }
        // processing(ledArray[r-1][col-1], r , col);
        delay(1.8 / r);
        
      }
    
    }
  }
  }

  /*******************************************************/
  


}



//void loop backet


int processing(int x, int r, int col) {

  if (col == 6) {
    pinMode(a, OUTPUT);
    if (x == 0 && r == 1) {
      pinMode(aa, OUTPUT);
      digitalWrite(a, HIGH);
      digitalWrite(aa, LOW);
    }
    if (x == 0 && r == 2 ) {
      pinMode(bb, OUTPUT);
      digitalWrite(a, HIGH);
      digitalWrite(bb, LOW);
    }
    if (x == 0 && r == 3) {
      pinMode(cc, OUTPUT);
      digitalWrite(a, HIGH);
      digitalWrite(cc, LOW);
    }
    if (x == 0 && r == 4) {
      pinMode(dd, OUTPUT);
      digitalWrite(a, HIGH);
      digitalWrite(dd, LOW);
    }
    if (x == 0 && r == 5) {
      pinMode(ee, OUTPUT);
      digitalWrite(a, HIGH);
      digitalWrite(ee, LOW);
    }
    if (x == 0 && r == 6) {
      pinMode(ff, OUTPUT);
      digitalWrite(a, HIGH);
      digitalWrite(ff, LOW);
    }
  }//end of main if loop
  /////////////////////////////////////////////////////////////////////////////////
  if (col == 5) {
    pinMode(a, OUTPUT);
    if (x == 0 && r == 1) {
      pinMode(aa, OUTPUT);
      digitalWrite(aa, HIGH);
      digitalWrite(a, LOW);
    }
    if (x == 0 && r == 2 ) {
      pinMode(bb, OUTPUT);
      digitalWrite(bb, HIGH);
      digitalWrite(a, LOW);
    }
    if (x == 0 && r == 3) {
      pinMode(cc, OUTPUT);
      digitalWrite(cc, HIGH);
      digitalWrite(a, LOW);
    }
    if (x == 0 && r == 4) {
      pinMode(dd, OUTPUT);
      digitalWrite(dd, HIGH);
      digitalWrite(a, LOW);
    }
    if (x == 0 && r == 5) {
      pinMode(ee, OUTPUT);
      digitalWrite(ee, HIGH);
      digitalWrite(a, LOW);
    }
    if (x == 0 && r == 6) {
      pinMode(ff, OUTPUT);
      digitalWrite(ff, HIGH);
      digitalWrite(a, LOW);
    }
  }//end of main if loop
  /////////////////////////////////////////////////////////////////////////////////////////////
  if (col == 4) {
    pinMode(b, OUTPUT);
    if (x == 0 && r == 1) {
      pinMode(aa, OUTPUT);
      digitalWrite(b, HIGH);
      digitalWrite(aa, LOW);
    }
    if (x == 0 && r == 2 ) {
      pinMode(bb, OUTPUT);
      digitalWrite(b, HIGH);
      digitalWrite(bb, LOW);
    }
    if (x == 0 && r == 3) {
      pinMode(cc, OUTPUT);
      digitalWrite(b, HIGH);
      digitalWrite(cc, LOW);
    }
    if (x == 0 && r == 4) {
      pinMode(dd, OUTPUT);
      digitalWrite(b, HIGH);
      digitalWrite(dd, LOW);
    }
    if (x == 0 && r == 5) {
      pinMode(ee, OUTPUT);
      digitalWrite(b, HIGH);
      digitalWrite(ee, LOW);
    }
    if (x == 0 && r == 6) {
      pinMode(ff, OUTPUT);
      digitalWrite(b, HIGH);
      digitalWrite(ff, LOW);
    }
  }//end of main if loop
  ///////////////////////////////////////////////////////////////////////////
  if (col == 3) {
    pinMode(b, OUTPUT);
    if (x == 0 && r == 1) {
      pinMode(aa, OUTPUT);
      digitalWrite(aa, HIGH);
      digitalWrite(b, LOW);
    }
    if (x == 0 && r == 2 ) {
      pinMode(bb, OUTPUT);
      digitalWrite(bb, HIGH);
      digitalWrite(b, LOW);
    }
    if (x == 0 && r == 3) {
      pinMode(cc, OUTPUT);
      digitalWrite(cc, HIGH);
      digitalWrite(b, LOW);
    }
    if (x == 0 && r == 4) {
      pinMode(dd, OUTPUT);
      digitalWrite(dd, HIGH);
      digitalWrite(b, LOW);
    }
    if (x == 0 && r == 5) {
      pinMode(ee, OUTPUT);
      digitalWrite(ee, HIGH);
      digitalWrite(b, LOW);
    }
    if (x == 0 && r == 6) {
      pinMode(ff, OUTPUT);
      digitalWrite(ff, HIGH);
      digitalWrite(b, LOW);
    }
  }//end of main if loop
  ///////////////////////////////////////////////////////////////////////////
  if (col == 2) {
    pinMode(c, OUTPUT);
    if (x == 0 && r == 1) {
      pinMode(aa, OUTPUT);
      digitalWrite(c, HIGH);
      digitalWrite(aa, LOW);
    }
    if (x == 0 && r == 2 ) {
      pinMode(bb, OUTPUT);
      digitalWrite(c, HIGH);
      digitalWrite(bb, LOW);
    }
    if (x == 0 && r == 3) {
      pinMode(cc, OUTPUT);
      digitalWrite(c, HIGH);
      digitalWrite(cc, LOW);
    }
    if (x == 0 && r == 4) {
      pinMode(dd, OUTPUT);
      digitalWrite(c, HIGH);
      digitalWrite(dd, LOW);
    }
    if (x == 0 && r == 5) {
      pinMode(ee, OUTPUT);
      digitalWrite(c, HIGH);
      digitalWrite(ee, LOW);
    }
    if (x == 0 && r == 6) {
      pinMode(ff, OUTPUT);
      digitalWrite(c, HIGH);
      digitalWrite(ff, LOW);
    }
  }//end of main if loop
  ///////////////////////////////////////////////////////////////////////////
  if (col == 1) {
    pinMode(c, OUTPUT);
    if (x == 0 && r == 1) {
      pinMode(aa, OUTPUT);
      digitalWrite(aa, HIGH);
      digitalWrite(c, LOW);
    }
    if (x == 0 && r == 2 ) {
      pinMode(bb, OUTPUT);
      digitalWrite(bb, HIGH);
      digitalWrite(c, LOW);
    }
    if (x == 0 && r == 3) {
      pinMode(cc, OUTPUT);
      digitalWrite(cc, HIGH);
      digitalWrite(c, LOW);
    }
    if (x == 0 && r == 4) {
      pinMode(dd, OUTPUT);
      digitalWrite(dd, HIGH);
      digitalWrite(c, LOW);
    }
    if (x == 0 && r == 5) {
      pinMode(ee, OUTPUT);
      digitalWrite(ee, HIGH);
      digitalWrite(c, LOW);
    }
    if (x == 0 && r == 6) {
      pinMode(ff, OUTPUT);
      digitalWrite(ff, HIGH);
      digitalWrite(c, LOW);
    }
  }//end of main if loop

}







int reset() {
  pinMode(a, INPUT);
  pinMode(b, INPUT);
  pinMode(c, INPUT);

  pinMode(aa, INPUT);
  pinMode(bb, INPUT);
  pinMode(cc, INPUT);
  pinMode(dd, INPUT);
  pinMode(ee, INPUT);
  pinMode(ff, INPUT);

}






