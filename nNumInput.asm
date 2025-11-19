.MODEL SMALL
.STACK 100H
.DATA
    MSG DB "Enter the number of input: $"
    N   DB 0
    X   DB ?
.CODE

MAIN PROC
    MOV AX, @DATA
    MOV DS, AX

    ; print message
    MOV AH, 9
    LEA DX, MSG
    INT 21H

    ; ==== INPUT N (single digit) ====
    MOV AH, 1
    INT 21H
    SUB AL, 30H     ; convert ASCII → number
    MOV N, AL

    ; print newline
    MOV AH, 2
    MOV DL, 0DH
    INT 21H
    MOV DL, 0AH
    INT 21H

    ; ==== LOOP N TIMES ====
    XOR CX, CX
    MOV CL, N

READ_LOOP:
    ; input character
    MOV AH, 1
    INT 21H
    MOV X, AL

    ; newline
    MOV AH, 2
    MOV DL, 0DH
    INT 21H
    MOV DL, 0AH
    INT 21H

    ; print character
    MOV AH, 2
    MOV DL, X
    INT 21H

    ; newline again
    MOV AH, 2
    MOV DL, 0DH
    INT 21H
    MOV DL, 0AH
    INT 21H

    LOOP READ_LOOP

    ; EXIT
    MOV AH, 4CH
    INT 21H
MAIN ENDP
END MAIN
