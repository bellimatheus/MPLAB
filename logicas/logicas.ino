
const int btn1 = 1;
const int btn2 = 2;
const int btn3 = 3;
const int saida = 9;

void setup() {

      pinMode(btn1, INPUT);
      pinMode(btn2, INPUT);
      pinMode(btn3, INPUT);
      pinMode(saida, OUTPUT);

}

void loop() {
  int estEnt1 = digitalRead(btn1);
  int estEnt2 = digitalRead(btn2);
  int estEnt3 = digitalRead(btn3);
  //int resultado = estEnt1^estEnt2; //int resultado = (estEnt1 == estEnt2)? HIGH : LOW;
  if(estEnt1 == estEnt2 && estEnt2 == estEnt3){
    digitalWrite(saida, HIGH);
  }else{
    digitalWrite(saida, LOW);
  }
  //digitalWrite(saida, resultado);
  delay(10);
;}
