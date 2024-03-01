bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, printf, scanf, fopen, fclose, fprintf, fread               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fprintf msvcrt.dll
import fread msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
        fisier db "mirel.txt", 0
        format_fisier db "r", 0
        descriptor dd -1
        len equ 100
        a times len db 0

; our code starts here
segment code use32 class=code
    start:
        push dword format_fisier
        push dword fisier
        call [fopen]
        add esp, 4*2
        
        mov [descriptor], eax
        
        cmp [descriptor], dword 0
        je gata
        
        push dword [descriptor]
        push dword len
        push dword 1
        push dword a
        call [fread]
        add esp, 4*4
        
        push dword a
        call [printf]
        add esp, 4
    gata:
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
