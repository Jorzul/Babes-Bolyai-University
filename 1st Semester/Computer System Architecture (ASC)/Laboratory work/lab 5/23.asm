bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)

; 

segment data use32 class=data
    s db 1, 4, 2, 4, 8, 2, 1, 1
    l equ $-s
    d times l db 0

; our code starts here
segment code use32 class=code
    start:
        mov ecx, l
        mov esi, 0
        mov edx, 0
        jecxz Exit
        Repeat:
            mov al,[s+esi]
            push ecx
            mov ecx, l
            mov edi, 0
            jecxz Done
            CheckD:
                mov bl,[d+edi]
                cmp al, bl
                jne OK
                mov [d+edx],al
                inc edx
                jmp Done
                OK:
                inc edi
            loop CheckD
            Done:
            pop ECX
            inc esi
        loop Repeat
        
        Exit:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
