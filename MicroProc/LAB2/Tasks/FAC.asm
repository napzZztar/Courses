FAC SEGMENT
    ASSUME CS:FAC, DS: FAC
    
    MOV AX, 1
    MOV CX, 5
    
    L1:
        MUL CL
    LOOP L1
    
    MOV BX, AX
    
    HLT
    FAC ENDS         
END
       