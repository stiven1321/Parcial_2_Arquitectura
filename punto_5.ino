#include <TimerOne.h>

byte ValueD;
byte secu [20];
int n;
volatile int ContarTiempo;

void setup() {

  ContarTiempo = 0;

  Timer1.initialize(1000000);
  Timer1.attachInterrupt(IniSecuencia);
  //Botones en pine 2, 3, 4 puerto D
  DDRD = B00000011;
  
  // puerto B 7, 6
  DDRB = B11111111;

  n = 0;
  
}

void loop() {
  ValueD = PIND; //leer pines de los botones
  PORTB = ValueD; //encender el led
  if (ValueD != 0){ // validar si no esta vacia la secuencia de pulsaciones
    ContarTiempo = 0;
   if (n < 20){ // valida que la secuencia no se mayor que el tamano del array
    secu [n] = ValueD;
    n++;
   }
   while (PIND != 0); // ejecuta el loop hasta que se presione el boton
  }
  if (ContarTiempo == 3){
     for (int i=0; i<n; i++){
      PORTB = secu[i];
      delay(2000);
      PORTB = 0;
      delay(1000);
     }
     n = 0;
  }
}

void IniSecuencia(){
  ContarTiempo++;
}