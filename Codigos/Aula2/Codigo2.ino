char i;

void setup() {
  // put your setup code here, to run once:
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()){
    int leitura_byte = Serial.read();



    if(leitura_byte == 65){
      funcao1();
    }

    if(leitura_byte == 66){
      funcao2();
    }

    if(leitura_byte == 67){
      funcao3();
    }

  }
}

char funcao1(){
  digitalWrite(11, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  char caractere = 'A';
  return caractere;
}

char funcao2(){
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(13, LOW);
  char caractere = 'B';
  return caractere;
}

char funcao3(){
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);
  char caractere = 'C';
  return caractere;
}