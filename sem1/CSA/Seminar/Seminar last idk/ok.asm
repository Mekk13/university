; The following code will create an empty file called "ana.txt" in the current folder,
; and it will write a text to this file.

; The program will use:
; - the function fopen() to open/create the file
; - the function fprintf() to write a text to file
; - the function fclose() to close the created file.

; Because the program uses the file access mode "w", if a file with the same name already
; exists, its contents will be discarded and the file will be treated as a new empty file.
; For details about the file access modes see the section "Theory".

bits 32

global start

; declare external functions needed by our program
extern exit, fopen, fclose,printf
import exit msvcrt.dll
import fopen msvcrt.dll
import printf msvcrt.dll
import fclose msvcrt.dll

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    format  db "It's semester %d, week %d of school.", 0 

; our code starts here
segment code use32 class=code
    start:
         push dword 8  ; pushing parameters on the stack
		 push dword 1 
		 push dword format  
		 call [printf]       ; calling the printf function
		 add esp, 4 * 3     ; cleaning the parameters from the stack
        ; exit(0)
        push dword 0      
        call [exit]
