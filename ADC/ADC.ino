#include <avr/io.h>
#include <avr/interrupt.h>

ISR(ADC_vect)
{
  
  if (ADCH>128)
  {
    PORTB=255;
  }
  else
  {
    PORTB=0;
  }
}

int main()
{
  
  DDRB=255;
  sei();
  ADMUX|=(1<<REFS0)|  (1<<ADLAR); // SET REF TO AREF, LEFT SHIFT, MUX SELECTION
  ADCSRA|=(1<<ADEN)|(1<<ADSC)|(1<<ADATE)|(1<<ADIE)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);//ENABLE ADC,START CONVERSION,ENALE AUTO TRIGGER,ENABLE INTERRUPT, SET PRESCALER TO 128 F_ADC=F_CPU/PRESCALER
  Serial.begin(9600);
  while(1)
  {
    Serial.println(ADCH);
  }
  return 0;
  
}

