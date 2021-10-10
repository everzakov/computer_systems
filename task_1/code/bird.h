#ifndef __bird__
#define __bird__

//------------------------------------------------------------------------------
// bird.h - содержит описание птицы  и её интерфейса
//------------------------------------------------------------------------------

#include <fstream>
#include "rnd.h"
#include "constants.h"

// Птица
struct bird {
    // Имя с максимально длиной
    char name[MAX_NAME_LEN];

    // Вес птицы
    int weight;

    // Отношение к передёту
    bool flyRelationship;
};

// Ввод параметров Птицы из файла
void In(bird &b, std::ifstream &ifst);

// Случайный ввод параметров птицы
void InRnd(bird &b);

// Вывод параметров птицы в форматируемый поток
void Out(bird &b, std::ofstream &ofst);

void OutInFile(bird &b, std::ofstream &ofst);

// Частное от деления суммы кодов незашифрованной строки на вес
double CodesDividedByWeight(bird &b);

#endif //__bird__