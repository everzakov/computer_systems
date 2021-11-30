;void sort(void *c, int len){
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
;}

global testFunc
section .text
testFunc:
push rbp
mov rbp, rsp
    mov rax, 0
leave
ret

global SortContainer
SortContainer:
section .text
push rbp
mov rbp, rsp
    mov rbx, rsi            ; число фигур
    xor rcx, rcx
return:
leave
ret