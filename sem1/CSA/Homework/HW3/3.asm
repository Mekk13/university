bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; Multiplications, divisions - Unsigned representation and signed representation
;    1) (a*a+b/c-1)/(b+c)+d-x; a-word; b-byte; c-word; d-doubleword; x-qword   -UNSIGNED
segment data use32 class=data
    a dw 4
    b db 8
    c dw 4
    d dd 67
    x dq 19
    ;=49

; our code starts here
segment code use32 class=code
    start:
        xor AX,AX
        xor DX,DX ; clear AX,DX
        mov AX,[a] ;put a in AX
        mul word[a] ; in DX:AX we have a*a
        
        xor EBX,EBX
        push DX
        push AX
        pop EBX ; a*a is now in EBX 
        
        xor EAX,EAX
        xor EDX,EDX
        mov AL,[b]
        div word [c] ;! DX:AX = DX:AX/[c] = b/c
        push DX
        push AX
        pop EAX
        
        add EBX,EAX ; in EBX we now have a*a+b/c  
        xor EAX,EAX
        mov AL,1
        sub EBX,EAX ; we put 1 into AL (so into EAX too bc its cleared) and then subtracted it from EBX
        ;EBX now has a*a+b/c-1
        
        xor EAX,EAX
        xor ECX,ECX
        mov CL,[b] ; we put b in CL
        add CX,[c] ; AX now has b+c
        
        mov EAX,EBX ; put a*a+b/c-1 in EAX for division
        div CX ; EAX= EAX/CX so (a*a+b/c-1)/(b+c)
        
        xor EBX,EBX
        xor ECX,ECX ;clear
        mov ECX,[d] ; put d in ECX
        sub ECX,[x] 
        sbb EBX,[x+4] 
        ; now EBX:ECX has d-x
        
        xor EDX,EDX
        add EAX,ECX
        adc EDX,EBX ; we add them together in EDX:EAX
        
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
