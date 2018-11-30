#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000
#define BAUDRATE 9600
#define UBRRVAL ((F_CPU/(BAUDRATE*16UL))-1)
volatile uint8_t t =1;
void transmit(volatile uint8_t t)
{
  while(!(UCSR0A)&(1<<UDRE0));
  UDR0=t;
  
}
ISR(USART_RX_vect)
{
   
   t=UDR0;
  
   PORTB^=(1<<PB5);
  
 Serial.println(t,BIN);
   
 }



int main()
{
  
  //sei();
  UBRR0H=(UBRRVAL>>8);
  UBRR0L=UBRRVAL;
  DDRB=255;
  UCSR0B|=(1<<RXCIE0)|(1<<RXEN0)|(1<<TXEN0);// Enable receive interrupt, Enable RX and TX
  UCSR0C|=(1<<UCSZ01)|(1<<UCSZ00);
 
  
  while(1)
  {
    transmit(t);
  }
  
 return 0;
}

