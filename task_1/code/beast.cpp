//------------------------------------------------------------------------------
// beast.cpp - содержит функции обработки для рыбы
//------------------------------------------------------------------------------

#include "beast.h"
#include "constants.h"
#include "rnd.h"
#include <cstring>

// Ввод параметров зверей из потока
void In(beast &b, std::ifstream &ifst) {
    ifst >> b.name >> b.weight;
    int beastType;
    ifst >> beastType;
    if (beastType == 0) {
        b.t = beast::type::PREDATORS;
    } else if (beastType == 1) {
        b.t = beast::type::HERBIVORES;
    } else {
        b.t = beast::type::INSECTIVORES;
    }
}

void OutInFile(beast &b, std::ofstream &ofst){
    ofst << "beast\n" << b.name << "\n" << b.weight << "\n" << b.t <<"\n";
}

// Случайный ввод параметров зверей
void InRnd(beast &b) {
    for (size_t i = 0; i < MAX_NAME_LEN; ++i) {
        b.name[i] = char('a' + Random());
    }
    b.name[MAX_NAME_LEN - 1] = '\0';
    b.weight = MIN_WEIGHT + Random();
    int beastType = Random() % 3;
    if (beastType == 0) {
        b.t = beast::type::PREDATORS;
    } else if (beastType == 1) {
        b.t = beast::type::HERBIVORES;
    } else {
        b.t = beast::type::INSECTIVORES;
    }
}

// Вывод параметров зверей в форматируемый поток
void Out(beast &b, std::ofstream &ofst) {
    ofst << "It is Beast: name = "
         << b.name << ", weight = " << b.weight << ", type = ";
    if (b.t == 0) {
        ofst << "PREDATORS";
    } else if (b.t == 1) {
        ofst << "HERBIVORES";
    } else {
        ofst << "INSECTIVORES";
    }
    ofst << ", codes / weight = " << CodesDividedByWeight(b) << "\n";
}

// Частное от деления суммы кодов незашифрованной строки на вес
double CodesDividedByWeight(beast &b) {
    int count = 0;
    for (int i = 0; i < strlen(b.name); ++i){
        count += int(b.name[i]);
    }
    return count * 1.0 / b.weight;
}