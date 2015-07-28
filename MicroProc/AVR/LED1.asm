
_main:
	LDI        27, 255
	OUT        93, 27
	LDI        27, 0
	OUT        94, 27

;LED1.c,1 :: 		void main() {
;LED1.c,2 :: 		DDRB = 0x01;
	LDI        27, 1
	OUT        DDRB+0, 27
;LED1.c,4 :: 		while(1){
L_main0:
;LED1.c,5 :: 		PORTB = 0x01;
	LDI        27, 1
	OUT        PORTB+0, 27
;LED1.c,6 :: 		Delay_ms(1000);
	LDI        18, 41
	LDI        17, 150
	LDI        16, 128
	DEC        16
	BRNE       $-1
	DEC        17
	BRNE       $-3
	DEC        18
	BRNE       $-5
;LED1.c,8 :: 		PORTB = 0x00;
	LDI        27, 0
	OUT        PORTB+0, 27
;LED1.c,9 :: 		Delay_ms(1000);
	LDI        18, 41
	LDI        17, 150
	LDI        16, 128
	DEC        16
	BRNE       $-1
	DEC        17
	BRNE       $-3
	DEC        18
	BRNE       $-5
;LED1.c,10 :: 		}
	JMP        L_main0
;LED1.c,11 :: 		}
L_end_main:
	JMP        L_end_main
; end of _main
