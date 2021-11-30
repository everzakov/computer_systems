//------------------------------------------------------------------------------
// animal.cpp - содержит процедуры связанные с обработкой обобщенного животного
// и создания произвольного животного (Рыбы, Птицы, Звери)
//------------------------------------------------------------------------------

#include "animal.h"
#include "string.h"

//------------------------------------------------------------------------------
// Ввод параметров обобщенного животного из файла
animal* In(std::ifstream &ifst) {
    animal *an;
    char type[MAX_NAME_LEN];
    ifst >> type;
    if (!strcmp(type, "fish")) {
        an = new animal;
        an->k = animal::FISH;
        In(an->f, ifst);
    } else if (!strcmp(type, "bird")) {
        an = new animal;
        an->k = animal::BIRD;
        In(an->br, ifst);
    } else if (!strcmp(type, "beast")) {
        an = new animal;
        an->k = animal::BEAST;
        In(an->bs, ifst);
    } else {
        printf("ERROR: Wrong animal type %s", type);
        exit(1);
    }
    return an;
}

void OutInFile(animal &an, std::ofstream &ofst){
    if (an.k == animal::BIRD){
        OutInFile(an.br, ofst);
    }else if (an.k == animal::BEAST){
        OutInFile(an.bs, ofst);
    }else if (an.k == animal::FISH){
        OutInFile(an.f, ofst);
    }
}

// Случайный ввод обобщенного животного
animal* InRnd() {
    animal *an;
    int animalType = rand() % 3;
    if (animalType == 0) {
        an = new animal;
        an->k = animal::FISH;
        InRnd(an->f);
    } else if (animalType == 1) {
        an = new animal;
        an->k = animal::BIRD;
        InRnd(an->br);
    } else {
        an = new animal;
        an->k = animal::BEAST;
        InRnd(an->bs);
    }
    return an;
}

// Вывод параметров текущего животного в поток
void Out(animal &an, std::ofstream &ofst) {
    switch (an.k) {
        case animal::FISH:
            Out(an.f, ofst);
            break;
        case animal::BIRD:
            Out(an.br, ofst);
            break;
        case animal::BEAST:
            Out(an.bs, ofst);
            break;
        default:
            ofst << "Incorrect animal type!\n";
    }
}

// Частное от деления суммы кодов незашифрованной строки на вес (действительное число)
double CodesDividedByWeight(animal &an) {
    switch (an.k) {
        case animal::FISH:
            return CodesDividedByWeight(an.f);
        case animal::BIRD:
            return CodesDividedByWeight(an.br);
        case animal::BEAST:
            return CodesDividedByWeight(an.bs);
        default:
            return 0;
    }
}