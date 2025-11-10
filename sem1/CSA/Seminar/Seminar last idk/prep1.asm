bits 32 
global start        
extern exit , fopen, fread,fprintf,fclose              
import exit msvcrt.dll  
import fopen msvcrt.dll
import fread msvcrt.dll
import fprintf msvcrt.dll
import fclose msvcrt.dll

segment data use32 class=data
    file_name1 db "file_read.txt",0 ;this must exist at start
    file_name2 db "file_write.txt",0 ; this will be created 
    file_descriptor1 dd -1
    file_descriptor2 dd -1
    access_mode1 db "r",0
    access_mode2 db "w",0
    len equ 100 
    text times len db 0
    
segment code use32 class=code
    start:
        push dword access_mode1
        push dword file_name1
        call [fopen]
        add esp, 4*2
        
        mov [file_descriptor1],eax ; store the file descriptor returned by fopen
        cmp eax, 0
        je final ; if we have an error the file desc. returned is 0 
        
        ;now we read from the file
        push dword [file_descriptor1] ;f.d. of file we read FROM
        push dword len ;amount of characters/things we read
        push dword 1 ; size of things we read
        push dword text ; location of string where the text is stored
        call [fread]
        add esp, 4*4 ; clear stack frfr
        
        ;now we close the file
        push dword [file_descriptor1]
        call [fclose]
        add esp,4
        
        ;great! now we need to write the text in another file b4 i kms
        ;first, open the destination file :"D
        
        push dword access_mode2 ; different access mode bc we wanna write in here
        push dword file_name2
        call [fopen]
        add esp,4*2
        
        mov [file_descriptor2],eax ; we get another file descriptor for the second file and store it
        cmp eax,0
        je final ;if error we piss off
        ;if not we continue our journey
        
        push dword text
        push dword [file_descriptor2] ; the f.d.for the file we want to write in
        call [fprintf]
        add esp, 4*2
        
        ;finally, we close the file we wrote in 
        push dword [file_descriptor2]
        call [fclose]
        add esp,4
        
        final:
        
        push    dword 0      
        call    [exit]       
