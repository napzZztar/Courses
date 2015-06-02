CODE SEGMENT
    ASSUME CS:CODE, DS:CODE
    
    MOV AX, 1234H
    MOV BX, 5678H
    
    MOV CX, AX
    MOV AX, BX
    MOV BX, CX
    
    HLT
    CODE ENDS
END