bits 32
global start        
extern exit,fopen,fclose,fread,fprintf               
import exit msvcrt.dll  
import fopen msvcrt.dll 
import fclose msvcrt.dll 
import fread msvcrt.dll
import fprintf msvcrt.dll

; Aia un text in fisier de forma
;<nume> are <un numar de o cifra> <obiecte>
;Trb sa scrii in fisier numele, cate caractere sunt in text, sa adaugi 10 la nr si sa spui daca e un nume de masculin sau feminin (pe principiul ca daca se gata cu a e feminin)

segment data use32 class=data
    fd1 dd -1
    fd2 dd -1
    filename1 db "write.txt",0
    filename2 db "file.txt",0
    format1 db "r",0
    format2 db "w",0
    len equ 100
    read_string times len db 0
    nr_in_file resb 1
    
    nume times 50 db 0
    nr_char resb 10
    numar resb 10 
    last_char_name db 0
    feminin db "feminin",0
    masculin db "masculin",0
    
    final_string times len db 0

segment code use32 class=code
    start:
        
        push dword format1
        push dword filename2
        call [fopen]
        add esp,4*2
        
        mov [fd1],eax
        cmp eax,0
        je final
        
        ;read from file
        push dword [fd1]
        push dword len
        push dword 1
        push dword read_string
        call [fread]
        add esp,4*4
        
        push dword [fd1]
        call [fclose]
        add esp,4
        
        mov EDI, nume
        mov ESI, read_string
        find_name:
            lodsb ;  in al the thing from esi, esi++
            add byte [nr_char],1
            cmp AL,' '
            je stop
            mov [last_char_name],AL ;at the end we will have the last character of the name in here
            stosb ; al goes in edi and edi +1
            jmp find_name
        stop:
            mov byte [edi],0 ; null terminator!
            ;gasisi numele intreg
            xor edi,edi
        jump_over:
            lodsb
            add byte [nr_char],1
            cmp AL,' '
            je gata
            jmp jump_over
        gata:
        ; now we're over the next word
        lodsb ;now we have the number in AL, but its ascii
        add byte [nr_char],1 ; count it 
        sub AL,'0'
        add AL,10 ; now we have a nr like 17 
        mov AH,0
        mov bl,10
        div bl ; in al we have quotient and ah remainder so , in al 1 and in ah 7
        add ah,'0'
        add al,'0'
        mov [numar],AL
        mov [numar+1],AH
        
        
        xor AX,AX
        count_final:
            lodsb
            cmp AL,0
            je over
            add byte [nr_char],1
            jmp count_final
        over:
        
        mov AL,[nr_char]
        sub AL,0
        mov AH,0
        mov BL,10
        div BL ; in AL qutient, AH - remainder
        add AH,'0'
        add AL,'0'
        mov [nr_char],AL
        mov [nr_char+1],AH
        
        ;build final string
        xor edi,edi
        xor esi,esi
        
        mov edi,final_string
        mov esi, nume
        add_name:
            lodsb  ; al gets stuff from esi, esi++
            cmp AL,0
            je next
            stosb ; moves AL to edi, edi++
            jmp add_name
        next:
        
        mov byte [edi],' '
        mov AL,[nr_char]
        mov AH, [nr_char+1]
        inc edi
        mov [edi],AL
        inc edi
        mov [edi],AH
        inc edi
        mov byte [edi],' '
        inc edi
        
        
        mov AL,[numar]
        mov AH,[numar+1]
        mov [edi],AL
        inc edi
        mov [edi],AH
        inc edi
        mov byte [edi],' '
        inc edi
        
        ;now we need to add fem or masc!
        xor esi,esi
        cmp byte [last_char_name],'a'
        je fem
        jne masc 
        
        fem:
            mov esi,feminin
            bucla:
                lodsb ; put in al, esi++
                cmp AL,0
                je stawhp
                stosb ; put it in edi,edi++
                jmp bucla
                
            stawhp:
                mov byte [edi],0
        
        jmp jump
            
        masc:
            mov esi,masculin
            bucla1:
                lodsb ; put in al, esi++
                cmp AL,0
                je stawhp1
                stosb ; put it in edi,edi++
                jmp bucla1
                
            stawhp1:
                mov byte [edi],0
        jump:
        ; now we have the final string and we must place it into a file!
        push dword format2
        push dword filename1
        call [fopen]
        add esp,4*2
        mov [fd2],eax
        cmp eax,0
        je final ; we opened the file!
        
        push dword final_string
        push dword [fd2]
        call [fprintf]
        add esp,4*2
        
        ;now close it
        push dword [fd2]
        call [fclose]
        add esp,4
        
        final:
        push    dword 0      
        call    [exit]