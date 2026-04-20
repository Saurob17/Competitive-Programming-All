; .model small
; .stack 100h
; .code
; main proc

; mov ah,1
; int 21h
; mov bl,al


; mov ah,1
; int 21h
; mov bh,al

; mov ah,2
; mov dl,10
; int 21h



; mov ah,2
; mov dl,13
; int 21h


; mov ah,1
; int 21h
; mov cl,al


; mov ah,1
; int 21h
; mov ch,al

; cmp bl,cl

; jg L1
; jmp L2 

;     L1:
;     mov ah,2
;     mov dl,bl 
;     int 21h

;      mov ah,2
;     mov dl,bh
;     int 21h


;     L2:

    
;     mov ah,2
;     mov dl,cl 
;     int 21h

;      mov ah,2
;     mov dl,ch
;     int 21h

;  exit:
;  mov ah,4ch
;  int 21h
;  main endp
;  end main


.model small
.stack 100h
.code
main proc

mov ah,1
int 21h
mov bl,al


mov ah,1
int 21h
mov bh,al

mov ah,2
mov dl,10
int 21h



mov ah,2
mov dl,13
int 21h


mov ah,1
int 21h
mov cl,al


mov ah,1
int 21h
mov ch,al

cmp bl,cl

jg L1
jmp L2 

    L1:
    mov ah,2
    mov dl,bl 
    int 21h

     mov ah,2
    mov dl,bh
    int 21h


    L2:

    cmp cl,bl
    jg L3

    jmp L4
    
    L3:
    mov ah,2
    mov dl,cl 
    int 21h

     mov ah,2
    mov dl,ch
    int 21h

    L4:  cmp bh,ch
        jge L5
        jmp L6

    L5: mov ah,2
    mov dl,bl 
    int 21h

     mov ah,2
    mov dl,bh
    int 21h


    L6:
   mov ah,2
    mov dl,cl 
    int 21h

     mov ah,2
    mov dl,ch
    int 21h

 exit:
 mov ah,4ch
 int 21h
 main endp
 end main