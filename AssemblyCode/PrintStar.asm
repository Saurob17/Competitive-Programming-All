.MODEL SMALL
.STACK 100H

.CODE
MAIN PROC
    ; Initialize the Data Segment (Optional here but good practice)
    MOV AX, @DATA
    MOV DS, AX

    ; 1. Set the counter
    MOV CX, 80          ; Load CX with 80 (Number of iterations)

    ; 2. Prepare to print a character
    MOV AH, 2           ; DOS Function to display a character
    MOV DL, '*'         ; The character to be displayed

DISPLAY_LOOP:           ; Label for the start of the loop
    INT 21H             ; Call DOS interrupt to print the character in DL
    
    LOOP DISPLAY_LOOP   ; Decrement CX, if CX > 0, jump to DISPLAY_LOOP

    ; 3. Exit the program
    MOV AH, 4CH         ; DOS Function to terminate program
    INT 21H

MAIN ENDP
END MAIN