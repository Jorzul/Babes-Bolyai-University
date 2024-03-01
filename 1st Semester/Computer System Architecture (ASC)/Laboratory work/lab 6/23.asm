bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    s db 2, 4, 2, 5, 2, 2, 4, 4
    len_s equ $-s
    d dw 0

; our code starts here
segment code use32 class=code
    start:
        mov esi, s
        mov ecx, len_s
        mov edi, d
        jecxz theend
    repeat:
        lodsb
        mov bl, al
        push esi
        
        push ecx
        mov ecx, len_s
        
        mov ah, 0
        mov esi, s
        
        repeat2:
            lodsb
            
            cmp al, bl
            jne continue
            
            inc ah
            
            continue:
            loop repeat2
        
        mov al, bl
        stosw
        
        pop ecx
        pop esi
        
        loop repeat
    
    theend:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
