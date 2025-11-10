bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; Multiplications, divisions - Unsigned representation and signed representation

;    1) (a*a+b/c-1)/(b+c)+d-x; a-word; b-byte; c-word; d-doubleword; x-qword    -SIGNED

segment data use32 class=data
    a dw 3
    b db 8
    c dw 13
    d dd 19
    x dq 67
    ; -48

; our code starts here
segment code use32 class=code
    start:
        
        xor EAX,EAX ;clear
        mov AX,[a]  ;put a i AX
        imul word [a] ;signed mul , a*a is now in DX:AX
        
        push DX
        push AX
        pop ECX
        
        xor EAX,EAX
        xor EDX,EDX
        mov AL,[b]
        cbw
        cwd ; b is now in !DX:AX!
        idiv word[c] ; we divide by c
        ; b/c is now in AX
        cwde 
        add ECX,EAX ; in ecx we now have a*a+b/c
        
        xor EAX,EAX
        mov AL,1
        sub ECX,EAX ; in ecx we now have a*a+b/c-1
        
        xor EAX,EAX
        mov AL,[b]
        cbw ; b is now in AX
        add AX,[c] ; in AX we now have b+c
        ;;;;;;;;;;;;;;;;;;;
        push AX
        mov EAX, ECX
        pop BX
        
        push EAX
        xor AX,AX
        xor DX,DX
        pop AX
        pop DX
        
        idiv BX ; in DX:AX we have (a*a+b/c-1)/(b+c)
        
        push EAX ; EAX on stack
        xor EAX,EAX
        mov EAX,[d]
        cdq ;in EDX:EAX we have d
        sub EAX,[x]
        sbb EDX,[x+4] ; in EDX:EAX we have d-x
        
        xor EDX,EDX
        pop ECX ; we have (a*a+b/c-1)/(b+c) in ECX
        xor EBX,EBX ; we clear EBX so that EBX:ECX is (a*a+b/c-1)/(b+c)
        
        add ECX,EAX
        adc EBX,EDX ; we have the result in EBX:ECX
        
        
        
        
        
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
