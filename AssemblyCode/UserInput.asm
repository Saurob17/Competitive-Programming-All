.model small
.stack 100h
.code

main proc

    ; input character
    mov ah,1
    int 21h
    mov bl,al

    ; new line (correct order)
    mov ah,2
    mov dl,13     ; CR
    int 21h

    mov dl,10     ; LF
    int 21h

    ; output character
    mov ah,2
    mov dl,bl
    int 21h

    mov ah,4ch
    int 21h

main endp
end main