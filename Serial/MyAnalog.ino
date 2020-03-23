//Hrimpic 2020


const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 11; // Analog output pin that the LED is attached to

int sensorValue = 0;        // value read from the pot       // value output to the PWM (analog out)

void setup()
{
  Serial.begin(9600);
  pinMode(13, INPUT);
}

void loop()
{
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  // print the results to the Serial Monitor:
  Serial.print((float)sensorValue/1023*5.0, 3);
  Serial.println();

 // Serial.println(outputValue);

  
  delay(200);
}

void serialEvent()
{
    while(Serial.available())
    {
    int a = Serial.read();
    //Serial.println(a);
    analogWrite(analogOutPin, a);
    }
}
