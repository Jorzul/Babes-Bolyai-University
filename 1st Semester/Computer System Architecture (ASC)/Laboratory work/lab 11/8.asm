bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, printf               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import printf msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)

segment data use32 class=data
    format_ascii db "%c", 0
    format_base8 db "%u", 0

; our code starts here
segment code use32 class=code
    base8ascii:
        
        cmp AL, 8
        jae exit_base_loop
        
        mov CL, 8
        
        base_loop:
        
            shl AL, 1
        
        exit_base_loop:
        
        ret
        
    start:
        mov BL, 40
        
        while_loop:
            
            mov EAX, 0
            mov AL, BL
            
            push EAX
            push dword format_base8
            call [printf]
            
            add esp, 4*2
            mov AL, BL
            
            push EAX
            push dword format_ascii
            call [printf]
            
            add esp, 4*2
            
            mov AL, BL
            mov CL, 10
            mov AH, 0
            
            div CL
            
            cmp AH, 7
            jne jumpp
            add BL, 2
            jumpp:
            add BL, 1
            cmp BL, 126
            
            jbe while_loop
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
