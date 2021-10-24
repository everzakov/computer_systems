//
// Created by Efim Verzakov on 16.10.2021.
//

#include "bird.h"

void Bird::In(std::ifstream &ifst) {
    ifst >> this->name >> this->weight >> this->flyRelationship;
}

void Bird::InRnd() {
    for (size_t i = 0; i < MAX_NAME_LEN; ++i) {
        this->name[i] = char('a' + (this->rnd26.Get()-1));
    }
    this->name[MAX_NAME_LEN - 1] = '\0';
    this->weight = Animal::rnd26.Get();
    int flyRelationship = Animal::rnd2.Get();
    if (flyRelationship == 1){
        this->flyRelationship = false;
    }else{
        this->flyRelationship = true;
    }
}

void Bird::Out(std::ofstream &ofst) {
    ofst << "This is Bird: name = "<<this->name<<", weight = "<<this->weight<<", flyRelationship = ";
    ofst << ((this->flyRelationship)? "true":"false");
    ofst<<", codes / weight = " << this->CodesDividedByWeight()<<"\n";
}

void Bird::OutInFile(std::ofstream &ofst) {
    ofst<<"\nbird\n"<<this->name<<"\n"<<this->weight<<"\n"<<this->flyRelationship;
}