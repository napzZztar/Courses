#line 1 "D:/The-A-Team/AVR/LCD.c"









void send_command(unsigned char command)
{

  PORTD  = command;

  PORTC  &= ~(1<< 0 );

  PORTC  &= ~(1<< 1 );

  PORTC  |= 1<< 2 ;
 Delay_us(1);
  PORTC  &= ~(1<< 2 );
 Delay_us(100);
}

void send_data(unsigned char dat)
{

  PORTD  = dat;

  PORTC  |= 1<< 0 ;


  PORTC  &= ~(1<< 1 );

  PORTC  |= 1<< 2 ;
 Delay_us(1);
  PORTC  &= ~(1<< 2 );
 Delay_us(100);
}
void main( )
{

  DDRC  = 0xFF;
  DDRD  = 0xFF;
 Delay_us(2000);
 send_command(0x38) ;
 send_command(0x0E);
 send_command(0x01);
 Delay_us(2000) ;
 send_command(0x06) ;

 send_data('A');
 send_data('I');
 send_data('U');
 send_data('B');
 while(1)
 {

 }
}
