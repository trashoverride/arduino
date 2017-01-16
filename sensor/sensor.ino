// Programa : Sensor de temperatura DS18B20
// Autor : FILIPEFLOP
 
#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal.h>
 
// Porta do pino de sinal do DS18B20
#define ONE_WIRE_BUS 3
 
// Define uma instancia do oneWire para comunicacao com o sensor
OneWire oneWire(ONE_WIRE_BUS);
int rele = 9;
int setpoint = 28;
 
DallasTemperature sensors(&oneWire);
DeviceAddress sensor1;
 
 
void setup(void)
{
  sensors.begin();
  sensors.getAddress(sensor1, 0);
  mostra_endereco_sensor(sensor1);
  pinMode(rele, OUTPUT); 
   
}
 
void mostra_endereco_sensor(DeviceAddress deviceAddress)
{
  for (uint8_t i = 0; i < 8; i++)
  {
    // Adiciona zeros se necessário
    if (deviceAddress[i] < 16) Serial.print("0");
    Serial.print(deviceAddress[i], HEX);
  }
}
 
void loop()
{
  // Le a informacao do sensor
  sensors.requestTemperatures();
  float tempC = sensors.getTempC(sensor1);
   
  if(tempC > setpoint)
        digitalWrite(rele, LOW);   // turn the LED on (HIGH is the voltage level)
  else
        digitalWrite(rele, HIGH);   // turn the LED on (HIGH is the voltage level)
  
  delay

}
