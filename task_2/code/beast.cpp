//
// Created by Efim Verzakov on 16.10.2021.
//


#include "beast.h"

void Beast::In(std::ifstream &ifst) {
    ifst>>this->name>>this->weight;
    int type;
    ifst >> type;
    if (type == 1) {
        t = Beast::PREDATORS;
    } else if (type == 2) {
        t = Beast::HERBIVORES;
    } else {
        t = Beast::INSECTIVORES;
    }
}

void Beast::InRnd() {
    for (size_t i = 0; i < MAX_NAME_LEN; ++i) {
        this->name[i] = char('a' + (this->rnd26.Get()-1));
    }
    this->name[MAX_NAME_LEN - 1] = '\0';
    this->weight = Animal::rnd26.Get();
    int type = Animal::rnd3.Get();
    if (type == 1) {
        t = Beast::PREDATORS;
    } else if (type == 2) {
        t = Beast::HERBIVORES;
    } else {
        t = Beast::INSECTIVORES;
    }
}

void Beast::Out(std::ofstream &ofst) {
    ofst << "This is Beast: name = "<<this->name<<", weight = "<<this->weight<<", type = ";
    if (this->t == 0){
        ofst<<"PREDATORS";
    } else if (this->t == 1){
        ofst<<"HERBIVORES";
    } else if (this->t == 2){
        ofst<<"INSECTIVORES";
    }
    ofst<<", codes / weight = " << this->CodesDividedByWeight()<<"\n";
}

void Beast::OutInFile(std::ofstream &ofst) {
    ofst<<"\nbeast\n"<<this->name<<"\n"<<this->weight<<"\n"<<this->t;
}