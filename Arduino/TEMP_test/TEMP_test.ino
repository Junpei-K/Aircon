extern "C" {
  uint8_t temprature_sens_read(); 
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.printf("Temperature(temperature_sens_read()): %d\n", temprature_sens_read());
  Serial.printf("Temperature(temperatureRead())      : %f\n", temperatureRead());

  delay(1000);
}
