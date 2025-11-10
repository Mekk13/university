bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, fscanf, printf, fopen, fclose               ; tell nasm that exit exists even if we won't be defining it
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
    
    read_word_format db "%s", 0
    read_char_format db "%c", 0
    write_foramt db "%s ", 0
    
    string times 100 db 0
    char db 0
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        push dword mode
        push dword file_name
        call [fopen]
        add esp, 4*2
        
        cmp eax, 0
        je final
        
        mov [fd], eax
        
        push dword char
        push dword read_char_format
        push dword [fd]
        call [fscanf]
        add esp, 4*3
        
        mov bl, [char]
        
        citire:
            push dword string
            push dword read_word_format
            push dword [fd]
            call [fscanf]
            add esp, 4*3
            
            cmp [string], byte 0
            je final
            
            mov esi, string
            mov ecx, 0
            verifica_cuvant:
                lodsb
                cmp al, byte 0
                je printare
                
                cmp al, [char]
                jne skip
                
                inc ecx
                skip:
                
                jmp verifica_cuvant
            
            printare:
                cmp ecx, 3
                jne noprint
                
                push dword string
                push dword write_foramt
                call [printf]
                add esp, 4*2
                noprint:
                
            jmp citire
        jmp final   
            
        push dword [fd]
        call [fclose]
        add esp, 4
        final:
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program