//------------------------------------------------------------------------------
// fish.cpp - содержит функции обработки для рыбы
//------------------------------------------------------------------------------

#include "fish.h"
#include "constants.h"
#include "rnd.h"
#include <cstring>

// Ввод параметров рыбы из потока
void In(fish &f, std::ifstream &ifst) {
    ifst >> f.name >> f.weight;
    int fishPlace;
    ifst >> fishPlace;
    if (fishPlace == 0) {
        f.p = fish::place::RIVER;
    } else if (fishPlace == 1) {
        f.p = fish::place::SEA;
    } else {
        f.p = fish::place::LAKE;
    }
}

void OutInFile(fish &f, std::ofstream &ofst){
    ofst << "fish\n" << f.name << "\n" << f.weight << "\n" << f.p <<"\n";
}

// Случайный ввод параметров рыбы
void InRnd(fish &f) {
    for (size_t i = 0; i < MAX_NAME_LEN; ++i) {
        f.name[i] = Random() + 'a';
    }
    f.name[MAX_NAME_LEN - 1] = '\0';
    f.weight = MIN_WEIGHT + Random();
    int fishPlace = Random() % 3;
    if (fishPlace == 0) {
        f.p = fish::place::RIVER;
    } else if (fishPlace == 1) {
        f.p = fish::place::SEA;
    } else {
        f.p = fish::place::LAKE;
    }
}

// Вывод параметров рыбы в форматируемый поток
void Out(fish &f, std::ofstream &ofst) {
    ofst << "It is Fish: name = "
         << f.name << ", weight = " << f.weight << ", place = ";
    if (f.p == 0) {
        ofst << "RIVER";
    } else if (f.p == 1) {
        ofst << "SEA";
    } else {
        ofst << "LAKE";
    }
    ofst << ", codes / weight = " << CodesDividedByWeight(f) << "\n";
}

// Частное от деления суммы кодов незашифрованной строки на вес
double CodesDividedByWeight(fish &f) {
    int count = 0;
    for (int i = 0; i < strlen(f.name); ++i){
        count += int(f.name[i]);
    }
    return count * 1.0 / f.weight;
}