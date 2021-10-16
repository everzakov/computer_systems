//
// Created by Efim Verzakov on 16.10.2021.
//

#include <iostream>
#include "animal.h"
#include "beast.h"
#include "fish.h"
#include "bird.h"

Random Animal::rnd2(1,2);
Random Animal::rnd3(1,3);
Random Animal::rnd26(1,26);

Animal* Animal::StaticIn(std::ifstream &ifst) {
    char type[5];
    ifst>>type;
    Animal* an = nullptr;
    if (!strcmp(type, "beast")){
        an = new Beast;
    }else if (!strcmp(type, "bird")){
        an = new Bird;
    }else if (!strcmp(type, "fish")){
        an = new Fish;
    }else{
        std::cout<<"Wrong type";
        exit(1);
    }
    an->In(ifst);
    return an;
}

Animal* Animal::StaticInRnd() {
    int type = Animal::rnd3.Get();
    Animal* an = nullptr;
    if (type == 1){
        an = new Beast;
    }else if (type == 2){
        an = new Bird;
    }else if (type == 3){
        an = new Fish;
    }
    an->InRnd();
    return an;
}

double Animal::CodesDividedByWeight() {
    int count = 0;
    for (int i = 0; i < strlen(this->name); ++i){
        count += int(this->name[i]);
    }
    return count * 1.0 / this->weight;
}
