extern printf
extern fprintf

extern CodesDividedByWeight

extern FISH
extern BIRD
extern BEAST
extern MAX_NAME_LEN
extern LEN_TO_PRINT


;    for (int i = 0; i<len; i++){
;        for (int j = i+1; j<len; j++){
;            if (CodesDividedByWeight(c+j*animalSize + intSize) > CodesDividedByWeight(c+i*animalSize + intSize)){
;                int tmp_weight = *((int *)(c+i*animalSize));
;                *((int *)(c+i*animalSize)) = *((int *)(c+j*animalSize));
;                *((int *)(c+j*animalSize)) = tmp_weight;
;
;                char tmp_char;
;                for (int z = 0; z<MAX_NAME_LEN; z++){
;                    tmp_char = *((char *)(c+i*animalSize+charSize*z + intSize));
;                    *((char *)(c+i*animalSize+charSize*z +intSize)) = *((char *)(c+j*animalSize+charSize*z +intSize));
;                    *((char *)(c+j*animalSize+charSize*z +intSize)) = tmp_char;
;                }
;
;                tmp_weight = *((int *)(c+i*animalSize+charSize*MAX_NAME_LEN + intSize));
;                *((int *)(c+i*animalSize+charSize*MAX_NAME_LEN +intSize)) = *((int *)(c+j*animalSize+charSize*MAX_NAME_LEN +intSize));
;                *((int *)(c+j*animalSize+charSize*MAX_NAME_LEN +intSize)) = tmp_weight;
;
;                tmp_weight = *((int *)(c+i*animalSize+charSize*MAX_NAME_LEN + 2*intSize));
;                *((int *)(c+i*animalSize+charSize*MAX_NAME_LEN +2*intSize)) = *((int *)(c+j*animalSize+charSize*MAX_NAME_LEN +2*intSize));
;                *((int *)(c+j*animalSize+charSize*MAX_NAME_LEN +2*intSize)) = tmp_weight;
;            }
;        }
;    }


global sort
sort:
section .bss
    .start  resq  1
    .i_name_start   resq  1
    .j_name_start   resq  1
section .text
    push rbp
    mov rbp, rsp

    mov [rel .start], rdi
    mov r9, rsi

    mov r10, r9
    mov r9, 0
    mov r11, 0

.loop:
    cmp r11, r10
    jge .cont
    add r9, 28
    inc r11
    jmp .loop

.cont:
    mov r10, 0
    mov r11, 0
    mov r12, 0
    mov r13, 0
    mov r14, 0
    mov r15, 0
.loopi:
    cmp r10, r9
    jge .return
    mov r11, r10
    add r11, 28

.loopj:
    cmp r11, r9
    jge .inci

    mov rdi, [rel .start]
    add rdi, r10
    mov [rel .i_name_start], rdi
    add rdi, 4


    call CodesDividedByWeight
    movsd xmm3, xmm0

    mov rdi, [rel .start]
    add rdi, r11
    mov [rel .j_name_start], rdi
    add rdi, 4
    call CodesDividedByWeight
    movsd xmm4, xmm0

    comisd xmm3, xmm4
    jae .incj

    mov rbx, [rel .i_name_start]
    mov r12, [rel .j_name_start]

    mov r15d, [rel rbx]
    mov r13d, [rel r12]
    mov [rel rbx], r13d
    mov [rel r12], r15d

    mov r15, [rel rbx + 4]
    mov r13, [rel r12 + 4]
    mov [rel rbx + 4], r13
    mov [rel r12 + 4], r15

    mov r15, [rel rbx + 12]
    mov r13, [rel r12 + 12]
    mov [rel rbx + 12], r13
    mov [rel r12 + 12], r15

    mov r15, [rel rbx + 20]
    mov r13, [rel r12 + 20]
    mov [rel rbx + 20], r13
    mov [rel r12 + 20], r15
    inc r14

.incj:
    add r11, 28
    jmp .loopj
.inci:
    add r10, 28
    jmp .loopi
.return:
    mov rax, r14
leave
ret