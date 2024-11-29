#include <HX711.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

HX711 scale;
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int motorPin = 4;  // Pino para o motor
const int buttonPin = 5; // Botão de controle

void setup() {
  pinMode(motorPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  
  scale.begin(A1, A0);  // Pinos de dados e clock do HX711
  lcd.begin(16, 2);
  lcd.print("Comedouro");
}

void loop() {
  if(digitalRead(buttonPin) == HIGH) {
    digitalWrite(motorPin, HIGH); // Aciona o motor para liberar ração
    delay(5000);  // Motor ligado por 5 segundos
    digitalWrite(motorPin, LOW);  // Desliga o motor
  }
  
  float weight = scale.get_units(10);  // Lê o peso
  lcd.setCursor(0, 1);
  lcd.print("Peso: ");
  lcd.print(weight);
  delay(1000);
}
