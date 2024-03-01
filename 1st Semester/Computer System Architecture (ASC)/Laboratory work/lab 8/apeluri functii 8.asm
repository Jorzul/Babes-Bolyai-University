bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, printf, scanf              ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a dd 50
    b dw 0
	message db "b=", 0 
    format db "%d", 0
    result dd 0
    result_format db "a + a/b = %d", 0

; our code starts here
segment code use32 class=code
    start:
        push dword message
        call [printf]
        add esp, 4*1   ; prints 'b=' so that we know what variable to read
        
        push dword b
        push dword format
        call [scanf]   ; read the number
        add esp, 4*2
        
        mov eax, [a]
        push eax
        pop ax
        pop dx    ; dx:ax = a (so that we can do a/b later)
        
        mov bx, [b]
        idiv bx        ; ax = a/b
        
        cwde
        mov ebx, [a]
        add ebx, eax
        mov [result], ebx
        
        push dword [result]
        push dword result_format
        call [printf]
        add esp, 4*2
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
