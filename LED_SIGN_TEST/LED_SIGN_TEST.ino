#include <digitalWriteFast.h>
#define RESET 22 //RIBBON 3  
#define AEN 2 //RIBBON 9
#define IOW 24 //RIBBON 11
#define DACK1 16 //RIBBON 19

#define TC 15 //RIBBON 31
#define IOR 28 //RIBBON 13

#define CLK 12 //RIBBON 23 - Timer OC1B
#define DRQ1 26 //ribbon 21

#define data0 42 //RIBBON 16 THIS IS BACKWARDS
#define data1 43 //RIBBON 14
#define data2 44
#define data3 45
#define data4 46
#define data5 47
#define data6 48
#define data7 49 //RIBBON 2


#define address2 37  //RIBBON 30
#define address3 36
#define address4 35
#define address5 34
#define address6 33
#define address7 32
#define address8 31 //RIBBON 18
#define address9 30 //RIBBON 27




void setup() {
  // put your setup code here, to run once:


  pinModeFast(data7, OUTPUT);
  pinModeFast(data6, OUTPUT);
  pinModeFast(data5, OUTPUT);
  pinModeFast(data4, OUTPUT);
  pinModeFast(data3, OUTPUT);
  pinModeFast(data2, OUTPUT);
  pinModeFast(data1, OUTPUT);
  pinModeFast(data0, OUTPUT);


  pinModeFast(address9, OUTPUT);
  pinModeFast(address8, OUTPUT);
  pinModeFast(address7, OUTPUT);
  pinModeFast(address6, OUTPUT);
  pinModeFast(address5, OUTPUT);
  pinModeFast(address4, OUTPUT);
  pinModeFast(address3, OUTPUT);
  pinModeFast(address2, OUTPUT);

  pinModeFast(RESET, OUTPUT);
  pinModeFast(AEN, OUTPUT);
  pinModeFast(IOW, OUTPUT);
  pinModeFast(DACK1, OUTPUT);
  pinModeFast(CLK, OUTPUT);

  pinModeFast(TC, OUTPUT);
  pinModeFast(IOR, OUTPUT);
  pinModeFast(DRQ1, INPUT);


  digitalWriteFast(TC, LOW);

  digitalWriteFast(IOR, HIGH);
  digitalWriteFast(DACK1, HIGH);


  digitalWriteFast(IOW,  HIGH);
  digitalWriteFast(CLK,  LOW);
  digitalWriteFast(DACK1, HIGH);
  digitalWriteFast(AEN,  LOW);

  //TCCR1B  = (TCCR1B  & 0xF8) | 0X01 ; //SET PRESCALER TO 1 - 62.5035 KHZ
  //TCCR1A = 0x23;
  // TCCR1B = 0X09;
  // OCR1A = 3;
  // OCR1B = 1;

}

void loop() {
  clock1();
      PORTL = B10100000; //5
      clock1();
      PORTL = B11100000; //7
      clock1();
digitalWriteFast(AEN, HIGH);
  delayMicroseconds(1);
 
 digitalWriteFast(AEN, LOW);



  for (int y = 0; y < 48; y++) {


    setAddress();

    PORTL = B11110001;
    clock1();
    PORTL = B11110000;
    clock1();
    PORTL = B11100000;
    clock1();
    digitalWriteFast(AEN, HIGH);
  delayMicroseconds(1);

 digitalWriteFast(AEN, LOW);
   
      clearAddress();




    clock2();


    setAddress();
    PORTL = B10100000; //6
    clock1();
    PORTL = B11100000; //7
    clock1();
 digitalWriteFast(AEN, HIGH);
   delayMicroseconds(1);
  
 digitalWriteFast(AEN, LOW);
    clearAddress();
    //clock1();
  }

  //digitalWrite(address2, HIGH);
  //   PORTL = 0X05;
  //      clock1();
  //  PORTL = 0X07;
  //   clock1();
  // digitalWrite(address2, LOW);

}
void clock1()
{

  digitalWriteFast(IOW,  LOW);
  //digitalWriteFast(CLK,  !digitalReadFast(CLK));
  // digitalWriteFast(DACK1, !digitalReadFast(DACK1));
  //digitalWriteFast(AEN,  !digitalReadFast(AEN));
  delayMicroseconds(1);

  digitalWriteFast(IOW, HIGH);
  //digitalWriteFast(CLK,  !digitalReadFast(CLK));
  //digitalWriteFast(DACK1, !digitalReadFast(DACK1));
  //digitalWriteFast(AEN,  !digitalReadFast(AEN));
  //  PORTL = 0XFF;
  //delay(1);

}

void clock2()
{
//setAddress();
  for (int x = 0; x < 32; x++) {
    digitalWriteFast(CLK, LOW);

    digitalWriteFast(CLK, HIGH);

    digitalWriteFast(AEN, LOW);
    delayMicroseconds(1);
        clearAddress();
            while (digitalRead (DRQ1) == LOW) {}
    digitalWriteFast(AEN, HIGH);
    digitalWriteFast(CLK, LOW);

   
    digitalWriteFast(CLK, HIGH);

     digitalWriteFast(CLK, LOW);
      
    digitalWriteFast(DACK1, LOW);
    digitalWriteFast(CLK, HIGH);

    digitalWriteFast(CLK, LOW);



    PORTL = B11110000;
//PORTL = B11111111;
        digitalWriteFast(CLK, HIGH);
      
    digitalWriteFast(IOW, LOW);
 
    if (x == 31) {
      digitalWriteFast(TC, HIGH);
    }

    digitalWriteFast(CLK, LOW);
    digitalWriteFast(CLK, HIGH);
    digitalWriteFast(IOW, HIGH);
    digitalWriteFast(TC, LOW);
    digitalWriteFast(DACK1, HIGH);
   
        digitalWriteFast(AEN, LOW);
                 PORTL = B11111000;
   //clearAddress();
  }
}

void setAddress() {
  digitalWriteFast(address9, HIGH);
  digitalWriteFast(address8, LOW);
  digitalWriteFast(address7, HIGH);
  digitalWriteFast(address6, HIGH);
  digitalWriteFast(address5, HIGH);
  digitalWriteFast(address4, HIGH);
  digitalWriteFast(address3, LOW);
  digitalWriteFast(address2, LOW);
}

void clearAddress()
{ digitalWriteFast(address9, LOW);
  digitalWriteFast(address8, HIGH);
  digitalWriteFast(address7, LOW);
  digitalWriteFast(address6, LOW);
  digitalWriteFast(address5, LOW);
  digitalWriteFast(address4, LOW);
  digitalWriteFast(address3, HIGH);
  digitalWriteFast(address2, HIGH);

}
