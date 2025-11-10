bits 32
global function

segment data use32 class=data
    len dd 0
    sum dd 0    
    masca dd 0x0000000F
;parameters are pushed as follows: sir, len, result, call  
    
segment code use32 class=code
function:
    mov edi,[esp+4] ; the result array!
    mov eax,[esp+8]
    mov [len],eax
    mov esi,[esp+12] ;the source string is now in esi!!! :D
    
    mov ecx,[len]
    repeta:
        xor eax,eax
        lodsd ; now in eax we are loading the dd from esi and esi+=4
        push ecx
        xor ecx,ecx
        mov ecx,8
        xor edx,edx;this shall be used for the sum fr
        bucla:
            mov ebx,eax
            and ebx,[masca] ; now in bl we have our hexa digit! i think
            add dl,bl
            shr eax,4 ; moving to the next hexa digit frfr
        loop bucla
        mov ax,dx ; put the sum there fr
        stosw ; store the word in axx into edi, edi+=2
        pop ecx
        loop repeta
    
    ret