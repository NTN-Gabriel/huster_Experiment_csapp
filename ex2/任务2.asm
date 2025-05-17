.686P
.model flat, c
printf proto c :ptr sbyte, :vararg
includelib  libcmt.lib
includelib  legacy_stdio_definitions.lib 

student  struct
    sname   db   8 dup(0)
    sid     db   11 dup(0)
    scores  dw   8  dup(0)
    average dw   0
student   ends

.data
   lpfmt  db "%s %s %d %d",0dh,0ah,0
   lpfmt_string  db "%s  ",0
   lpfmt_num  db "%d  ",0

.code
computeAverageScore2 proc
    push ebp
    mov ebp, esp
    push eax
    push esi
    push edi
    push ebx

    mov esi, [ebp+8]
    mov ecx, [ebp+12]
    test ecx, ecx
    jz done

student_loop:
    mov eax, 0
    lea edi, [esi+19]

    mov ebx, 8
score_loop:
    movsx edx, word ptr [edi]
    add eax, edx
    add edi, 2
    dec ebx
    jnz score_loop

    cdq
    mov ebx, 8
    idiv ebx
    mov [esi+35], ax
    add esi, 37
    dec ecx
    jnz student_loop

done:
    pop ebx
    pop edi
    pop esi
    pop eax
    pop ebp
    ret
computeAverageScore2 endp



computeAverageScore3 proc
    push ebp
    mov ebp, esp
    push eax
    push ecx
    push edx
    push esi
    push edi
    push ebx

    mov esi, [ebp+8]
    mov ecx, [ebp+12]
    test ecx, ecx
    jz done

student_loop:
    lea  edi, [esi + 19]

    movsx eax, word ptr [edi] 
    movsx ebx, word ptr [edi+2]
    movsx edx, word ptr [edi+4]
    add eax, ebx
    movsx ebx, word ptr [edi+6]
    add edx, ebx
    add eax, edx
    movsx ebx, word ptr [edi+8]
    movsx edx, word ptr [edi+10]
    add eax, ebx
    movsx ebx, word ptr [edi+12]
    add eax, edx
    add eax, ebx
    movsx ebx, word ptr [edi+14]
    add eax, ebx

    shr eax, 3
    mov [esi + 35], ax
    add esi, 37
    dec ecx
    jnz student_loop

done:
    pop ebx
    pop edi
    pop esi
    pop edx
    pop ecx
    pop eax
    pop ebp
    ret
computeAverageScore3 endp

end