bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, fopen, fclose, fread, printf   ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll
import fclose msvcrt.dll
import fopen msvcrt.dll
import fread msvcrt.dll
import printf msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                           ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    file_name db "file.txt", 0
    read_mode db "r", 0
    upper_case_A db "A"
    upper_case_Z db "Z"
    write_mode db "w", 0
    file_stream dd 0
    bytes_read dd 0
    highet_freq_char dd 0
    char_freq dd 0
    format db "%c: %d", 0
    read_content resb 2000

; our code starts here
segment code use32 class=code
    start:
        push read_mode
        push file_name
        call [fopen]
        add esp, 4*2   ; we read each letter
        
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
            
        ; go through each digit, count the appearance and put a zero where you passed through it, digit stays in al, count in ebx
        mov esi, read_content
        mov ecx, [bytes_read]
        
        .loop:
            
            push ecx
            lodsb
            
            cmp al, [upper_case_A]
            jb .end_loop
            
            cmp al, [upper_case_Z]
            jg .end_loop              ; if digit is between A or Z then we count it and put a zero
            
            mov ebx, 0
            mov edi, read_content
            mov ecx, [bytes_read]
            
            .count:
                scasb
                jne .dont_count
                
                add ebx, 1
                
                .dont_count:
            loop .count
            
            cmp dword [char_freq], ebx
            jg .end_loop
            
            mov [highet_freq_char], al
            mov [char_freq], ebx         ; change the char and the frequency
            
            .end_loop:
            pop ecx
            
        loop .loop
        
        push dword [char_freq]
        push dword [highet_freq_char]
        push format
        call [printf]
        
        .end:
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
