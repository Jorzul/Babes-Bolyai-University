bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, fopen, fclose, fread, printf, fprintf, scanf              ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll
import fclose msvcrt.dll
import fopen msvcrt.dll
import fread msvcrt.dll
import fprintf msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    file_name db "file.txt", 0
    open_mode db "a+", 0
    file_descriptor dd 0
    stop dd 0
    read_format db "%d", 0
    format db "%d%c", 0
    new_line dd `\n`, 0
    read_word dd 0
; our code starts here
segment code use32 class=code
    start:
        ; ...
        push open_mode
        push file_name
        call [fopen]
        add esp, 4*2
        
        cmp eax, 0
        je .end
        mov [file_descriptor], eax
        
        .read_words
            push read_word
            push read_format
            call [scanf]
            add esp, 4*2
            
            mov eax, [read_word]
            cmp eax, [stop]
            je .end
            
            push dword [new_line]
            push dword [read_word]
            push format
            push dword [file_descriptor]
            call [fprintf]
            add esp, 4*3
         jmp .read_words
         push dword [file_descriptor]
         call [fclose]
         add esp, 4
            .end:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
