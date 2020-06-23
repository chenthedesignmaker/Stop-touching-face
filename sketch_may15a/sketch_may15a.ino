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
