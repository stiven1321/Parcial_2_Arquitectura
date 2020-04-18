void setup() {
  
  // puertos B 
  DDRB = B11111111;
  //puertos D
  //DDRD = D01111111;
  
}

void loop() {
 
  PORTB = B11111111; //encender los leds en el pueto
  delay(2000); //dura encendido 2 seg
  PORTD = B11111111; //encender los leds en el puerto D
  delay(2000); //dura encendido 2 seg
  
}