CODE SEGMENT 
	ASSUME CS:CODE, DS:CODE

    MOV AX, 10
    MOV BX, 5
    
    MOV CX, 15
    ADD CX, AX
    SUB CX, 17
    ADD CX, BX
    
    HLT  
    CODE ENDS
END