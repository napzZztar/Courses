CODE SEGMENT 
    ASSUME CS:CODE, DS: CODE, ES:CODE, SS:CODE
    
    PPIC_C EQU 1FH
    PPIC EQU 1DH
    PPIB EQU 1BH
    PPIA EQU 19H
    
    ORG 1000H
    MOV AX, 0
    
    MOV AL, 10000000B
    OUT PPIC_C, AL
    
    MOV CX, 50
    MOV AL, 11101110B
    
    L1:
        OUT PPIB, AL
        PUSH CX
        MOV CX, 0
        LOOP $
        
        POP CX
        ROR AL, 1
        LOOP L1
        
        HLT
    
    CODE ENDS
END