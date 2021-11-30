//
// Created by Efim Verzakov on 26.11.2021.
//

#include <stdio.h>

#include "extdata.h"

// Ввод параметров зверя из файла
void InBeast(void *b, FILE *ifst) {
    char name[MAX_NAME_LEN];
    fscanf(ifst, "%s", name);
    for (int i = 0; i<MAX_NAME_LEN - 1; i++){
        *((char*)(b + charSize * i)) = name[i];
    }
    *((char*)(b + charSize * (MAX_NAME_LEN-1))) = '\0';
    fscanf(ifst, "%d", (int*)(b + MAX_NAME_LEN * charSize));
    fscanf(ifst, "%d", (int*)(b + MAX_NAME_LEN * charSize + intSize));
}

// Ввод параметров птицы из файла
void InBird(void *b, FILE *ifst) {
    char name[MAX_NAME_LEN];
    fscanf(ifst, "%s", name);
    for (int i = 0; i<MAX_NAME_LEN - 1; i++){
        *((char*)(b + charSize * i)) = name[i];
    }
    *((char*)(b + charSize * (MAX_NAME_LEN-1))) = '\0';
    fscanf(ifst, "%d", (int*)(b + MAX_NAME_LEN * charSize));
    fscanf(ifst, "%d", (int*)(b + MAX_NAME_LEN * charSize + intSize));
}

// Ввод параметров рыбы из файла
void InFish(void *f, FILE *ifst) {
    char name[MAX_NAME_LEN];
    fscanf(ifst, "%s", name);
    for (int i = 0; i<MAX_NAME_LEN - 1; i++){
        *((char*)(f + charSize * i)) = name[i];
    }
    *((char*)(f + charSize * (MAX_NAME_LEN-1))) = '\0';
    fscanf(ifst, "%d", (int*)(f + MAX_NAME_LEN * charSize));
    fscanf(ifst, "%d", (int*)(f + MAX_NAME_LEN * charSize + intSize));
}

// Ввод параметров обобщенного животного из файла
int InAnimal(void *a, FILE *ifst) {
    int k;
    fscanf(ifst, "%d", &k);
    switch(k) {
        case 1:
            *((int*)a) = FISH;
            InFish(a + intSize, ifst);
            return 1;
        case 2:
            *((int*)a) = BIRD;
            InBird(a + intSize, ifst);
            return 1;
        case 3:
            *((int*)a) = BEAST;
            InBeast(a + intSize, ifst);
            return 1;
        default:
            return 0;
    }
}

// Ввод содержимого контейнера из указанного файла
void InContainer(void *c, int *len, FILE *ifst) {
    void *tmp = c;
    int size = 0;
    fscanf(ifst, "%d", &size);
    while(*len < size && !feof(ifst)) {
        if(InAnimal(tmp, ifst)) {
            tmp = tmp + animalSize;
            (*len)++;
        }
    }
}
