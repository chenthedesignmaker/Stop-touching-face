#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK 2
#define DIO 3

// The amount of time (in milliseconds) between tests
#define TEST_DELAY   2000

const uint8_t SEG_DONE[] = {
  SEG_B | SEG_C | SEG_D | SEG_E | SEG_G,           // d
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,   // O
  SEG_C | SEG_E | SEG_G,                           // n
  SEG_A | SEG_D | SEG_E | SEG_F | SEG_G            // E
  };

TM1637Display display(CLK, DIO);





#define SENSOR_PIN 4
#define SENSOR_PIN2 5
#define SENSOR_PIN3 6
#define SENSOR_PIN4 7
#define MOTOR_PIN 8

int sensorReading;
int sensorReading2;
int sensorReading3;
int sensorReading4;

bool sensorState = false;
int counter;

void setup() {
  // put your setup code here, to run once:
 pinMode(SENSOR_PIN, INPUT);

  pinMode(MOTOR_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  
  display.setBrightness(0x0f);
  display.showNumberDec(counter, true);
  
  sensorReading = digitalRead(SENSOR_PIN);
  sensorReading2 = digitalRead(SENSOR_PIN2);
  sensorReading3 = digitalRead(SENSOR_PIN3);
  sensorReading4 = digitalRead(SENSOR_PIN4);
  
  if(sensorReading==LOW||sensorReading2==LOW||sensorReading3==LOW||sensorReading4==LOW){//sensor triggered
     digitalWrite(MOTOR_PIN,1);
     //delay(1000);
     if(sensorState == false){
        counter++;
        Serial.println("reading is LOW");
        display.showNumberDec(counter, true);  // Expect: 0001
        sensorState = true;
        delay(500);
      }
     
   
     Serial.println("Sensor1"+sensorReading);
     Serial.println("Sensor2"+sensorReading2);
     Serial.println("Sensor3"+sensorReading3);
     Serial.println("Sensor4"+sensorReading4);
    }
    else{
      sensorState = false;
      digitalWrite(MOTOR_PIN,0);
      Serial.println("reading is HIGH");
      }
      
}
