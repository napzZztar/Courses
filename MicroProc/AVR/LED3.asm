
_main:
	LDI        27, 255
	OUT        93, 27
	LDI        27, 0
	OUT        94, 27

;LED3.c,3 :: 		void main() {
;LED3.c,4 :: 		DDRA = 0x02;
	LDI        27, 2
	OUT        DDRA+0, 27
;LED3.c,5 :: 		DDRB = 0x04;
	LDI        27, 4
	OUT        DDRB+0, 27
;LED3.c,6 :: 		DDRC = 0X08;
	LDI        27, 8
	OUT        DDRC+0, 27
;LED3.c,7 :: 		DDRD = 0X16;
	LDI        27, 22
	OUT        DDRD+0, 27
;LED3.c,9 :: 		while(1){
L_main0:
;LED3.c,10 :: 		PORTA = 0x02;
	LDI        27, 2
	OUT        PORTA+0, 27
;LED3.c,11 :: 		Delay_ms(1000);
	LDI        18, 41
	LDI        17, 150
	LDI        16, 128
	DEC        16
	BRNE       $-1
	DEC        17
	BRNE       $-3
	DEC        18
	BRNE       $-5
;LED3.c,12 :: 		allOff();
	CALL       _allOff+0
;LED3.c,13 :: 		Delay_ms(500);
	LDI        18, 21
	LDI        17, 75
	LDI        16, 191
	DEC        16
	BRNE       $-1
	DEC        17
	BRNE       $-3
	DEC        18
	BRNE       $-5
	NOP
;LED3.c,14 :: 		PORTB = 0x04;
	LDI        27, 4
	OUT        PORTB+0, 27
;LED3.c,15 :: 		Delay_ms(1000);
	LDI        18, 41
	LDI        17, 150
	LDI        16, 128
	DEC        16
	BRNE       $-1
	DEC        17
	BRNE       $-3
	DEC        18
	BRNE       $-5
;LED3.c,16 :: 		allOff();
	CALL       _allOff+0
;LED3.c,17 :: 		Delay_ms(500);
	LDI        18, 21
	LDI        17, 75
	LDI        16, 191
	DEC        16
	BRNE       $-1
	DEC        17
	BRNE       $-3
	DEC        18
	BRNE       $-5
	NOP
;LED3.c,18 :: 		PORTC = 0x08;
	LDI        27, 8
	OUT        PORTC+0, 27
;LED3.c,19 :: 		Delay_ms(1000);
	LDI        18, 41
	LDI        17, 150
	LDI        16, 128
	DEC        16
	BRNE       $-1
	DEC        17
	BRNE       $-3
	DEC        18
	BRNE       $-5
;LED3.c,20 :: 		allOff();
	CALL       _allOff+0
;LED3.c,21 :: 		Delay_ms(500);
	LDI        18, 21
	LDI        17, 75
	LDI        16, 191
	DEC        16
	BRNE       $-1
	DEC        17
	BRNE       $-3
	DEC        18
	BRNE       $-5
	NOP
;LED3.c,22 :: 		PORTD = 0x16;
	LDI        27, 22
	OUT        PORTD+0, 27
;LED3.c,23 :: 		Delay_ms(1000);
	LDI        18, 41
	LDI        17, 150
	LDI        16, 128
	DEC        16
	BRNE       $-1
	DEC        17
	BRNE       $-3
	DEC        18
	BRNE       $-5
;LED3.c,24 :: 		allOff();
	CALL       _allOff+0
;LED3.c,25 :: 		Delay_ms(500);
	LDI        18, 21
	LDI        17, 75
	LDI        16, 191
	DEC        16
	BRNE       $-1
	DEC        17
	BRNE       $-3
	DEC        18
	BRNE       $-5
	NOP
;LED3.c,26 :: 		}
	JMP        L_main0
;LED3.c,27 :: 		}
L_end_main:
	JMP        L_end_main
; end of _main

_allOff:

;LED3.c,29 :: 		void allOff(){
;LED3.c,30 :: 		PORTA = 0x00;
	LDI        27, 0
	OUT        PORTA+0, 27
;LED3.c,31 :: 		PORTB = 0x00;
	LDI        27, 0
	OUT        PORTB+0, 27
;LED3.c,32 :: 		PORTC = 0x00;
	LDI        27, 0
	OUT        PORTC+0, 27
;LED3.c,33 :: 		PORTD = 0x00;
	LDI        27, 0
	OUT        PORTD+0, 27
;LED3.c,34 :: 		}
L_end_allOff:
	RET
; end of _allOff
