#line 1 "D:/The-A-Team/AVR/LED3.c"
void allOff();

void main() {
 DDRA = 0x02;
 DDRB = 0x04;
 DDRC = 0X08;
 DDRD = 0X16;

 while(1){
 PORTA = 0x02;
 Delay_ms(1000);
 allOff();
 Delay_ms(500);
 PORTB = 0x04;
 Delay_ms(1000);
 allOff();
 Delay_ms(500);
 PORTC = 0x08;
 Delay_ms(1000);
 allOff();
 Delay_ms(500);
 PORTD = 0x16;
 Delay_ms(1000);
 allOff();
 Delay_ms(500);
 }
}

void allOff(){
 PORTA = 0x00;
 PORTB = 0x00;
 PORTC = 0x00;
 PORTD = 0x00;
}
