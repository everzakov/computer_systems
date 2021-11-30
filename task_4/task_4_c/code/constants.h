//
// Created by Efim Verzakov on 26.11.2021.
//

#ifndef TASK_4_C_CONSTANTS_H
#define TASK_4_C_CONSTANTS_H
#include <stdio.h>
int const intSize = sizeof(int);
int const charSize = sizeof(char);
int const boolSize = sizeof(int);

int const MAX_NAME_LEN = 16;
int const MIN_WEIGHT = 1;

int const beastSize = 2*intSize + MAX_NAME_LEN*charSize;
int const PREDATORS = 1;
int const HERBIVORES = 2;
int const INSECTIVORES = 3;

int const birdSize = intSize+boolSize+MAX_NAME_LEN*charSize;
int const TRUE = 1;
int const FALSE = 0;
int const fishSize = 2*intSize + MAX_NAME_LEN*charSize;
int const RIVER = 1;
int const SEA = 2;
int const LAKE = 3;

int const animalSize = intSize + (beastSize >= birdSize ? (beastSize >= fishSize ? beastSize : fishSize) : (birdSize >= fishSize ? birdSize:fishSize));
int const FISH = 1;
int const BIRD = 2;
int const BEAST = 3;

int const maxSize = 10000*animalSize;
// Ввод содержимого контейнера из указанного файла
void InContainer(void *c, int *len, FILE *ifst);
// Случайный ввод содержимого контейнера
void InRndContainer(void *c, int *len, int size);
// Вывод содержимого контейнера в файл
void OutContainer(void *c, int len, FILE *ofst);
// Вывод содержимого контейнера в файл
void OutContainerInFile(void *c, int len, FILE *ofst);
double CodesDividedByWeight(void *a);
// Вычисление суммы периметров всех фигур в контейнере
void sort(void* c, int len);
#endif //TASK_4_C_CONSTANTS_H
