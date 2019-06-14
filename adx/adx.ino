 // analog input pin 5 -- voltage
const int xpin = A0;                  // x-axis of the accelerometer1
const int ypin = A1;                  // y-axis
const int zpin = A2;                  // z-axis (only on 3-axis models) 

const int xpin1 = A3;                  // x-axis of the accelerometer2
const int ypin1 = A4;                  // y-axis
const int zpin1 = A5;                  // z-axis (only on 3-axis models)


void setup() {
  // initialize the serial communications:
  Serial.begin(9600);

  pinMode(8, OUTPUT); // left led
  pinMode(9, OUTPUT); // front white led
  pinMode(10,OUTPUT); // back red led
  pinMode(11,OUTPUT); // right led
}

void loop() {

  int   difference = map(difference,0, 1023, 10, 179) ; //nominl change in sensor value and detection
  blinky();

  int oldxpin = analogRead(xpin);
  int oldypin = analogRead(ypin);
  int oldzpin = analogRead(zpin);
  int oldxpin1 = analogRead(xpin1);
  int oldypin1 = analogRead(ypin1);
  int oldzpin1 = analogRead(zpin1);
  delay(100);
  int currxpin = analogRead(xpin);
  int currypin = analogRead(ypin);
  int currzpin = analogRead(zpin);
  int currxpin1 = analogRead(xpin1);
  int currypin1 = analogRead(ypin1);
  int currzpin1 = analogRead(zpin1);
  // print the sensor values:
  if((currxpin-oldxpin)>=difference)
  Serial.print(analogRead(xpin));
  else
  Serial.print("null");
  // print a tab between values:
  Serial.print("\t");

  if((currypin-oldypin)>=difference)
  Serial.print(analogRead(ypin));
  else
  Serial.print("null");
  // print a tab between values:
  Serial.print("\t");

  if((currzpin-oldzpin)>=difference)
  Serial.print(analogRead(zpin));
  else
  Serial.print("null");

  Serial.print("\t");

  if((currxpin1-oldxpin1)>=difference)
  Serial.print(analogRead(xpin1));
  else
  Serial.print("null");
  // print a tab between values:
  Serial.print("\t");

  if((currypin1-oldypin1)>=difference)
  Serial.print(analogRead(ypin1));
  else
  Serial.print("null");
  // print a tab between values:
  Serial.print("\t");

  if((currzpin1-oldzpin1)>=difference)
  Serial.print(analogRead(zpin1));
  else
  Serial.print("null");

  if(currxpin-oldxpin>=difference || currypin-oldypin>=difference || currzpin-oldzpin>=difference)
  {
    Serial.println("flaggggggg");
    digitalWrite(10,LOW);
    digitalWrite(8,HIGH);
    delay(100);
    digitalWrite(8,LOW);
    delay(100);
  }
  else 
  digitalWrite(8,LOW);


  

   if(currxpin1-oldxpin1>=difference || currypin1-oldypin1>=difference || currzpin1-oldzpin1>=difference)
  {
    Serial.println("flaggggggg2");
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
    delay(100);
    digitalWrite(11,LOW);
    delay(100);
  }
  else 
  digitalWrite(11,LOW);

  
    
  Serial.println();
  // delay before next reading:
  delay(100);
}



void blinky()
{
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
  delay(100);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  delay(100);
  
}

