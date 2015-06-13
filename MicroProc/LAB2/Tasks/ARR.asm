ARRAY SEGMENT
    ASSUME CS:ARRAY, DS: ARRAY
    
    XOR AX, AX
    MOV AX, CS
    MOV DS, AX
    MOV AX, 0
    
    MOV SI, OFFSET A
    MOV CX, 5
    
    L1:
        ADD AL, [SI]
        INC SI
    LOOP L1
    HLT  
          
    A DB 15,19,7,20,2
    ARRAY ENDS
END
       