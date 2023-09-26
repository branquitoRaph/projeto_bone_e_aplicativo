int ldr = 14;
int LM35 = 15;
int temp, lum; 

void setup() {
pinMode(ldr, INPUT);
pinMode(LM35, INPUT);
Serial.begin(9600);
}

void loop() {
  lum = analogRead(ldr);
  temp = analogRead(LM35)*0.48828125;
  Serial.println(String(lum) + "-" + String(temp));
  delay(5000);
}
