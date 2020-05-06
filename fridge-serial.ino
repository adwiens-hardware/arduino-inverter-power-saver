#define CPU_DIV (4) /* How many times slower the Arduino clone is than a normal one. */
#define TEMPERATURE_PIN (A1) /* Pin the temperature sensor is connected to. */
#define TARGET (766)
#define SWING (2) /* 764 hottest, 768 coldest */
#define RELAY_PIN (2)

enum states {
  FRIDGE_ON = HIGH,
  FRIDGE_OFF = LOW
};

double avg;
int state = FRIDGE_OFF;

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  analogReference(INTERNAL); // Analog range is 0-1.1 volts
  Serial.begin(38400);
  avg = ((double)analogRead(TEMPERATURE_PIN)) / 4;
}

void loop() {
  avg = ((double)0.9995) * avg + ((double)0.0005) * ((double)analogRead(TEMPERATURE_PIN)) / 4;
  Serial.println(avg);
  if (state == FRIDGE_ON && avg > TARGET + SWING) {
    state = FRIDGE_OFF;
  } else if (state == FRIDGE_OFF && avg < TARGET - SWING) {
    state = FRIDGE_ON;
  }
  digitalWrite(RELAY_PIN, state);
  delay(1);
}
