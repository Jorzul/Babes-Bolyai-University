bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, fopen, fclose, fread, printf, fprintf               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll
import fclose msvcrt.dll
import fopen msvcrt.dll
import fread msvcrt.dll
import fprintf msvcrt.dll
import printf msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    file_name db "file.txt", 0
    text db "adafnfnFESNFNInnuBkvYBjvHBHb457667Fgu67t6456!@$%^&&^%$#FW4%^$#$%Y%GF^%UY$", 0
    text_length equ $ - text
    a_code db "!"
    z_code db "?"
    open_mode db "w+", 0
    file_descriptor dd 0
    write_format db "%s", 0
; our code starts here
segment code use32 class=code
    start:
        ; ...
        
        mov esi, text
        mov ecx, text_length
        .loop:
        
        push ecx
        
            lodsb
            cmp al, [a_code]
            jb .end_loop
            cmp al, [z_code]
            ja .end_loop
            
            ; lower case letters get here in al
            mov al, "X"
            mov [esi-1], al
            
        .end_loop:
        pop ecx
        loop .loop
        
        push open_mode
        push file_name
        call [fopen]
        add esp, 4*2
        
        cmp eax, 0
        je .end
        mov [file_descriptor], eax
        push text
        push write_format
        push dword [file_descriptor]
        call [fprintf]
        add esp, 4*3
        
        push text
        push write_format
        call [printf]
        add esp, 4*2
        
        .end:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
