#ifndef __beast__
#define __beast__

//------------------------------------------------------------------------------
// beast.h - содержит описание зверей и их интерфейса
//------------------------------------------------------------------------------

#include <fstream>
#include "rnd.h"
#include "constants.h"

// Звери
struct beast {
    // Имя с максимально длиной
    char name[MAX_NAME_LEN];

    // Вес зверей
    int weight;

    enum type {PREDATORS, HERBIVORES, INSECTIVORES};
    type t;
};

// Ввод параметров зверей из файла
void In(beast &b, std::ifstream &ifst);

// Случайный ввод параметров зверей
void InRnd(beast &b);

// Вывод параметров зверей в форматируемый поток
void Out(beast &b, std::ofstream &ofst);

void OutInFile(beast &b, std::ofstream &ofst);

// Частное от деления суммы кодов незашифрованной строки на вес
double CodesDividedByWeight(beast &b);

#endif //__beast__