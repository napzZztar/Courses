void main() {
     DDRB = 0x01;
     
     while(1){
              PORTB = 0x01;
              Delay_ms(1000);
              
              PORTB = 0x00;
              Delay_ms(1000);
     }
}
