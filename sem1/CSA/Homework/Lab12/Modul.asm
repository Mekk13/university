bits 32
global _find_minimum

segment data use32 class=data
segment code use32 class=code
    _find_minimum:
        ; Input: 
        ;    [esp+4] = pointer to numbers (int array)
        ;    [esp+8] = n (number of elements in the array)

        ; Initialize min to INT_MAX (0x7FFFFFFF)
        mov eax, 0x7FFFFFFF    ; min = INT_MAX (0x7FFFFFFF)
        mov ebx, [esp + 8]     ; Load n (number of elements) into ebx
        xor ecx, ecx           ; Initialize loop counter i = 0

        loop_start:
            cmp ecx, ebx          ; Compare i (ecx) with n (ebx)
            jge end_loop          ; If i >= n, jump to end

            ; Load numbers[i] into edx
            mov edx, [esp + 4]     ; Load address of numbers
            mov esi, [edx + ecx*4] ; Load numbers[i] into esi (4-byte integer)

            ; Compare numbers[i] with min (eax)
            cmp esi, eax           ; Compare numbers[i] (esi) with min (eax)
            jge next_iteration    ; If numbers[i] >= min, skip update

            ; Update min = numbers[i]
            mov eax, esi           ; Update min (eax) with numbers[i] (esi)

            next_iteration:
                inc ecx                 ; Increment loop counter i
                jmp loop_start         ; Continue to next iteration

            end_loop:
        ret                     ; Return, eax holds the minimum value
