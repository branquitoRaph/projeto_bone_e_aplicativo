bool cooldown = false; 
float temp_sensor = 0.0;
int tempo_ativo = 4000;
int tempo_espera = 25000;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, OUTPUT);
}

void loop() {
  temp_sensor = map(((analogRead(0) - 20) * 3.04), 0, 1023, -40, 125);
  printTemperatura();
  if (cooldown == true){
    for (int i = 0; i < (tempo_espera / 500); i++){
      temp_sensor = map(((analogRead(0) - 20) * 3.04), 0, 1023, -40, 125);
      printTemperatura();
      delay(1000);
    }
    cooldown = false;
  }
  if (temp_sensor > 34.0 && cooldown == false){
    LigarRele();
  }
  delay(1000);
}

void LigarRele(){
  Serial.println("R E F R E S C A N D O!");
  digitalWrite(2,HIGH);
  delay(tempo_ativo);
  digitalWrite(2,LOW);
  cooldown = true;
  Serial.println("Interrompendo a refrescagem.");
}

void printTemperatura(){
  Serial.print("Temp:");
  Serial.print(temp_sensor);
  Serial.println("°C");
}