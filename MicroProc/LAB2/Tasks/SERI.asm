SERIES SEGMENT
    ASSUME CS:SERIES, DS: SERIES
    
    MOV AX, 2D
    XOR DX, DX
    
    L1:
        ADD DX, AX
        ADD AX, 2
        CMP AX, 22
    JNE L1
    HLT
    SERIES ENDS
END
       