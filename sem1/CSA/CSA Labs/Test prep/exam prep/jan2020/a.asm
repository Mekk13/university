bits 32
global start
extern exit,printf
import exit msvcrt.dll
import printf msvcrt.dll
extern function

segment data use32 class=data
    sir dd -1,123456,0xabcdeff,0xabcdeff,0xcbcdeff,0xdbcdeff,0111010101b
    len equ $-sir
    sir_rezultat times len db 0 
    masca dd 0x0000000F
    sum dd 0
    format db "%d",0

segment code use32 class=code
    start:
        
        push dword sir
        push dword len
        push dword sir_rezultat
        call function
        add esp, 4*3
        
        push dword [sir_rezultat]
        push dword format
        call [printf]
        add esp,4*2
        
    push dword 0
    call [exit]