#include <avr/io.h>
#include <avr/interrupt.h>


int main(void){
  
  DDRB=255;
  DDRD=255;
  
  TCCR0A|=0b11000011; //enable Fast PWM and invert output at OC0A and OC0B pin6 and 5 on uno
  TCCR0B|=0b00000100; //prescaler set to 1024
  OCR0A=20;
 
  TCNT0=0;//initialize timer to 0
  

  return 0;
}

