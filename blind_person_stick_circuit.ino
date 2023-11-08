//Smart Stick for Blind People Using Arduino UNO and Ultrasonic Sensor
/*
    serial.begin()---> when you want to output some information from your arduino to your computer screen..
    9600 ---> baud rate (default value)..
*/

int trigger_pin = 9;   //trigger pin defined at 9th pin on arduino
int echo_pin = 11;  //echo pin defined at 11th pin on arduino
int buzzer_pin = 12; //buzzer pin defined at 13th pin on arduino
//int vibrator_pin = 12;
int led_pin=13;
int time;
int distance; 
void setup() 
{
        Serial.begin (9600); 
        pinMode (trigger_pin, OUTPUT); 
        pinMode (echo_pin, INPUT);
        pinMode (buzzer_pin, OUTPUT);
       // pinMode (vibrator_pin,OUTPUT);
        pinMode (led_pin,OUTPUT);
}
void loop() 
{
    digitalWrite (trigger_pin, HIGH);
    delayMicroseconds (10);
    digitalWrite (trigger_pin, LOW);
    time = pulseIn (echo_pin, HIGH);
    distance = (time * 0.034) / 2;

  if (distance <= 20) 
        {
        Serial.println (" Object is near ");
        Serial.print (" Distance= ");              
        Serial.println (distance);        
        digitalWrite (buzzer_pin, HIGH);
        //digitalWrite (vibrator_pin,HIGH);
        digitalWrite (led_pin,HIGH);
        delay (500);
        }
  else {
        Serial.println (" object is far ");
        Serial.print (" Distance= ");              
        Serial.println (distance);        
        digitalWrite (buzzer_pin, LOW);
       // digitalWrite (vibrator_pin,LOW);
        digitalWrite (led_pin,LOW);
        delay (100);        
       } 
}
