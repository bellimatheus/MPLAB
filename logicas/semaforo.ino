int contagem = 0;
int estLed = 0;
int btn = 2;
int led = 10;


void setup() {
  // put your setup code here, to run once:
  pinMode(btn, INPUT);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  

  Serial.begin(9600);
}

void loop() {    
    if (digitalRead (btn) == 1 && estLed == 0 && contagem == 0){
      digitalWrite(led, HIGH), ++contagem, estLed = 1;
    }
    if (digitalRead (btn) == 0 && estLed == 1 && contagem == 1){
      ++contagem;
    }
    if (digitalRead (btn) == 1 && estLed == 1 && contagem == 2){
      digitalWrite(led, LOW), ++contagem, estLed = 0;
    }
    if (digitalRead (btn) == 0 && estLed == 0 && contagem == 3){
      contagem = 0;
    }
    Serial.print("Contador = ");
      Serial.println(contagem);
}

