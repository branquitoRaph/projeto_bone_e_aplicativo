#include <Wire.h>               //Biblioteca I2C
#include <SparkFunMLX90614.h>   //Biblioteca SensorInfravermelho-gy906 ||  https://github.com/wagner-rambo/arquivos/raw/master/usCom012_wr_files.rar

IRTherm therm;                  //Objeto do sensor

int rele = 2;
int tempo_espera = 180;         //Segundos
int tempo_ativo = 7;            //Segundos

float temp_ambiente, temp_objeto;
bool cooldown = false;

char comando = ' ';

void setup() {
  Serial.begin(9600);
  therm.begin();
  therm.setUnit(TEMP_C);

  pinMode(rele, OUTPUT);
  digitalWrite(rele, HIGH);
}

void loop() {
  if (Serial.available()) {
  comando = Serial.read();
    if (comando == 'L') {
      BotaoAPP();
      }
  }

  if (therm.read()) {
    temp_objeto = therm.object();
    temp_ambiente = therm.ambient();
    PrintInfo();

    if (cooldown == true){
      for (int i = 0; i < (tempo_espera); i++){

        if (Serial.available()) {
        comando = Serial.read();
          if (comando == 'L') {
          BotaoAPP();
          cooldown = false;
          break;
          }
        }

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
  delay(tempo_ativo * 1000);
  digitalWrite(rele, HIGH);
  cooldown = true;
}

void BotaoAPP(){
  digitalWrite(rele, LOW);
  delay(tempo_ativo * 1000);
  digitalWrite(rele, HIGH);
}

void PrintInfo(){
  Serial.print(String(temp_objeto) + "-" + String(temp_ambiente));
}