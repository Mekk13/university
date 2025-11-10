bits 32 
global start        
extern exit, fopen, fread, fclose , printf       
import exit msvcrt.dll    
import fopen msvcrt.dll
import fclose msvcrt.dll
import fread msvcrt.dll
import printf msvcrt.dll
extern function

segment data use32 class=data
    file_name db "fisier.txt",0 
    file_descriptor dd -1
    access_mode db "r",0
    len equ 100 ; i'm gonna read at most 100 characters
    number_string times len db 0 ;string to hold the numbers read
    
    even_numbers times len db 0
    odd_numbers times len db 0
    format db "%s",0 ; format for print
    newline db 10,0 ; format for a new line hehe

    auxiliar dd 0
    
segment code use32 class=code
    start:
        
        ;open file
        ; eax = fopen(file_name, access_mode)
        push dword access_mode
        push dword file_name
        call [fopen]
        add esp, 4*2
        
        ;check error
        mov [file_descriptor],eax
        cmp eax,0
        je final
        
        ; read from file
        ; eax = fread(text, 1, len, file_descriptor)
        push dword [file_descriptor]
        push dword len
        push dword 1 ;size of each element to read
        push dword number_string
        call [fread]
        add esp, 4*4
       
        ;manually add a null terminator 
        mov ecx,eax ; in ecx we now have the nr of bytes read
        mov byte[number_string+ecx],0
        
        ;close file
        push dword [file_descriptor]
        call [fclose]
        add esp, 4
        
        ;move the number sting address to esi
        mov ESI,number_string
        xor ECX,ECX
        xor EBX,EBX
        
        mov edx,even_numbers
        mov ebx,odd_numbers
       
        call function
            
        final:
            ;print the resulting strings
            push dword even_numbers
            push dword format
            call [printf]
            add esp, 4*2
        
            push dword newline
            call [printf]
            add esp,4
        
            push dword odd_numbers
            push dword format
            call [printf]
            add esp, 4*2
            
        push    dword 0      
        call    [exit]       
