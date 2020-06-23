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





#define SENSOR_PIN 2
#define MOTOR_PIN 3

int sensorReading;

void setup() {
  // put your setup code here, to run once:
 pinMode(SENSOR_PIN, INPUT);

  pinMode(MOTOR_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  sensorReading = digitalRead(SENSOR_PIN);
  // put your main code here, to run repeatedly:
  if(sensorReading==LOW){
     digitalWrite(MOTOR_PIN,1);
     //delay(1000);
     Serial.println(sensorReading);
    }
    else{
      digitalWrite(MOTOR_PIN,0);
      Serial.println("reading is HIGH");
      }
      
}
