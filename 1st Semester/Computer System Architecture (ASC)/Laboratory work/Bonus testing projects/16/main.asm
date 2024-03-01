bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, fopen, fread, printf                ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll
import fopen msvcrt.dll
import fread msvcrt.dll
import printf msvcrt.dll
    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    x_count dd 0
    y_count dd 0
    file_name db "file.txt", 0
    file_descriptor dd 0
    open_mode db "r", 0
    bytes_read dd 0
    read_text resb 2000
    print_format db "%c: %d, %c: %d", 0
; our code starts here
segment code use32 class=code
    start:
        ; ...
        push open_mode
        push file_name
        call [fopen]
        add esp, 4*2
        
        cmp eax, 0
        je .end_program
        mov [file_descriptor], eax
        
        .read_file_loop:
            push dword [file_descriptor]
            push dword 100
            push dword 1
            push read_text
            call [fread]
            add esp, 4*4
            
            add [bytes_read], eax
            cmp eax, 0
            jne .read_file_loop
            
        mov esi, read_text
        mov ecx, [bytes_read]
        
        .compare_loop:
            lodsb
            cmp al, "x"
            jne .compare_y
            ; is x
            add dword [x_count], 1
            .compare_y:
            cmp al, "y"
            jne .end_compare
            ;is y
            add dword[y_count], 1
            .end_compare:
        loop .compare_loop
        mov eax, "x"
        mov ebx, "y"
        push dword[ x_count]
        push eax
        push dword [y_count]
        push ebx
        push print_format
        call [printf]
        add esp, 4*5
        ; exit(0)
        .end_program:
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
