DAC EQU 3FD8H

CODE SEGMENT
    
    ASSUME CS: CODE, DS: CODE
    
    XOR AL, AL
    MOV DX, DAC
    
    L1:    
    OUT DX, AL
    INC AL
    JMP L1
    
    HLT
    CODE ENDS
END