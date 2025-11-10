bits 32 
global start        
extern exit , fclose , fopen , scanf , fprintf          
import exit msvcrt.dll
import fclose msvcrt.dll   
import fopen msvcrt.dll   
import scanf msvcrt.dll    
import fprintf msvcrt.dll     
 
;A file name (defined in data segment) is given. Create a file with the given name,
;then read words from the keyboard until character '$' is read.
;Write only the words that contain at least one uppercase letter to file. 

segment data use32 class=data
   file db "file1.txt",0
   mode db "w",0
   read_f db "%s",0
   fd dd -1 ; file descriptor
   wordd resb 100 ; buffer for each word read 
   newline db 10,0 ;10 is the ascii code for Line Feed
   
segment code use32 class=code
    start:
        push dword mode
        push dword file
        call [fopen]
        add ESP, 4*2
        
        cmp eax,0 ; check if there was an error
        je end_program
        mov [fd],eax ; move the file descriptor in fd
       
        read_loop:
            push dword wordd ;the buffer for the string we read
            push dword read_f
            call [scanf]
            add ESP, 4*2
            mov ESI, wordd
            check_dollar:
            
                lodsb ; now in AL we have the first character of our word
                CMP al,'$' ; we check if the character is a dollar
                je end_loop ; if it is we get out of the loop
                CMP al,0  ; if we run out of characters we also need to stop
                je done
                jMP check_dollar ; we keep looking for the $ sign
                
                done:
                    ;now we need to check if the word has any uppercase letters
                    mov ESI,wordd
                    xor ECX,ECX ; we clear ecx; we will use it to count the amount of uppercase letters
                    check_uppercase:
                        lodsb ; in AL we have the first character
                        CMP AL,0 ; if we reach the end we need to stop
                        jz uppercse_check_done
                        CMP al,'A'
                        jl check_uppercase ; if the character is <A
                        CMP al,'Z'
                        jg check_uppercase ; if the character is >A
                        inc ECX ; We found an uppercase letter :)
                        jmp check_uppercase
                    uppercse_check_done:
                    CMP ECX,0
                    jz read_loop ; if there were no uppercase letters, we read the next word
                    ;otherwise we need to write it to the file
                    
                    push dword wordd
                    push dword [fd]
                    call [fprintf]
                    add ESP, 4*2
                    
                    ;we add a new line for readability
                    push dword newline
                    push dword [fd]
                    call [fprintf]
                    add ESP, 4*2 
                    
                    jmp read_loop
        end_loop:
        ;now we need to close the file:
        push dword [fd]
        call dword [fclose]
        add ESP,4
        
        end_program:
        push    dword 0      
        call    [exit]       
