bool cooldown = false; 
float temp_sensor = 0.0;
int tempo_ativo = 3000;
int tempo_espera = 20000;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, OUTPUT);


}

void loop() {
  temp_sensor = (analogRead(0) * (5.0/1023)) / 0.01;
  printTemperatura();
  if (cooldown == true){
    for (int i = 0; i < (tempo_espera / 100); i++){
      temp_sensor = (analogRead(0) * (5.0/1023)) / 0.01;
      printTemperatura();
      delay(100);
    }
    cooldown = false;
  }
  if (temp_sensor > 34.0 && cooldown == false){
    LigarRele();
  }
  delay(100);
}

char LigarRele(){
  Serial.print("R E F R E S C A N D O!");
  digitalWrite(2,HIGH);
  delay(tempo_ativo);
  digitalWrite(2,LOW);
  cooldown = true;
  Serial.print("Interrompendo a refrescagem.");
}

char printTemperatura(){
  Serial.print("Temp:");
  Serial.print(temp_sensor);
  Serial.println("°C");
}