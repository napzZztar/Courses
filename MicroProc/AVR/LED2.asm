
_main:
	LDI        27, 255
	OUT        93, 27
	LDI        27, 0
	OUT        94, 27

;LED2.c,1 :: 		void main() {
;LED2.c,2 :: 		DDRA = 0x55;
	LDI        27, 85
	OUT        DDRA+0, 27
;LED2.c,4 :: 		while(1){
L_main0:
;LED2.c,5 :: 		PORTA = 0x55;
	LDI        27, 85
	OUT        PORTA+0, 27
;LED2.c,6 :: 		Delay_ms(1000);
	LDI        18, 41
	LDI        17, 150
	LDI        16, 128
	DEC        16
	BRNE       $-1
	DEC        17
	BRNE       $-3
	DEC        18
	BRNE       $-5
;LED2.c,8 :: 		PORTA = 0x00;
	LDI        27, 0
	OUT        PORTA+0, 27
;LED2.c,9 :: 		Delay_ms(500);
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
;LED2.c,10 :: 		}
	JMP        L_main0
;LED2.c,11 :: 		}
L_end_main:
	JMP        L_end_main
; end of _main
