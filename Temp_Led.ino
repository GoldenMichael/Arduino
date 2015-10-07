#include <math.h>         //loads the more advanced math functions
const int redPin = 11;
const int greenPin = 10;
const int bluePin = 9;
void setup() {            //This function gets called when the Arduino starts
  Serial.begin(9600);   //This code sets up the Serial port at 115200 baud rate
  setColourRgb(0,0,0);
}
 
double Thermister(int RawADC) {  //Function to perform the fancy math of the Steinhart-Hart equation
 double Temp;
 Temp = log(((10240000/RawADC) - 10000));
 Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
 Temp = Temp - 273.15;              // Convert Kelvin to Celsius
 Temp = (Temp * 9.0)/ 5.0 + 32.0; // Celsius to Fahrenheit - comment out this line if you need Celsius
 return Temp;
}
 int time = 0;
void loop() {             //This function loops while the arduino is powered
  int val;                //Create an integer variable
  double temp;            //Variable to hold a temperature value
  val=analogRead(0);      //Read the analog port 0 and store the value in val
  temp=Thermister(val);  //Runs the fancy math on the raw analog value
  if ( time >= 60) {
  Serial.println(temp);   //Print the value to the serial port
  time = 0;
  }
  delay(1000);    //Wait one second before we do it again
  time++;
  if ( temp > 86) {
     setColourRgb(255,14,240); 
  }
  else if (temp < 86 && temp > 84) {
      setColourRgb(255,7,240);
  }
  else if (temp < 84 && temp > 83) {
     setColourRgb(255,0,192);
  }
  else if (temp < 83 && temp > 82) {
     setColourRgb(255,0,96);
  }
  else if (temp < 82 && temp > 81) {
     setColourRgb(255,0,0);
  }
  else if (temp < 81 && temp > 80) {
     setColourRgb(255,40,0);
  }
  else if (temp < 80 && temp > 79) {
     setColourRgb(255,80,0);
  }
  else if (temp < 79 && temp > 78) {
     setColourRgb(255,120,0);
  }
  else if (temp < 78 && temp > 77) {
     setColourRgb(255,170,0);
  }
  else if (temp < 77 && temp > 76) {
     setColourRgb(255,210,0);
  }
  else if (temp < 76 && temp > 75) {
     setColourRgb(255,250,0);
  }
  else if (temp < 75 && temp > 74) {
     setColourRgb(255,250,0);
  }
  else if (temp < 74 && temp > 73) {
     setColourRgb(62,255,0);
  }
  else if (temp < 73 && temp > 72) {
     setColourRgb(0,255,92);
  }
  else if (temp < 72 && temp > 71) {
     setColourRgb(0,255,208);
  }
  else if (temp < 71 && temp > 69) {
     setColourRgb(0,132,255);
  }
  else if (temp < 69 && temp > 67) {
     setColourRgb(0,50,255);
  }
  else if (temp < 67) {
     setColourRgb(5,0,255);
  }
}

void setColourRgb(unsigned int blue, unsigned int green, unsigned int red) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
 }
