//first led light
#define LED 13
#define LED1 12
#define LED2 11
#define LED3 10
#define LED4 9
#define LED5 8
#define LED6 7
#define LED7 6
void setup() {
 pinMode(LED, OUTPUT); 
  Serial.begin(115200);  
}


double Thermister(int RawADC) { 
 double Temp;
 Temp = log(((10240000/RawADC) - 10000));
 Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
 Temp = Temp - 273.15;         
 Temp = (Temp * 9.0)/ 5.0 + 32.0; 
 return Temp;
}

void loop() {
  
//  int val;               
//  val=analogRead(0);      
//  Serial.println(val);    
//  delay(1000);          
  
  int val;             
  double temp;         
  val=analogRead(0);      
  temp=Thermister(val);   
  Serial.println(temp);   
  
  digitalWrite(LED, HIGH);
  delay(100);
  digitalWrite(LED1, HIGH);
  digitalWrite(LED, LOW);
  delay(100);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED1, LOW);
    delay(100);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED2, LOW);
    delay(100);
  digitalWrite(LED4, HIGH);
  digitalWrite(LED3, LOW);
   delay(100);
  digitalWrite(LED5, HIGH);
  digitalWrite(LED4, LOW); 
   delay(100);
  digitalWrite(LED6, HIGH);
  digitalWrite(LED5, LOW);
    delay(100);
  digitalWrite(LED7, HIGH);
  digitalWrite(LED6, LOW);
    delay(100);
  digitalWrite(LED7, LOW);
  
// int x = 1000;
// int z = -10;
// while(1) {
// if (x = 50) {
//   z = 10;
// }
// digitalWrite(LED, HIGH);
// delay(x);
// digitalWrite(LED, LOW);
// delay(750);
// x += z;
//}
}
