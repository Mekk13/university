bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; A byte string S is given. Obtain the maximum of the elements found on the even positions and the minimum of the elements found on the odd positions of S. 

;Example:
;S: 1, 4, 2, 3, 8, 4, 9, 5
;   0  1  2  3  4  5  6  7
;max_poz_pare: 9
;min_poz_impare: 3

segment data use32 class=data
    S db 1, 4, 2, 3, 8, 4, 9, 5
    len equ $-S
    max_even db -128
    min_odd db 127

; our code starts here
segment code use32 class=code
    start:
        mov ECX,len
        mov ESI, S ; We want to start from the beginning so we put the starting address of S in ESI
        
        jecxz end_loop
        mov AL, 0 ; i want to manually keep track of my position in the array and i want to start from 0
        
        
        repeat_loop:
            ;mov bl,[s+esi]bits 32 ; assembling for the 32 bits architecture
            mov BL,[ESI] ; we are loading in BL the byte at the memory address ESI (set to S before the loop)
            test AL,01h ; checking if its odd or even 
            ; zero flag is set to 1 when the result of AL and 01h is 0, so when the number is even ZF=0
        
            jz jump ; this will jump when zero flag is 1 => so when index is even 
                ;so here wee need to execute the instructions for when the index is odd
                cmp BL,[min_odd] ; BL-[min_odd]
                jge skip ; jump if BL>=[min_odd], so we dont need to set min_odd
                    mov [min_odd],BL ;  put the new small value in min_odd
                skip:
                
                jmp skip_even; we jump so that we can avoid the even instruction that would otherwise execute afterwards anyway
            jump:
            
            cmp BL,[max_even] ; will do BL-[max_even] and set flags
            jl here ; jump if BL<[max_even]
                mov [max_even], BL ; if BL> the max found so far we take it as a new maximum
            here:
            
            skip_even:
        
            inc ESI ; we move to the next byte= next element in S
            inc AL ; we increment the index counter too
        loop repeat_loop
        end_loop:
        
        mov AL,[max_even]
        mov BL,[min_odd]
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
