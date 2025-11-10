bits 32 
global start        
extern exit,scanf,printf      
import exit msvcrt.dll  
import scanf msvcrt.dll
import printf msvcrt.dll
  
;Two numbers a and b are given. Compute the expression value: (a-b)*k, where k is a constant value defined in data segment. 
;Display the expression value (in base 16). 

segment data use32 class=data
   a dd 0
   b dd 0
   k db 7 
   read_f db "%d",0
   print_f db "%x in hexadecimal",0
   
segment code use32 class=code
    start:
        push dword a ; push the address bc printf expects an address
        push dword read_f
        call [scanf]
        add esp,4*2
        
        push dword b 
        push dword read_f
        call [scanf]
        add esp,4*2
        
        mov EAX,[a]
        sub EAX,[b]
        mov EBX,EAX
        xor EAX,EAX
        mov AL,[k]
        cbw
        cwd
        imul EBX ; in EDX:EAX we now have (a-b)*k
        
        push EAX
        push dword print_f
        call [printf]
        add ESP, 4*2
       
        push    dword 0      
        call    [exit]       
