ARRAY SEGMENT
    ASSUME CS:ARRAY, DS: ARRAY
    
    XOR AX, AX
    MOV AX, CS
    MOV DS, AX
    MOV AX, 0
    
    MOV SI, OFFSET A
    MOV CX, 3
    MOV BL, 3
    
    L1:
        ADD AL, [SI]
        INC SI
    LOOP L1
    DIV BL
    HLT  
          
    A DB 3,1,2
    ARRAY ENDS
END
       