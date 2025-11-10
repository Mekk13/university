bits  32
global start
extern exit,printf
import exit msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    string dd 1234A678h,12785634h,1A4D3C26h,0
    ;or len equ ($-string)/4
    result resw 20 
    counter dd 0
    format db "%d",0
    
segment code use32 class=code
    start:
        mov esi,string
        mov edi,result
        xor edx,edx
        
        process:
            lodsd ; in eax a dd from string and esi +4
            test eax,eax
            jz over
            
            mov bl,ah ; keep the high part of the low word
            shr eax,16 ; shift so now we have the high part of the high word in ah
            mov al,bl ; place the lower part
            stosw ; the word goes into edi and edi+=2
            
            
            mov ecx,16
            count_1s:
                shr ax,1
                adc dx,0
                loop count_1s
            jmp process
            
        over:
        mov [counter],dx
        
        push dword [counter]
        push dword format
        call [printf]
        
        add esp,4*3
        
        
        
        push dword 0
        call [exit]