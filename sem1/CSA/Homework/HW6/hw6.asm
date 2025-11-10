bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; A string of doublewords is given. Compute the string formed by the high bytes of the low words from the elements of the 
;doubleword string and these bytes should be multiple of 10. 
;example: s DD 12345678h, 1A2B3C4Dh, FE98DC76h 
;obtain: d DB 3Ch, DCh.
segment data use32 class=data
    s dd 12345678h,1A2B3C4Dh,0FE98DC76h
    ls equ ($-s)/4
    d times ls db 0
    aux resb 1
    

; our code starts here
segment code use32 class=code
    start:
        mov ECX, ls ; We put the length of the string in ECX for the loop
        mov ESI,s ; We put the string in ESI so we can use certain instructions
        mov EDI,d ; the result string in EDI
        jecxz end_loop
        repeat:
            lodsd ; in EAX we load the whole doubleword and ESI is incremented by 4 automatically
            ; we only need the higher part of the lowesr word, AH , so we isolate it   
            mov [aux],AH; we put the value in aux 
            xor EAX,EAX
            mov AL,[aux]
            mov BX, 10
            xor DX,DX ; making sure dx is 0
            idiv BX ; we divide DX:AX/BX => AX will hold the quotient and DX the remainder
            test DX,DX ; ZF=1 if DX is 0 (so no remainder, which means that the value in AX was a multiple of 10)
            jnz avoid ; if we DID have a remainder then ZF is 0 and we jump
            ; otherwise we add it to the result string:
            
            xor AX,AX
            mov AL,[aux]; put aux back in AL
            stosb ; we put the value from AL to ES:EDI
            
            avoid:
        loop repeat
        end_loop:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
