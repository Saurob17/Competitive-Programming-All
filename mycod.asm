.MODEL SMALL
.STACK 100H

.DATA
    ; You can define data here if needed
    MSG DB '?', '$'

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX

    MOV AH, 9          ; print '?'
    LEA DX, MSG
    INT 21H

    MOV AH, 1          ; input a character
    INT 21H
    MOV BL, AL         ; store it in BL

    ; print newline
    MOV AH, 2
    MOV DL, 0DH
    INT 21H
    MOV DL, 0AH
    INT 21H

    ; print character again
    MOV AH, 2
    MOV DL, BL
    INT 21H

    ; return to DOS
    MOV AH, 4CH
    INT 21H
MAIN ENDP
END MAIN
