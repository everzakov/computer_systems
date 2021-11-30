//------------------------------------------------------------------------------
// output.c - единица компиляции, вбирающая в себя все функции вывода данных
//------------------------------------------------------------------------------

#include <stdio.h>

#include "extdata.h"
// Целевая функция для обощённого животного
double CodesDividedByWeight(void *a){
    double sum = 0;
    for (int i = 0; i<MAX_NAME_LEN-1; i++){
        sum+=*((char *)(a+i*charSize));
    }
    return sum/(*((int*)(a+MAX_NAME_LEN*charSize)));
}

// Вывод параметров зверя в файл
void OutBeast(void *r, FILE *ofst) {
    fprintf(ofst, "It is Beast: name: ");
    for (int i = 0; i<MAX_NAME_LEN-1; i++){
        fprintf(ofst, "%c",  *((char *)(r+i*charSize)));
    }
    fprintf(ofst, " ; weight: %d; type: ", *((int*)(r+MAX_NAME_LEN*charSize)));
    int t = *((int*)(r+MAX_NAME_LEN*charSize + intSize));
    if (t == PREDATORS){
        fprintf(ofst,"PREDATORS");
    }else if (t == HERBIVORES){
        fprintf(ofst,"HERBIVORES");
    }else if (t == INSECTIVORES){
        fprintf(ofst,"INSECTIVORES");
    }else{
        fprintf(ofst, "Incorrect Beast!");
    }
    fprintf(ofst, "; codes / weight: %f\n", CodesDividedByWeight(r));
}

// Вывод параметров птицы в файл
void OutBird(void *r, FILE *ofst) {
    fprintf(ofst, "It is Bird: name: ");
    for (int i = 0; i<MAX_NAME_LEN-1; i++){
        fprintf(ofst, "%c",  *((char *)(r+i*charSize)));
    }
    fprintf(ofst, " ; weight: %d; flyRelationship: ", *((int*)(r+MAX_NAME_LEN*charSize)));
    int t = *((int*)(r+MAX_NAME_LEN*charSize + intSize));
    if (t == TRUE){
        fprintf(ofst,"true");
    }else if (t == FALSE){
        fprintf(ofst,"false");
    }else{
        fprintf(ofst, "Incorrect Bird!");
    }
    fprintf(ofst, "; codes / weight: %f\n", CodesDividedByWeight(r));
}

// Вывод параметров рыбы в файл
void OutFish(void *r, FILE *ofst) {
    fprintf(ofst, "It is Fish: name: ");
    for (int i = 0; i<MAX_NAME_LEN-1; i++){
        fprintf(ofst, "%c",  *((char *)(r+i*charSize)));
    }
    fprintf(ofst, " ; weight: %d; place: ", *((int*)(r+MAX_NAME_LEN*charSize)));
    int t = *((int*)(r+MAX_NAME_LEN*charSize + intSize));
    if (t == RIVER){
        fprintf(ofst,"RIVER");
    }else if (t == SEA){
        fprintf(ofst,"SEA");
    }else if (t == LAKE){
        fprintf(ofst,"LAKE");
    }else{
        fprintf(ofst, "Incorrect Fish!");
    }
    fprintf(ofst, "; codes / weight: %f\n", CodesDividedByWeight(r));
}

// Вывод параметров текущего животного в файл
void OutAnimal(void *s, FILE *ofst) {
    int k = *((int*)s);
    if(k == FISH) {
        OutFish(s+intSize, ofst);
    }
    else if(k == BIRD) {
        OutBird(s+intSize, ofst);
    }
    else if(k == BEAST) {
        OutBeast(s+intSize, ofst);
    }
    else {
        fprintf(ofst, "Incorrect animal!\n");
    }
}

// Вывод содержимого контейнера в файл
void OutContainer(void *c, int len, FILE *ofst) {
    void *tmp = c;
    fprintf(ofst, "Container contains %d elements.\n", len);
    for(int i = 0; i < len; i++) {
        fprintf(ofst, "%d: ", i);
        OutAnimal(tmp, ofst);
        tmp = tmp + animalSize;
    }
}

// Вывод параметров зверя в файл
void OutBeastInFile(void *r, FILE *ofst) {
    for (int i = 0; i<MAX_NAME_LEN-1; i++){
        fprintf(ofst, "%c",  *((char *)(r+i*charSize)));
    }
    fprintf(ofst, "\n%d\n", *((int*)(r+MAX_NAME_LEN*charSize)));
    int t = *((int*)(r+MAX_NAME_LEN*charSize + intSize));
    if (t == PREDATORS){
        fprintf(ofst,"1\n");
    }else if (t == HERBIVORES){
        fprintf(ofst,"2\n");
    }else if (t == INSECTIVORES){
        fprintf(ofst,"3\n");
    }else{
        fprintf(ofst, "Incorrect Beast!");
    }
}

// Вывод параметров птицы в файл
void OutBirdInFile(void *r, FILE *ofst) {
    for (int i = 0; i<MAX_NAME_LEN-1; i++){
        fprintf(ofst, "%c",  *((char *)(r+i*charSize)));
    }
    fprintf(ofst, "\n%d\n", *((int*)(r+MAX_NAME_LEN*charSize)));
    int t = *((int*)(r+MAX_NAME_LEN*charSize + intSize));
    if (t == TRUE){
        fprintf(ofst,"0\n");
    }else if (t == FALSE){
        fprintf(ofst,"1\n");
    }else{
        fprintf(ofst, "Incorrect Bird!");
    }
}

// Вывод параметров рыбы в файл
void OutFishInFile(void *r, FILE *ofst) {
    for (int i = 0; i<MAX_NAME_LEN-1; i++){
        fprintf(ofst, "%c",  *((char *)(r+i*charSize)));
    }
    fprintf(ofst, "\n%d\n", *((int*)(r+MAX_NAME_LEN*charSize)));
    int t = *((int*)(r+MAX_NAME_LEN*charSize + intSize));
    if (t == RIVER){
        fprintf(ofst,"1\n");
    }else if (t == SEA){
        fprintf(ofst,"2\n");
    }else if (t == LAKE){
        fprintf(ofst,"3\n");
    }else{
        fprintf(ofst, "Incorrect Fish!");
    }
}

// Вывод параметров текущего животного в файл
void OutAnimalInFile(void *s, FILE *ofst) {
    int k = *((int*)s);
    if(k == FISH) {
        fprintf(ofst, "1\n");
        OutFishInFile(s+intSize, ofst);
    }
    else if(k == BIRD) {
        fprintf(ofst, "2\n");
        OutBirdInFile(s+intSize, ofst);
    }
    else if(k == BEAST) {
        fprintf(ofst, "3\n");
        OutBeastInFile(s+intSize, ofst);
    }
    else {
        fprintf(ofst, "Incorrect animal!\n");
    }
}

void OutContainerInFile(void *c, int len, FILE *ofst){
    void *tmp = c;
    fprintf(ofst, "%d\n", len);
    for(int i = 0; i < len; i++) {
        OutAnimalInFile(tmp, ofst);
        tmp = tmp + animalSize;
    }
}



void sort(void *c, int len){
    for (int i = 0; i<len; i++){
        for (int j = i+1; j<len; j++){
            if (CodesDividedByWeight(c+j*animalSize + intSize) > CodesDividedByWeight(c+i*animalSize + intSize)){
                int tmp_weight = *((int *)(c+i*animalSize));
                *((int *)(c+i*animalSize)) = *((int *)(c+j*animalSize));
                *((int *)(c+j*animalSize)) = tmp_weight;

                char tmp_char;
                for (int z = 0; z<MAX_NAME_LEN; z++){
                    tmp_char = *((char *)(c+i*animalSize+charSize*z + intSize));
                    *((char *)(c+i*animalSize+charSize*z +intSize)) = *((char *)(c+j*animalSize+charSize*z +intSize));
                    *((char *)(c+j*animalSize+charSize*z +intSize)) = tmp_char;
                }

                tmp_weight = *((int *)(c+i*animalSize+charSize*MAX_NAME_LEN + intSize));
                *((int *)(c+i*animalSize+charSize*MAX_NAME_LEN +intSize)) = *((int *)(c+j*animalSize+charSize*MAX_NAME_LEN +intSize));
                *((int *)(c+j*animalSize+charSize*MAX_NAME_LEN +intSize)) = tmp_weight;

                tmp_weight = *((int *)(c+i*animalSize+charSize*MAX_NAME_LEN + 2*intSize));
                *((int *)(c+i*animalSize+charSize*MAX_NAME_LEN +2*intSize)) = *((int *)(c+j*animalSize+charSize*MAX_NAME_LEN +2*intSize));
                *((int *)(c+j*animalSize+charSize*MAX_NAME_LEN +2*intSize)) = tmp_weight;
            }
        }
    }
}
