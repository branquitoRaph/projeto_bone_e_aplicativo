unsigned long tempo;
int botao1 = 6;
int botao2 = 7;
int botao3 = 8;
int botao4 = 9;
int delta1 = 0;
int delta2 = 0;
int delta3 = 0;
int valorbotao1 = 0;
int valorbotao2 = 0;
int valorbotao3 = 0;
int valorbotao4 = 0;
unsigned long t_botao1 = 0;
unsigned long t_botao2 = 0;
unsigned long t_botao3 = 0;
unsigned long t_botao4 = 0;

void setup() {
pinMode(botao1, INPUT);
pinMode(botao2, INPUT);
pinMode(botao3, INPUT);
pinMode(botao4, INPUT);
Serial.begin(9600);
}

void loop() {
  tempo = millis();
  
  valorbotao1 = digitalRead(botao1);
  if (valorbotao1 == 1){
    t_botao1 = millis();
    while (valorbotao1 == 1){
      valorbotao1 = digitalRead(botao1);
    }
    Serial.print("botão 1: ");
    Serial.println(t_botao1);
  }
  
  valorbotao2 = digitalRead(botao2);
  if (valorbotao2 == 1){
    t_botao2 = millis();
    while (valorbotao2 == 1){
      valorbotao2 = digitalRead(botao2);
    }
    Serial.print("botão 2: ");
    Serial.println(t_botao2);
    delta1 = t_botao2 - t_botao1;
    Serial.print("Entre 1 e 2: ");
   Serial.println(delta1);
  }
  
  valorbotao3 = digitalRead(botao3);
  if (valorbotao3 == 1){
    t_botao3 = millis();
    while (valorbotao3 == 1){
      valorbotao3 = digitalRead(botao3);
    }
    Serial.print("botão 3: ");
    Serial.println(t_botao3);
    delta2 = t_botao3 - t_botao2; 
    Serial.print("Entre 2 e 3: ");
    Serial.println(delta2);
  }

  valorbotao4 = digitalRead(botao4);
  if (valorbotao4 == 1){
    t_botao4 = millis();
    while (valorbotao4 == 1){
      valorbotao4 = digitalRead(botao4);
    }
    Serial.print("botão 4: ");
    Serial.println(t_botao4);
    delta3 = t_botao4 - t_botao3;
    Serial.print("Entre 3 e 4: ");
    Serial.println(delta3);
  
  }

}
