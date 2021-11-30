//
// Created by Efim Verzakov on 26.11.2021.
//

#include <stdlib.h>
#include <stdio.h>

#include "extdata.h"

// rnd.c - содержит генератор случайных чисел в диапазоне от 0 до 25
int Random26() {
    return rand() % 26;
}

int Random3(){
    return rand() % 3 + 1;
}

int Random2(){
    return rand()%2;
};

// Случайный ввод параметров зверя
void InRndBeast(void *r) {
    for (int i = 0; i<MAX_NAME_LEN-1; i++){
        *((char*)(r+i*charSize)) = Random26() + 'a';
    }
    *((char*)(r+(MAX_NAME_LEN-1)*charSize)) = '\0';
    printf("beast\n%s", ((char*)(r)));

    *((int*)(r+MAX_NAME_LEN*charSize)) = MIN_WEIGHT + Random26();
    *((int*)(r+MAX_NAME_LEN*charSize + intSize)) = Random3();
    printf("\n%d\n%d\n", *((int*)(r+MAX_NAME_LEN*charSize)), *((int*)(r+MAX_NAME_LEN*charSize + intSize)));
//     printf("    Rectangle %d %d\n", *((int*)r), *((int*)r+1));
}

// Случайный ввод параметров птицы
void InRndBird(void *r) {
    for (int i = 0; i<MAX_NAME_LEN-1; i++){
        *((char*)(r+i*charSize)) = Random26() + 'a';
    }
    *((char*)(r+(MAX_NAME_LEN-1)*charSize)) = '\0';
    printf("bird\n%s", ((char*)(r)));

    *((int*)(r+MAX_NAME_LEN*charSize)) = MIN_WEIGHT + Random26();
    *((int*)(r+MAX_NAME_LEN*charSize + intSize)) = Random2();
    printf("\n%d\n%d\n", *((int*)(r+MAX_NAME_LEN*charSize)), *((int*)(r+MAX_NAME_LEN*charSize + intSize)));
//     printf("    Rectangle %d %d\n", *((int*)r), *((int*)r+1));
}

// Случайный ввод параметров рыбы
void InRndFish(void *r) {
    for (int i = 0; i<MAX_NAME_LEN-1; i++){
        *((char*)(r+i*charSize)) = Random26() + 'a';
    }
    *((char*)(r+(MAX_NAME_LEN-1)*charSize)) = '\0';
    printf("fish\n%s", ((char*)(r)));


    *((int*)(r+MAX_NAME_LEN*charSize)) = MIN_WEIGHT + Random26();
    *((int*)(r+MAX_NAME_LEN*charSize + intSize)) = Random3();
    printf("\n%d\n%d\n", *((int*)(r+MAX_NAME_LEN*charSize)), *((int*)(r+MAX_NAME_LEN*charSize + intSize)));
//     printf("    Rectangle %d %d\n", *((int*)r), *((int*)r+1));
}

// Случайный ввод обобщенного животного
int InRndShape(void *s) {
    int k = Random3();
    switch(k) {
        case 1:
            *((int*)s) = FISH;
            InRndFish(s+intSize);
            return 1;
        case 2:
            *((int*)s) = BIRD;
            InRndBird(s+intSize);
            return 1;
        case 3:
            *((int*)s) = BEAST;
            InRndBeast(s+intSize);
            return 1;
        default:
            return 0;
    }
}

// Случайный ввод содержимого контейнера
void InRndContainer(void *c, int *len, int size) {
    void *tmp = c;
    while(*len < size) {
        if(InRndShape(tmp)) {
            tmp = tmp + animalSize;
            (*len)++;
        }
    }
}
