bits 32
global start
extern exit,printf
import exit msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    
    b db 'z','s','x','a',0
    lenb equ $-b
    format db "%s",0
    
    
segment code use32 class=code
    start:
        mov ecx, lenb-2
        mov esi,0
        mov edi, b
        
        jecxz over
        
        outer_loop:
            mov al, [b+esi]
            mov edi,esi
            add edi,1
            push ecx
            jecxz end_il
            
            inner_loop:
                mov ah,[b+edi]
                cmp al,ah
                jle dont_swap
                
                mov [b+esi],ah
                mov [b+edi],al
                mov al,ah
                
                dont_swap:
                inc edi
            loop inner_loop    
            end_il:
            inc esi
            pop ecx
            loop outer_loop

    over:
    
    push dword b
    push dword format
    call [printf]
    add esp, 4*2
    
    push dword 0
    call [exit]