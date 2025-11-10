bits 32 

segment data use32 class=data
    len equ 100
    number times len db 0

segment code use32 public code
global function    

function:
    mov edi,number
    parse_digit:
            ;load char in AL
            lodsb ; AL=[esi], increment esi
            cmp al, 0 ; check end of string! We added a 0 manually 
            jne form_number
            mov CL,1 ; i cant use CF because it gets cleared later :c
            jmp space_encountered
            form_number:
                cmp al,' '
                je space_encountered
                stosb ; AL in es:edi and edi++
                jmp parse_digit
               
            space_encountered:
                ;now we have a full number :'D and we need to check even/odd
                ;first i wanna add a space and a null terminator to my number
                stosb ; mov whats AL in EDI and EDI++
                mov byte [edi],0
                xor AL,AL
                mov AL, [edi-2] ; we move the least significant byte into al
                sub AL,'0' ; we convert to integer
                test AL,1 ; we check even or odd! ZF=1 => number is even
                jz even_nr
                jmp odd_nr
                
            odd_nr:
                test al,al ; clearing ZF    
                push esi ; save the address of the main string
                mov esi,number
                mov edi,ebx
                
                copy_loop1:
                    cmp byte [esi],0
                    jz done_loop1
                    movsb ; the byte from the address of esi moves to the address of edi and they both increase
                    jmp copy_loop1
                    
                done_loop1:
                    test al,al ; clearing ZF 
                    pop esi
                    mov ebx,edi
                    mov edi,number
                    cmp CL,1
                    jz final
                    jmp parse_digit
                    
            
            even_nr:
                test al,al ; clearing ZF 
                push esi ; save the address of the main string
                mov esi,number
                mov edi,edx
                
                copy_loop:
                    mov AL,[esi]
                    cmp byte [esi],0
                    jz done_loop
                    movsb ; the byte from the address of esi moves to the address of edi and they both increase
                    jmp copy_loop
                    
                done_loop:
                    pop esi
                    mov edx,edi
                    mov edi,number
                    test al,al ; clearing ZF 
                    cmp CL,1
                    jz final
                    jmp parse_digit
    final:
        ret