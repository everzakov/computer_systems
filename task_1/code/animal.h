#ifndef __animal__
#define __animal__

//------------------------------------------------------------------------------
// animal.h - содержит описание обобщающего животного
//------------------------------------------------------------------------------

#include "fish.h"
#include "bird.h"
#include "beast.h"

//------------------------------------------------------------------------------
// структура, обобщающая все имеющихся животных
struct animal {
    // значения ключей для каждого из животных
    enum key {FISH, BIRD, BEAST};
    key k; // ключ
    // используемые альтернативы
    union { // используем простейшую реализацию
        fish f;
        bird br;
        beast bs;
    };
};

// Ввод обобщенного животного
animal * In(std::ifstream &ifdt);

// Случайный ввод обобщенного животного
animal *InRnd();

// Вывод обобщенного животного
void Out(animal &a, std::ofstream &ofst);

void OutInFile(animal &a, std::ofstream &ofst);

// Частное от деления суммы кодов незашифрованной строки на вес
double CodesDividedByWeight(animal &b);

#endif //__animal__