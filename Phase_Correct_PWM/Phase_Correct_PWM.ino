#include <avr/io.h>
#include <avr/interrupt.h>
// Phase correct 
ISR (TIMER0_OVF_vect)
{
  PORTB^=255;
}

int main(void)
{sei();
  DDRB=255;
  DDRD=255;
  PORTD&=0<<8;
  TCNT0=0;//initialize timer to 0
TCCR0A|=0b01000011; //enable Phase correct PWM and toggle OC0A pin6 on uno
TCCR0B|=0b00001101; //prescaler set to 256
OCR0A=2;
TIMSK0|=0b00000001; //enable overflow interrupt 

while(1)
{
  
}
  return 0;
}

