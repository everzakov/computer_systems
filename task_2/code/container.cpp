//
// Created by Efim Verzakov on 16.10.2021.
//

#include <iostream>
#include "container.h"

//------------------------------------------------------------------------------
// Конструктор контейнера
Container::Container(): len{0} { }

//------------------------------------------------------------------------------
// Деструктор контейнера
Container::~Container() {
    Clear();
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void Container::Clear() {
    for(int i = 0; i < len; i++) {
        delete cont[i];
    }
    len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
void Container::In(std::ifstream &ifst) {
    int n = 0;
    ifst >> n;
    while (!ifst.eof() && n > 0) {
        if ((cont[len] = Animal::StaticIn(ifst)) != 0) {
            len++;
            n--;
        }
    }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
void Container::InRnd(int size) {
    while(len < size) {
        if((cont[len] = Animal::StaticInRnd()) != nullptr) {
            len++;
        }
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void Container::Out(std::ofstream &ofst) {
    ofst << "Container contains " << len << " elements.\n";
    for(int i = 0; i < len; i++) {
        ofst << i << ": ";
        cont[i]->Out(ofst);
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void Container::OutInFile(std::ofstream &ofst) {
    ofst << this->len;
    for(int i = 0; i < len; i++) {
        this->cont[i]->OutInFile(ofst);
    }
}

//------------------------------------------------------------------------------
// Вычисление суммы периметров всех животных в контейнере
double Container::CodesDividedByWeight() {
    double sum = 0.0;
    for(int i = 0; i < len; i++) {
        sum += cont[i]->CodesDividedByWeight();
    }
    return sum;
}

//------------------------------------------------------------------------------
// Сортировка животных в контейнере
void Container::Sort() {
    for (int i = 0; i<len-1; i++){
        int i_max = i;
        for (int j = i+1; j<len; j++){
            if (this->cont[j]->CodesDividedByWeight() > this->cont[i_max]->CodesDividedByWeight()){
                Animal * tmp = this->cont[i_max];
                cont[i_max] = cont[j];
                cont[j] = tmp;
            }
        }
    }
}