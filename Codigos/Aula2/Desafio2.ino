int leitura;

void setup() {
  pinMode(A0, INPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  leitura = analogRead(A0);
  Serial.println(leitura);

  if(leitura<250){
    aceso();
  }
  if(leitura>250 && leitura<400){
    piscar();
  }
  if(leitura>400){
    apagado();
  }
  delay(500);

}

void aceso(){
  digitalWrite(11, HIGH);
}

void apagado(){
  digitalWrite(11, LOW);
}

void piscar() {
    digitalWrite(11, HIGH);
    delay(500);
    digitalWrite(11, LOW);
    delay(500);
}
