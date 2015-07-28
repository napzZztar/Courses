#line 1 "D:/The-A-Team/AVR/LED2.c"
void main() {
 DDRA = 0x55;

 while(1){
 PORTA = 0x55;
 Delay_ms(1000);

 PORTA = 0x00;
 Delay_ms(500);
 }
}
