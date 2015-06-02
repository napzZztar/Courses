DAC EQU 3FD8H

CODE SEGMENT
    
    ASSUME CS: CODE, DS: CODE
    
    MOV DX, DAC
    XOR AL, AL
    L1:
    OUT DX, AL
    INC AL
    CMP AL, 0FFH
    JNZ L1
    
    L2:
    OUT DX, AL
    DEC AL
    AND AL, AL
    JNZ L2
    JMP L1
    
    
    HLT
    CODE ENDS
END