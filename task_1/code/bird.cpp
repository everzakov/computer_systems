//------------------------------------------------------------------------------
// bird.cpp - содержит функции обработки для рыбы
//------------------------------------------------------------------------------

#include "bird.h"
#include "constants.h"
#include "rnd.h"

// Ввод параметров птицы из потока
void In(bird &b, std::ifstream &ifst) {
    ifst >> b.name >> b.weight;
    int flyRelationship;
    ifst >> flyRelationship;
    b.flyRelationship = flyRelationship;
}

void OutInFile(bird &b, std::ofstream &ofst){
    ofst << "bird\n" << b.name << "\n" << b.weight << "\n" << b.flyRelationship <<"\n";
}

// Случайный ввод параметров птицы
void InRnd(bird &b) {
    for (size_t i = 0; i < MAX_NAME_LEN; ++i) {
        b.name[i] = char('a' + Random());
    }
    b.name[MAX_NAME_LEN - 1] = '\0';
    b.weight = MIN_WEIGHT + Random();
    b.flyRelationship = Random() % 2;
}

// Вывод параметров птицы в форматируемый поток
void Out(bird &b, std::ofstream &ofst) {
    ofst << "It is Bird: name = "
         << b.name << ", weight = " << b.weight << ", flyRelationship = "
         << (b.flyRelationship ? "true" : "false")
         << ", codes / weight = " << CodesDividedByWeight(b) << "\n";
}

// Частное от деления суммы кодов незашифрованной строки на вес
double CodesDividedByWeight(bird &b) {
    int count = 0;
    for (int i = 0; i < strlen(b.name); ++i){
        count += int(b.name[i]);
    }
    return count * 1.0 / b.weight;
}