#ifndef __fish__
#define __fish__

//------------------------------------------------------------------------------
// fish.h - содержит описание рыбы  и её интерфейса
//------------------------------------------------------------------------------

#include <fstream>
#include "rnd.h"
#include "constants.h"

// Рыба
struct fish {
    // Имя с максимально длиной
    char name[MAX_NAME_LEN];

    // Вес рыбы
    int weight;

    // Местро проживания рыбы
    enum place {RIVER, SEA, LAKE};
    place p;
};

// Ввод параметров Рыбы из файла
void In(fish &f, std::ifstream &ifst);

// Случайный ввод параметров рыбы
void InRnd(fish &f);

// Вывод параметров рыбы в форматируемый поток
void Out(fish &f, std::ofstream &ofst);

void OutInFile(fish &f, std::ofstream &ofst);

// Частное от деления суммы кодов незашифрованной строки на вес
double CodesDividedByWeight(fish &f);

#endif //__fish__