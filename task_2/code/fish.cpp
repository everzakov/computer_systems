//
// Created by Efim Verzakov on 16.10.2021.
//

#include "fish.h"

void Fish::In(std::ifstream &ifst) {
    ifst>>this->name>>this->weight;
    int type;
    ifst >> type;
    if (type == 1) {
        p = Fish::RIVER;
    } else if (type == 2) {
        p = Fish::SEA;
    } else {
        p = Fish::LAKE;
    }
}

void Fish::InRnd() {
    for (size_t i = 0; i < MAX_NAME_LEN; ++i) {
        this->name[i] = char('a' + (this->rnd26.Get()-1));
    }
    this->name[MAX_NAME_LEN - 1] = '\0';
    this->weight = Animal::rnd26.Get();
    int type = Animal::rnd3.Get();
    if (type == 1) {
        p = Fish::RIVER;
    } else if (type == 2) {
        p = Fish::SEA;
    } else {
        p = Fish::LAKE;
    }
}

void Fish::Out(std::ofstream &ofst) {
    ofst << "This is Fish: name = "<<this->name<<", weight = "<<this->weight<<", place = ";
    if (this->p == 0){
        ofst<<"RIVER";
    } else if (this->p == 1){
        ofst<<"SEA";
    } else if (this->p == 2){
        ofst<<"LAKE";
    }
    ofst<<", codes / weight = " << this->CodesDividedByWeight()<<"\n";
}

void Fish::OutInFile(std::ofstream &ofst) {
    ofst<<"fish\n"<<this->name<<"\n"<<this->weight<<"\n"<<this->p<<"\n";
}
