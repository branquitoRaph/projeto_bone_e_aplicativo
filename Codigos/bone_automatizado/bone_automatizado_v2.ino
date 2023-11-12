#include <Wire.h>               //Biblioteca I2C
#include <SparkFunMLX90614.h>   //Biblioteca SensorInfravermelho-gy906   

IRTherm therm;                  //Objeto do sensor

int rele = 2;
int tempo_espera = 25000;
int tempo_ativo = 4000;

float temp_ambiente, temp_objeto;
bool cooldown = false;

void setup() {
  Serial.begin(9600);
  therm.begin();
  therm.setUnit(TEMP_C);

  pinMode(rele, OUTPUT);
  digitalWrite(rele, HIGH);
}

void loop() {
  if (therm.read()) {
    temp_objeto = therm.object();
    temp_ambiente = therm.ambient();
    PrintInfo();

    if (cooldown == true){
      for (int i = 0; i < (tempo_espera / 1000); i++){
        temp_objeto = therm.object();
        temp_ambiente = therm.ambient();
        PrintInfo();
        delay(1000);
      }
      cooldown = false;
    }
    if (temp_objeto > 35.0){
      LigarRele();
    }
  }
  delay(1000);
}

void LigarRele(){
  digitalWrite(rele, LOW);
  delay(tempo_ativo);
  digitalWrite(rele, HIGH);
  cooldown = true;
}

void PrintInfo(){
  Serial.println(String(temp_objeto) + "-" + String(temp_ambiente) + "-" + String(cooldown));
}