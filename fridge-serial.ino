#define CPU_DIV (4) /* How many times slower the Arduino clone is than a normal one. */
#define TEMPERATURE_PIN (A1) /* Pin the temperature sensor is connected to. */
#define TARGET (760.5)
#define HALF_SWING (0.25) /* 760.25 hottest, 760.75 coldest */
#define RELAY_PIN (2)

enum states {
  FRIDGE_ON = HIGH,
  FRIDGE_OFF = LOW
};

double avg;
int state = FRIDGE_OFF;

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  analogReference(INTERNAL); // Analog range is 0-1.1 volts
  Serial.begin(38400);
  avg = ((double)analogRead(TEMPERATURE_PIN)) / 4.0;
}

void loop() {
  avg = ((double)0.999) * avg + ((double)0.001) * ((double)analogRead(TEMPERATURE_PIN)) / 4.0;
  Serial.println(avg);
  if (avg > TARGET + HALF_SWING) {
    state = FRIDGE_OFF;
  } else if (avg < TARGET - HALF_SWING) {
    state = FRIDGE_ON;
  }
  digitalWrite(RELAY_PIN, state);
  digitalWrite(LED_BUILTIN, state);
  delay(1);
}
