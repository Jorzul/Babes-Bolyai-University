bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, fopen, fclose, fread, printf, scanf, fprintf               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll
import fclose msvcrt.dll
import fopen msvcrt.dll
import fread msvcrt.dll
import fprintf msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll
    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    file_descriptor resd 1
    open_mode db "w+", 0
    file_name resb 31
    text resb 121
    read_format db "%s", 0
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        push file_name
        push read_format
        call [scanf]
        add esp, 4*2
        
        push text
        push read_format
        call [scanf]
        add esp, 4*2
        
        push open_mode
        push file_name
        call [fopen]
        add esp, 4*2
        cmp eax, 0
        je .end
        mov [file_descriptor], eax
        
        push text
        push read_format
        push dword[ file_descriptor]
        call [fprintf]
        add esp, 4*3
        
        push file_name
        push read_format
        call [printf]
        
        .end:
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
