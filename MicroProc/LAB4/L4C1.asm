CNT3 EQU 3FD6H
BPORT3 EQU 3FD2H

CODE SEGMENT
ASSUME CS:CODE,DS:CODE
    MOV AL,10000000B
    MOV DX,CNT3
    OUT DX,AL 
    
    MOV AL,95h
    MOV DX,BPORT3
    OUT DX,AL 
    
    
    HLT
CODE ENDS
    END

