bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

;    a - byte, b - word, c - double word, d - qword - Signed representation
;    1)(c-d-a)+(b+b)-(c+a) 
segment data use32 class=data
     a db 2
     b dw 7
     c dd -18
     d dq 90
     ; -80

; our code starts here
segment code use32 class=code
    start:
        
        mov EAX,[c]
        cdq ; signed extension of EAX to EDX:EAX
        
        sub EAX,[d]
        sbb EAX,[d+4] ;we subtract d and now in EDX:EAX we have c-d-a
        
        mov ECX, EAX
        mov EBX, EDX ; we move EDX:EAX into EBX:ECX
        
        xor EAX,EAX
        xor EDX,EDX ; we clear EAX and EDX
        mov AL, [a]
        cbw ;AL is converted to AX
        cwde ;AL becomes DX:AX
        cdq ; EAX becomes EDX:EAX 
        
        sub ECX,EAX
        sbb EBX,EDX ; EBX:ECX now has c-d-a
        
        xor EAX,EAX
        xor EDX,EDX
        mov AX,[b]
        add AX, [b] ; in AX we now have b+b
        cwd ;AX becomed DX:AX
        cdq ; DX:AX becomes EDX:EAX
        
        add ECX,EAX
        adc EBX,EDX ; we add them with carry so that we now have (c-d-a)+(b+b) in EBX:ECX
        
        xor EAX,EAX
        xor EDX,EDX
        mov AL, [a]
        cbw ;AL is converted to AX
        cwd ;AL becomes DX:AX
        add AX,[c]
        adc DX,[c+2] ; now in DX:AX we have c+adc
        push DX
        push AX
        pop EAX
        cdq ; EAX to EDX:EAX 
        
        sub ECX,EAX
        sbb EBX,EDX ; now we have the final result in EBX:ECX
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
