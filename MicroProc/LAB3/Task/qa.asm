DAC EQU 3FD8H

CODE SEGMENT
    
    ASSUME CS: CODE, DS: CODE
    
    MOV AX, CS
    MOV DS, AX
    MOV DX, DAC
    
    L1:
    MOV DI, 0
    MOV BL, 36
    
    L2:
    MOV AL, SINE[DI]
    OUT DX, AL
    INC DI
    DEC BL
    JNZ L2
    JMP L1
        
    HLT   
    
    SINE DB 254, 252, 246, 237, 224, 209, 191, 170, 149
    DB 127, 105, 84, 64, 45, 30, 17, 8, 2
    DB 0, 127, 127, 127, 127, 127, 127, 127, 127
    DB 147, 177, 207, 237, 254, 237, 207, 177, 147
    CODE ENDS
END