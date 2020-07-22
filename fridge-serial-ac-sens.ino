#define CPU_DIV (4) /* How many times slower the Arduino clone is than a normal one. */
#define RELAY_PIN (2)
#define AC_SENS_PIN (3)
#define INVERTER_DELAY (8 * 1000 / CPU_DIV)
#define LOOP_DELAY (500 / CPU_DIV)
#define SLEEP_DELAY (5UL * 60 * 1000 / CPU_DIV)

enum states {
  INVERTER_ON = HIGH,
  INVERTER_OFF = LOW
};

volatile bool fridgeIsOn = false;
bool ledOn = false;

void ac_sens_isr() {
  fridgeIsOn = true;
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(AC_SENS_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(AC_SENS_PIN), ac_sens_isr, CHANGE);
  Serial.begin(38400);
  Serial.println("ON");
}

void loop() {
  Serial.println("CHECKING IF FRIDGE NEEDS TO RUN");
  digitalWrite(RELAY_PIN, INVERTER_ON);
  fridgeIsOn = false;
  delay(INVERTER_DELAY);
  if (fridgeIsOn) {
    Serial.println("DETECTED FRIDGE ON. KEEPING INVERTER ON UNTIL FRIDGE TURNS OFF.");
  }
  while(fridgeIsOn) {
    digitalWrite(LED_BUILTIN, ledOn ? HIGH : LOW);
    ledOn = !ledOn;
    fridgeIsOn = false;
    delay(LOOP_DELAY);
  }
  Serial.println("DETECTED FRIDGE OFF. TURNING OFF INVERTER & WAITING 5 MINS");
  digitalWrite(RELAY_PIN, INVERTER_OFF);
  delay(SLEEP_DELAY);
}
