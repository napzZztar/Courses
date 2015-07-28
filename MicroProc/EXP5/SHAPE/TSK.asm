CODE SEGMENT
 ASSUME CS:CODE, DS:CODE, ES:CODE, SS:CODE

PPIC_C EQU 1EH ; Control Register
PPIC EQU 1CH ; C port
PPIB EQU 1AH
PPIA EQU 18H

ORG 1000H
MOV AL, 10000000B ; All PORT initialized as Output
OUT PPIC_C, AL ; Send control word to Control Register
MOV AX, CS ; Make code and data segment same
MOV DS, AX
XOR AX, AX ; Clear AX

STT:

MOV BL, 10

L1: MOV SI, OFFSET FONT ; Get the address of FONT
 MOV AH,00000001B

L2: MOV AL, [SI] ; Load the FONT sequencially
 OUT PPIB, AL ; Send to PORTB

MOV AL, AH
 OUT PPIC, AL ; send 0x01 to PORTC
 MOV AL, 0FFH
 OUT PPIA, AL
 CALL TIMER ; Create delay

INC SI ; Go for the next line
 CLC ; make Carry flag (CF) = 0
 ROL AH, 1 ; Activate next line
 JNC L2 ; Jump if no carry ? Jump until all the msg of FONT is shown
 DEC BL
 CMP BL, 0
 JNE L1


MOV BL, 10
L3: MOV SI, OFFSET FONT1 ; Get the address of FONT
 MOV AH,00000001B

L4: MOV AL, [SI] ; Load the FONT sequencially
 OUT PPIB, AL ; Send to PORTB

MOV AL, AH
 OUT PPIC, AL ; send 0x01 to PORTC
 MOV AL, 0FFH
 OUT PPIA, AL
 CALL TIMER ; Create delay

INC SI ; Go for the next line
 CLC ; make Carry flag (CF) = 0
 ROL AH, 1 ; Activate next line
 JNC L4 ; Jump if no carry ? Jump until all the msg of FONT is shown
 DEC BL
 CMP BL, 0
 JNE L3



MOV BL, 10
L5: MOV SI, OFFSET FONT2 ; Get the address of FONT
 MOV AH,00000001B

L6: MOV AL, [SI] ; Load the FONT sequencially
 OUT PPIB, AL ; Send to PORTB

MOV AL, AH
 OUT PPIC, AL ; send 0x01 to PORTC
 MOV AL, 0FFH
 OUT PPIA, AL
 CALL TIMER ; Create delay

INC SI ; Go for the next line
 CLC ; make Carry flag (CF) = 0
 ROL AH, 1 ; Activate next line
 JNC L6 ; Jump if no carry ? Jump until all the msg of FONT is shown
 DEC BL
 CMP BL, 0
 JNE L5


MOV BL, 10
L7: MOV SI, OFFSET FONT3 ; Get the address of FONT
 MOV AH,00000001B

L8: MOV AL, [SI] ; Load the FONT sequencially
 OUT PPIB, AL ; Send to PORTB

MOV AL, AH
 OUT PPIC, AL ; send 0x01 to PORTC
 MOV AL, 0FFH
 OUT PPIA, AL
 CALL TIMER ; Create delay

INC SI ; Go for the next line
 CLC ; make Carry flag (CF) = 0
 ROL AH, 1 ; Activate next line
 JNC L8 ; Jump if no carry ? Jump until all the msg of FONT is shown
 DEC BL
 CMP BL, 0
 JNE L7


 JMP STT ; Always Jump to the beginning and keep displaying



 INT 3 ; Halt ?Never executed

TIMER: MOV CX, 300 ; This is a delay function
TIMER1: NOP ; NOP (No Operation) does nothing, but uses clock cycle.
 NOP
 NOP
 NOP
 LOOP TIMER1 ;
RET

hlt              


FONT DB 11111111B
     DB 11111011B
     DB 11110011B
     DB 11100000B
     DB 11110011B
     DB 11111011B
     DB 11111111B
     DB 11111111B

FONT1 DB 11111111B
     DB 11110111B
     DB 11100111B
     DB 11000000B
     DB 11100111B
     DB 11110111B
     DB 11111111B
     DB 11111111B



FONT2 DB 11111111B
     DB 11101111B
     DB 11001111B
     DB 10000001B
     DB 11001111B
     DB 11101111B
     DB 11111111B
     DB 11111111B

FONT3 DB 11111111B
      DB 11011111B
      DB 10011111B
      DB 00000011B
      DB 10011111B
      DB 11011111B
      DB 11111111B
      DB 11111111B


CODE ENDS
 END 