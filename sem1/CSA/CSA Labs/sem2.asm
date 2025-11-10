bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    ;a db 10
    ;b dw 9
    ;c db 7
    ;d db 3
    ;x resw 1
    a db 1
    b db 2
    c db 4
    d db 5
    e dw 5
    x dq 6
    
; our code starts here
segment code use32 class=code
    start:
        ; ... unsigned
        ; (a*b)/d - c
        ;mov AL, [a]
        ;mov AH, 0 ; now in AX we have [a]
        ;mul word [b] ; now in DX:AX we have a*b
        ;mov CL, [d]
        ;mov CH, 0 ; CX now has d
        ;div CX; DX:AX will be divided by CX and the result (quotient) is in AX
        ;mov CL, [c]
        ;mov CH, 0 ; CX= [c]
        ;sub AX, CX ; the result will be in AX
        ;mov [x], AX
        ;_________________________________________________________________________
        ;signed
        ;mov AL, [a] 
        ;cbw; ax=a
        ;imul word [b] ; DX:AX = a*b
        ;mov CX, AX; in cx we have the lower part of ab, DX:CX has ab
        ;mov AL , [d] ; 
        ;cbw ; ax has d
        ;mov BX,AX ; now bx has d 
        ;mov AX,CX ; DX:AX again contains a*b
        ;idiv BX ; ax= a*b/data
        ;mov BX,AX; bx has the result bc we dont need bx anymore. 
        ;mov AL, [c]
        ;cbw ; AX contains c
        ;sub BX, AX ; bx=bx-ax 
        ;mov [x], BX ; we move the final result into x
        ;__________________________________________________________________________
        
        ;(a*b*c-d)/e-x
        ;a,b,c,d - bytes, e- word, x -quad word
        ; unsigned
        
        ;mov Al, [a];
        ;mul byte [b]; in ax we have ab
        ;mov BL, [c]; 
        ;mov BH, 0; Bx=c
        ;mul BX ; DX:AX has a*b*c
        ;push DX
        ;push AX
        ;pop EAX; EAX gets DX:AX
        ;mov EDX, 0
        ;mov DL, [d]; EDX=d
        ;sub EAX, EDX ; eax will have abc-d
        ;push EAX
        ;pop AX
        ;pop DX ; DX:AX = EAX
        ;div word [e] ; the division is in ax , quotient in al and remainder in ah ???? i think
        ;mov  EBX, 0
        ;mov BX, AX; EBX =( abc-d ) /e
        ;mov ECX, 0
        ;sub EBX, [x] ; we only take the lower part of x here!
        ;sbb ECX, [x+4]
        ; final result will be in ECX:EBX
        
        ; signed
        mov AL, [a]
        imul byte [b] ; in AX
        mov BX,AX;
        mov AL, [c]
        cbw [c] ; in ax we have c 
        imul BX; res is in DX:AX
        mov BX,AX
        mov CX, DX
        ; now DX:AX is in CX:BX
        mov AL, [d]
        cbw ; in ax we have d
        cwd ; AX to DX:AX
        sub BX, AX
        sbb CX, DX
        ; now our result is in CX:BX
        mov AX, BX
        mov DX,CX
        idiv word [e] ; in AX we have the result
        cwde ; changes from AX to EAX!
        cdq ; EDX:EAX takes the result
        sub EAX, [x]
        sbb EDX, [x+4]
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
