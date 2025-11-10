bits 32
global start        
extern exit,fopen,fclose,fscanf,fprintf               
import exit msvcrt.dll  
import fopen msvcrt.dll 
import fclose msvcrt.dll 
import fscanf msvcrt.dll
import fprintf msvcrt.dll


segment data use32 class=data
    fd1 dd -1
    fd2 dd -1
    filename1 db "read.txt",0
    filename2 db "write.txt",0
    openformat1 db "r",0
    openformat2 db "w",0
    readformat db "%s are %d %s",0
    writefem db "%s female %d %s",0
    writemasc db "%s male %d %s",0
    
    obiect times 100 db 0
    nr dd 0
    nombre times 100 db 0
    
    
segment code use32 class=code
    start:
        push dword openformat1
        push dword filename1
        call [fopen]
        add esp,4*2
        mov [fd1],eax
        
        cmp eax, 0
        je final
        
        push dword obiect
        push dword nr
        push dword nombre
        push dword readformat
        push dword [fd1]
        call [fscanf]
        add esp,4*5
        
        push dword [fd1]
        call [fclose]
        add esp, 4
        
        mov eax,[nr]
        add eax,10
        mov [nr],eax
        
        push dword openformat2
        push dword filename2
        call [fopen]
        add esp,4*2
        
        mov [fd2],eax
        cmp eax, 0
        je final
        
        push dword obiect
        push dword [nr]
        push dword nombre
        push dword writefem
        push dword [fd2]
        call [fprintf]
        add esp, 4*5
        
        push dword [fd2]
        call [fclose]
        add esp,4
        
        
        final:
        push    dword 0      
        call    [exit]       
