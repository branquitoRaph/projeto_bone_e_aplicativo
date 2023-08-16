int led = 9;

void setup() {
  pinMode(led,OUTPUT);
}

void loop() {
    for (int brilho = 0; brilho < 254; brilho++){
    analogWrite(led, brilho);
    delay(25);
  }
  for (int brilho = 255; brilho>1; brilho--){
    analogWrite(led, brilho);
    delay(25);
  }
}