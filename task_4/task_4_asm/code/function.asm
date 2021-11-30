extern printf
extern fprintf

extern FISH
extern BIRD
extern BEAST
extern LEN_TO_PRINT
extern charSize
extern nameSize

;// Целевая функция для обощённого животного
;double CodesDividedByWeight(void *a){
;  double sum = 0;
;  for (int i = 0; i<MAX_NAME_LEN-1; i++){
;    sum+=*((char *)(a+i*charSize));
;  }
;  return sum/(*((int*)(a+MAX_NAME_LEN*charSize)));
;}



global CodesDividedByWeight
CodesDividedByWeight:
section .data
    .sum    dq  0.0
    .check  dq  1.0
    .outfmt db "i = %d",10,0
section .bss
  .prect  resq  1
section .text
    push rbp
    mov rbp, rsp

    mov ebx, [rel LEN_TO_PRINT]
    mov edx, 0
    xor r8, r8
    movsd xmm1, [rel .sum]

    mov     [rel .prect], rdi
.loop:
    cmp edx, [rel LEN_TO_PRINT]
    jge .return

    mov al, [rel rdi]

    add rdi, 1        ; адрес следующей фигуры

    xor r8, r8
    movzx r8, al

    cvtsi2sd    xmm0, r8
    addsd xmm1, xmm0
    inc edx

    jmp .loop


.return:
    mov  rdi, [rel .prect]
    add rdi, 16
    xor edx, edx
    mov edx, [rel rdi]
    cvtsi2sd xmm2, edx
    divsd xmm1, xmm2
    movsd xmm0, xmm1
leave
ret