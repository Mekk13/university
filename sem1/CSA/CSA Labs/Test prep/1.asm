bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, fscanf, fopen, fclose, printf               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
import fclose msvcrt.dll
import fopen msvcrt.dll
import fscanf msvcrt.dll
import printf msvcrt.dll

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    file_name db "wordsfile.txt", 0
    mode db "r", 0
    fd dd -1
    
    read_format db "%s are %d %s", 0
    write_format1 db "%s female %d %s", 0
    write_format2 db "%c male %d %s", 0
    
    nume times 100 db 0
    numar dd 0
    obiect times 100 db 0
    keep db 0
; our code starts here
segment code use32 class=code
    start:
        ; ...
        push dword mode
        push dword file_name
        call [fopen]
        add esp, 4*2
        
        mov [fd], eax
        cmp eax, 0
        je final
        
        push dword obiect
        push dword numar
        push dword nume
        push dword read_format
        push dword [fd]
        call [fscanf]
        add esp, 4*4
        
        mov esi, nume
        repeat_name:
            lodsb 
            cmp al, ' '
            je final_name
            mov [keep], al
            jmp repeat_name
        
        final_name:
            mov bl, [keep]
            cmp bl, 'a'
            jne male
            
        mov ebx, [numar]
        add ebx, byte 10
        mov [numar], ebx
            
        push dword obiect 
        push dword [numar]
        push dword nume
        push dword write_format1
        call [printf]
        add esp, 4*3
        jmp final
        
        male:
            push dword obiect 
            push dword [numar]
            push dword nume
            push dword write_format2
            call [printf]
            add esp, 4*3
            
        
        final:
            push dword [fd]
            call [fclose]
            add esp, 4
            
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
