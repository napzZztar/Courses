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
    
    SINE DB 127, 149, 170, 191, 209, 224, 237, 246
    DB 252, 254, 252, 246, 237, 224, 209, 191
    DB 170, 149, 127, 105, 84, 64, 45, 30
    DB 17, 8, 2, 0, 2, 8, 17, 30, 45, 64, 84, 105
    
    CODE ENDS
END