bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; (a+a)-(b+b)-c   byte
    ; (a1+b1+b1)+(c1-d1)   word
    ; [(10+d2)-(a2*a2-2*b2)]/c2    a2,b2,c2-byte  d2-word
    a db 10
    b db 5
    c db 2
    x resb 1
    
    ;-----------------------------
    
    a1 dw 100
    b1 dw 30
    c1 dw 55
    d1 dw 17
    x1 resw 1
    
    ;-----------------------------
    
    a2 db 13
    b2 db 5
    c2 db 8
    d2 dw 999
    x2  resw 1
    
    
; our code starts here
segment code use32 class=code
    start:
        ;(a+a)-(b+b)-c   byte
        mov AL, [a]
        add AL, [a]
        mov BL, [b]
        add BL, [b]
        sub AL,BL
        sub AL, [c]
        mov [x], AL
        
        ;-------------------------
        ; (a1+b1+b1)+(c1-d1)   word
        mov AX, [a1]
        add AX,[b1]
        add AX,[b1]
        mov BX, [c1]
        sub BX,[d1]
        add AX,BX
        mov [x1], AX
        
        ;-------------------------
        ; [(10+d2)-(a2*a2-2*b2)]/c2    a2,b2,c2-byte  d2-word
        mov AL,[a2]
        mov AH,0
        mul byte [a2]
        mov BX,AX
        mov AL, [b2]
        mov DL,2
        mul DL
        sub BX,AX
        mov AX,[d2]
        add AX, 10
        sub AX,BX
        div byte [c2]
        mov [x2],BX
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
