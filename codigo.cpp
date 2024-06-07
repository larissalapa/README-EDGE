#include <LiquidCrystal.h>

// Pinos de controle dos Motores
constexpr int motorPins[] = {13, 12, 11, 10, 9};

// Pinos do sensor de temperatura e potenciômetro
constexpr int tempPin = A1;
constexpr int phPin = A0;

// Configuração do LCD
LiquidCrystal lcd(8, 7, 6, 5, 4, 3);

// Intervalos de tempo
constexpr unsigned long sampleInterval = 2000; // Intervalo para atualização de leituras
constexpr unsigned long collectionInterval = 10000; // Intervalo de 10 segundos para iniciar a coleta
constexpr unsigned long motorDuration = 5000; // Duração de ativação de cada motor

// Variáveis de controle de tempo
unsigned long previousMillis = 0;
unsigned long collectionStartMillis = 0;
unsigned long motorStartMillis = 0;
int currentMotor = 0;
bool isCollecting = false;

void initializePins() {
  for (int pin : motorPins) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
  }
}

void initializeLCD() {
  lcd.begin(16, 2);
  lcd.print("Iniciando...");
  delay(2000);
  lcd.clear();
}

float readTemperature() {
  int tempReading = analogRead(tempPin);
  float voltage = tempReading * (5.0 / 1023.0);
  return (voltage - 0.5) * 100.0;
}

float readPH() {
  int phValue = analogRead(phPin);
  return static_cast<float>(phValue) * 14.0 / 1023.0;
}

void updateDisplay(float temperature, float ph) {
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" C  ");
  lcd.setCursor(0, 1);
  lcd.print("pH: ");
  lcd.print(ph);
  lcd.print("    ");
}

void activateMotor(int motorIndex) {
  digitalWrite(motorPins[motorIndex], HIGH);
  delay(motorDuration);
  digitalWrite(motorPins[motorIndex], LOW);
}

void setup() {
  initializePins();
  initializeLCD();
  collectionStartMillis = millis();
}

void updateSensors(unsigned long currentMillis) {
  if (currentMillis - previousMillis < sampleInterval) return;

  previousMillis = currentMillis;
  float temperature = readTemperature();
  float ph = readPH();
  updateDisplay(temperature, ph);
}

void startCollection(unsigned long currentMillis) {
  if (isCollecting || (currentMillis - collectionStartMillis < collectionInterval)) return;

  isCollecting = true;
  motorStartMillis = currentMillis;
  currentMotor = 0;
}

void collectData(unsigned long currentMillis) {
  if (!isCollecting) return;

  lcd.setCursor(0, 0);
  lcd.print("Coletando...     ");

  if (currentMotor >= 5) {
    lcd.setCursor(0, 0);
    lcd.print("Coleta finalizada");
    delay(2000);
    lcd.clear();
    isCollecting = false;
    collectionStartMillis = currentMillis; // Reinicia o tempo de coleta
    return;
  }

  if (currentMillis - motorStartMillis >= motorDuration || currentMotor == 0) {
    motorStartMillis = currentMillis;
    activateMotor(currentMotor);
    currentMotor++;
  }
}

void loop() {
  unsigned long currentMillis = millis();
  updateSensors(currentMillis);
  startCollection(currentMillis);
  collectData(currentMillis);
}
