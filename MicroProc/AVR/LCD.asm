
_send_command:
	PUSH       28
	PUSH       29
	IN         28, 93
	IN         29, 94
	ADIW       28, 5

;LCD.c,10 :: 		void send_command(unsigned char command)
;LCD.c,13 :: 		LCD_DATA_PORT = command; // Send Command
	LDD        16, Y+0
	OUT        PORTD+0, 16
;LCD.c,15 :: 		LCD_CONTROL_PORT &= ~(1<<RS);
	IN         16, PORTC+0
	ANDI       16, 254
	OUT        PORTC+0, 16
;LCD.c,17 :: 		LCD_CONTROL_PORT &= ~(1<<RW);
	ANDI       16, 253
	OUT        PORTC+0, 16
;LCD.c,19 :: 		LCD_CONTROL_PORT |= 1<<En; // En = 1 (High)
	ORI        16, 4
	OUT        PORTC+0, 16
;LCD.c,20 :: 		Delay_us(1); // wait a while
	LDI        16, 2
	DEC        16
	BRNE       $-1
	NOP
	NOP
;LCD.c,21 :: 		LCD_CONTROL_PORT &= ~(1<<En); // En = 0 (Low)
	IN         27, PORTC+0
	CBR        27, 4
	OUT        PORTC+0, 27
;LCD.c,22 :: 		Delay_us(100); // wait a while
	LDI        17, 2
	LDI        16, 9
	DEC        16
	BRNE       $-1
	DEC        17
	BRNE       $-3
;LCD.c,23 :: 		}
L_end_send_command:
	POP        29
	POP        28
	RET
; end of _send_command

_send_data:
	PUSH       28
	PUSH       29
	IN         28, 93
	IN         29, 94
	ADIW       28, 5

;LCD.c,25 :: 		void send_data(unsigned char dat)
;LCD.c,28 :: 		LCD_DATA_PORT = dat; // Send data
	LDD        16, Y+0
	OUT        PORTD+0, 16
;LCD.c,30 :: 		LCD_CONTROL_PORT |= 1<<RS;
	IN         16, PORTC+0
	ORI        16, 1
	OUT        PORTC+0, 16
;LCD.c,33 :: 		LCD_CONTROL_PORT &= ~(1<<RW);
	ANDI       16, 253
	OUT        PORTC+0, 16
;LCD.c,35 :: 		LCD_CONTROL_PORT |= 1<<En; // En = 1
	ORI        16, 4
	OUT        PORTC+0, 16
;LCD.c,36 :: 		Delay_us(1); // wait a while
	LDI        16, 2
	DEC        16
	BRNE       $-1
	NOP
	NOP
;LCD.c,37 :: 		LCD_CONTROL_PORT &= ~(1<<En); // En = 0
	IN         27, PORTC+0
	CBR        27, 4
	OUT        PORTC+0, 27
;LCD.c,38 :: 		Delay_us(100); // wait a while
	LDI        17, 2
	LDI        16, 9
	DEC        16
	BRNE       $-1
	DEC        17
	BRNE       $-3
;LCD.c,39 :: 		}
L_end_send_data:
	POP        29
	POP        28
	RET
; end of _send_data

_main:
	LDI        27, 255
	OUT        93, 27
	LDI        27, 0
	OUT        94, 27

;LCD.c,40 :: 		void main( )
;LCD.c,43 :: 		LCD_CONTROL_PORT_DDR = 0xFF; // Set PORTC in output mode
	LDI        27, 255
	OUT        DDRC+0, 27
;LCD.c,44 :: 		LCD_DATA_PORT_DDR = 0xFF; // Set PORTD in output mode
	LDI        27, 255
	OUT        DDRD+0, 27
;LCD.c,45 :: 		Delay_us(2000); // Wait for LCD to initialize
	LDI        17, 21
	LDI        16, 199
	DEC        16
	BRNE       $-1
	DEC        17
	BRNE       $-3
;LCD.c,46 :: 		send_command(0x38) ; // Initialize LCD: 2 lines, 5x7 matrix
	LDI        27, 56
	PUSH       27
	CALL       _send_command+0
	IN         26, 93
	IN         27, 94
	ADIW       26, 1
	OUT        93, 26
	OUT        94, 27
;LCD.c,47 :: 		send_command(0x0E); // Display on, cursor on
	LDI        27, 14
	PUSH       27
	CALL       _send_command+0
	IN         26, 93
	IN         27, 94
	ADIW       26, 1
	OUT        93, 26
	OUT        94, 27
;LCD.c,48 :: 		send_command(0x01); // Clear LCD screen
	LDI        27, 1
	PUSH       27
	CALL       _send_command+0
	IN         26, 93
	IN         27, 94
	ADIW       26, 1
	OUT        93, 26
	OUT        94, 27
;LCD.c,49 :: 		Delay_us(2000) ; // Wait for a while
	LDI        17, 21
	LDI        16, 199
	DEC        16
	BRNE       $-1
	DEC        17
	BRNE       $-3
;LCD.c,50 :: 		send_command(0x06) ; // Shift cursor right
	LDI        27, 6
	PUSH       27
	CALL       _send_command+0
	IN         26, 93
	IN         27, 94
	ADIW       26, 1
	OUT        93, 26
	OUT        94, 27
;LCD.c,52 :: 		send_data('A');
	LDI        27, 65
	PUSH       27
	CALL       _send_data+0
	IN         26, 93
	IN         27, 94
	ADIW       26, 1
	OUT        93, 26
	OUT        94, 27
;LCD.c,53 :: 		send_data('I');
	LDI        27, 73
	PUSH       27
	CALL       _send_data+0
	IN         26, 93
	IN         27, 94
	ADIW       26, 1
	OUT        93, 26
	OUT        94, 27
;LCD.c,54 :: 		send_data('U');
	LDI        27, 85
	PUSH       27
	CALL       _send_data+0
	IN         26, 93
	IN         27, 94
	ADIW       26, 1
	OUT        93, 26
	OUT        94, 27
;LCD.c,55 :: 		send_data('B');
	LDI        27, 66
	PUSH       27
	CALL       _send_data+0
	IN         26, 93
	IN         27, 94
	ADIW       26, 1
	OUT        93, 26
	OUT        94, 27
;LCD.c,56 :: 		while(1)
L_main0:
;LCD.c,59 :: 		}
	JMP        L_main0
;LCD.c,60 :: 		}
L_end_main:
	JMP        L_end_main
; end of _main
