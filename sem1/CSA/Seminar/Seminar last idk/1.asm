bits 32 
global start        
extern exit               
import exit msvcrt.dll    
;write a program in asm that reads signed integers in base 10 from the keyboard until the number 0 is read, and stores them in an array (except the 0). 
;The program will build a new array of words by retaining bytes 2 and 0 from each integer of the initial array.
;The array of words will be sorted in descending order according to the number of bits 1 they contain. Print the resulted array of words in base 16.
;subprogram 1: reads integers
;subprogram 2: computes nr of bits 1 for a word

segment data use32 class=data
    array resd 100
    read_format db "%d ",0
    result resw 100
    count db 0
    num resd 1
    
segment code use32 class=code
    read: ; read(&array,&count)
        mov edi, [esp+4] 
        repeat:
            push dword num
            push dword read_format
            call [scanf]
            add esp, 4*2
            
            cmp dword [num], 0
            je end_loop
            mov eax,[num]
            stosd ; puts in edi eax. and adds 4 to edi.
            inc BL ; the value of count being formed
            jmp repeat
        end_loop:
        mov EAX,[esp+8]
        mov [eax],bl
        ret 4*2
    
    count1: ; count1( number) -> returns in eax the nr of bits 1
        mov EAX, [esp+4]
        mov ecx, 16
        mov BL,0
        counting:
            shr al,1
            jnc .dont
            inc BL
            .dont:
            loop counting:
        mov eax,0
        mov al,bl
        ret 4
        
    ;sort based on bits of 1:
    ;for i=0,n-2
    ;   for j=i,n-1
    ;       if count1(a[i]),count1(a[j])
    ;           swap(a[i],a[j])
    ;*
    
    start:
        push dword count
        push dword array
        call read
        mov ecx,[count]
        mov esi,array
        mov EDI, result 
        repeat2:
            lodsd ; eax gets the element forom esi, esi+4
            mov BL,AL
            shr EAX,8 ; now the high part (2nd byte) is in AH 
            mov AL,BL ; we put back byte 0
            stosw
            loop repeat2
        ;ax-a[i]
        ;bx-a[j]
        cwde; ax->eax
        push dword eax
        call count1
        mov dl,al
        mov ax,bx
        cwde
        push dword eax
        call count1
        mov sh,al
        cmp dl,dh
        jae noswap
        ;trebe implementata in * sufhuishka
        
        
        
        
        
        
        
        
        push    dword 0     
        call    [exit]       
