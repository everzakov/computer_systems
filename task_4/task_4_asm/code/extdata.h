

//------------------------------------------------------------------------------
// extdata.h - Описание внешних данных
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Раздел констант
//------------------------------------------------------------------------------
#ifndef __data__
#define __data__
int const intSize;
int const charSize;
int const boolSize;

int const MAX_NAME_LEN;
int const MIN_WEIGHT;

int const LEN_TO_PRINT;

int const beastSize;
int const PREDATORS;
int const HERBIVORES;
int const INSECTIVORES;

int const birdSize;
int const TRUE;
int const FALSE;
int const fishSize;
int const RIVER;
int const SEA;
int const LAKE;

int const animalSize;
int const FISH;
int const BIRD;
int const BEAST;

int const maxSize;

//------------------------------------------------------------------------------
// Раздел данных
//------------------------------------------------------------------------------

// Количество элементов в массиве
// external int len;

//------------------------------------------------------------------------------
// Раздел выделяемой памяти
//------------------------------------------------------------------------------

// Массив используемый для хранения данных
//external int cont[];



//------------------------------------------------------------------------------
// Описание используемых функций
//------------------------------------------------------------------------------

// Ввод содержимого контейнера из указанного файла
//void InContainer(void *c, int *len, FILE *ifst);
// Случайный ввод содержимого контейнера
//void InRndContainer(void *c, int *len, int size);
// Вывод содержимого контейнера в файл
//void OutContainer(void *c, int len, FILE *ofst);
// Вычисление суммы периметров всех фигур в контейнере
//double PerimeterSumContainer(void *c, int len);

#endif