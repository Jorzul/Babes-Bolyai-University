bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, fopen, fclose, fread, printf               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll
import fclose msvcrt.dll
import fopen msvcrt.dll
import fread msvcrt.dll

import printf msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    file_name db "file.txt", 0
    search_characters db "`~!@#$%^&*()-_=+{}[]|\:;\'<,>,?", 0
    characters equ $ - search_characters
    read_mode db "r", 0
    write_mode db "w", 0
    file_stream dd 0
    bytes_read dd 0
    found dd 0
    format db "%d", 0
    read_content resb 2000
; our code starts here
segment code use32 class=code
    start:
        ; ...
        push read_mode
        push file_name
        call [fopen]
        add esp, 4*2
        
        cmp eax, 0
        je .end
        mov [file_stream], eax
        .main_program:
            push dword [file_stream]
            push dword 100
            push dword 1
            push read_content
            call [fread]
            add esp, 4*4
            
            add dword[bytes_read], eax
            cmp eax, 0  
            jne .main_program
            
        mov ecx, [bytes_read]
        mov esi , read_content
        .loop:
            push ecx
            mov ecx, characters
            lodsb
            mov edi, search_characters
            .search:             
                scasb
                jne .not_equal
                ; they are equal
                add dword[found], 1
                jmp .end_loop
                .not_equal:
            loop .search
            .end_loop
            pop ecx
        loop .loop
        .end:
        push dword [file_stream]
        call [fclose]
        add esp, 4
        
        push dword [found]
        push format
        call [printf]
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
