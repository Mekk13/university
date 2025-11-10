bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

;  a - byte, b - word, c - double word, d - qword - Unsigned representation
;  1)(c-b+a)-(d+a) ECX:EBX is correct!!
segment data use32 class=data
    a db 2
    b dw 20
    c dd 22
    d dq 1
    x resd 1
    ;1

segment code use32 class=code
    start:
        xor EAX,EAX ;EAX =0
        mov AX,[b] ; now in eax we have b
        xor EBX,EBX ;EBX =0
        mov BL,[a]  ;BL=a
        mov ECX, [c] ;ECX=c
        sub ECX,EAX  ;ECX=c-b
        add ECX, EBX ;ECX=c-b+a
        mov [x],ECX ; x=c-b+a
        
        xor EAX,EAX ;EAX=0
        mov AL,[a] ; now in EAX we have a
        xor EDX,EDX ; clear EDX
        add EAX,[d]
        adc EDX,[d+4] ; we add with a carry 
        ; now EDX:EAX = d+a
        
        xor EBX,EBX
        mov ECX,[x] ;EBX:ECX now has c-b+adc
        
        sub ECX,EAX
        sbb EBX,EDX ; EBX:ECX has the final result
        
 
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
