bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)

; A character string S is given. Obtain the string D that contains all capital letters of the string S.
; Example:
;  S: 'a', 'A', 'b', 'B', '2', '%', 'x', 'M'
;  D: 'A', 'B', 'M'


segment data use32 class=data
    s db 'a', 'A', 'b', 'B', '2', '%', 'x', 'M' ; declare the string of bytes
	l equ $-s 
	d db 0

; our code starts here
segment code use32 class=code
    start:
        mov ecx, l ; we put the length l in ECX in order to make the loop
        mov esi, 0     
        mov edi, 0   ; EDI is for d and ESI is for s
        jecxz Exit      
        Repeat:
            mov al, [s+esi]
            sub al, 'A'
            mov bl, 'Z' - 'A'    
            cmp al, bl        ; if al > b that means al = capital letter
            jnbe notOK
            mov al, [s+esi] 
            mov [d+edi], al    ; we put al in d and increase edi 
            inc edi
            notOK:
            inc esi
        loop Repeat
        Exit:       ;end of the program
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
