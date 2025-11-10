bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
;26
;Given 2 doublewords R and T. Compute the doubleword Q as follows:

; the bits 0-6 of Q are the same as the bits 10-16 of T
; the bits 7-24 of Q are the same as the bits 7-24 of (R XOR T).
; the bits 25-31 of Q are the same as the bits 5-11 of R.

segment data use32 class=data
    R dd 13
    T dd 244
    Q resd 1
;00000000000000000000000000001101 R
;00000000000000000000000011110100 T 
;00000000000000000000000011111001 xor
;00000000000000000000000010000000 result = 128

; our code starts here
segment code use32 class=code
    start:
        mov EAX,0 ; i want my result to be built in EAX
        mov EBX,[T]
        and EBX,1FC00h ; 00000000000000011111110000000000 binary 
        shr EBX,10
        or EAX,EBX
        
        mov EBX,[T]
        xor EBX,[R]
        and EBX,1FFFF80h ; 00000001111111111111111110000000 binary
        or EAX,EBX
        
        mov EBX,[R]
        and EBX, 0FE0h ; 00000000000000000000111111100000 binary
        shl EBX,20
        or EAX,EBX
        
        mov [Q],EAX
        
        ;EAX=0  EBX=R   ESI=T  EDX=xor
        
        
            
        
        mov [Q],EAX ; result in Q
        
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
