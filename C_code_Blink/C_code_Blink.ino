#include <avr/io.h>
#include <avr/interrupt.h>
// CTC mode with ISR and Auto toggle on OC0A and OC0B
ISR (TIMER0_COMPA_vect)
{
  PORTB^=255;
}

int main(void)
{sei();
  DDRB=255;
  DDRD=255;
  
  TCNT0=0;
TCCR0A|=0b01010010; //enable CTC and toggle OC0A pin6 on uno OC0B pin 5
TCCR0B|=0b00000001; //prescaler set to 1024

OCR0A=20; // set the upper limit for CTC
TIMSK0|=0b00000010; //enable interrupt for CTC

while(1)
{
  
}
  return 0;
}

