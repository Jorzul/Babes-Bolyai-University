bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    s DD 12345678h, 1A2C3C4Dh, 98FCDC76h
    len_s   equ   ($-s)/4
    d db 0
    zece db 10

; our code starts here
segment code use32 class=code
    start:
        mov ecx, len_s
        mov esi, s
        mov edi, d
        jecxz theend
    repeat:
        mov ebx, 0
        mov eax, 0
        
        lodsd   ; eax = ds:esi   + esi = esi + 4
        shr eax, 16
        mov ah, 0    ; in AL we will have the low byte of the high word of the high doubleword
        
        div byte [zece] 
        
        mov bl, ah
        mov bh, al    ; we got the palindrome of ah:al in bh:bl 
        
        cmp al, bl
        cmp ah, bh
        jne continue
        
        stosb  ; mov [edi], al  + inc edi
        
        continue:
        loop repeat
    
    theend:    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
