
// avr-libc library includes
#include <avr/io.h>
#include <avr/interrupt.h>
const int ypin = A2;                  // y-axis
const int ypin1 = A3;
volatile float a = 0;
volatile float b = 0;
volatile int flag;
volatile int flag1;

void setup() {
  // initialize the serial communications:
  Serial.begin(115200);


  int k;
  for (k = 3; k < 11; k++)
  {
    pinMode(k, OUTPUT);
  }

  // initialize Timer1
  cli();          // disable global interrupts
  TCCR1A = 0;     // set entire TCCR1A register to 0
  TCCR1B = 0;     // same for TCCR1B

  // set compare match register to desired timer count:
  OCR1A = 15624 / 1000;
  // turn on CTC mode:
  TCCR1B |= (1 << WGM12);
  // Set CS10 and CS12 bits for 1024 prescaler:
  TCCR1B |= (1 << CS10);
  TCCR1B |= (1 << CS12);
  // enable timer compare interrupt:
  TIMSK1 |= (1 << OCIE1A);
  sei();          // enable global interrupts


}

void loop()
{

  float y = analogRead(ypin) - 350;
  y = (y * 9.8) / 75;
  float y1 = analogRead(ypin1) - 350;
  y1 = (y1 * 9.8) / 75;

  Serial.print(y);
  Serial.print("\t");
  Serial.print((y1));
  Serial.print("\t");
  Serial.print("\n");
  a = y1;
  b = y;


  righton();
  lefton();

}



void gesture()
{
  if (b < -2.5)
    flag = 0;
  else
    flag = 1;
}


void gesture2()
{
  if (a < -2.5)
    flag1 = 0;
  else
    flag1 = 1;
}

ISR(TIMER1_COMPA_vect)
{
  gesture();
  gesture2();
}


void lefton()
{
  if (flag == 0 && flag1 == 1)
  {
    int j = 3;
    int i = 0;
    for (i = 0; i < 5; i++)
    {
      for (j = 3; j < 8; j++)
      {
        digitalWrite(j, HIGH);
        delay(50);
        digitalWrite(j, LOW);
        delay(50);
      }
    }
  }
}


void righton()
{
  if (flag == 1 && flag1 == 0)
  {
    int i = 0;
    for (i = 0; i < 5; i++)
    {
      int j = 8;
      for (j = 8; j < 12; j++)
      {
        digitalWrite(j, HIGH);
        delay(50);
        digitalWrite(j, LOW);
        delay(50);
      }
    }
  }
}


