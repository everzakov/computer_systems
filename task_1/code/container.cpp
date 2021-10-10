//------------------------------------------------------------------------------
// container.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------
#include <iostream>

#include "container.h"

//------------------------------------------------------------------------------
// Инициализация контейнера
void Init(container &c) {
    std::cout << "Init\n";
    c.len = 0;
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void Clear(container &c) {
    c.len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
void In(container &c, std::ifstream &ifst) {
    int number = 0;
    ifst >> number;
    if (number <= 20) {
        while (!ifst.eof()) {
            if ((c.cont[c.len] = In(ifst)) != nullptr) {
                c.len++;
            }
        }
    }else{
        InRnd(c, number);
    }
}

void OutInFile(container&c, std::ofstream &ofst){
    ofst<<c.len<<"\n";
    for (int i = 0; i<c.len; i++){
        OutInFile(*c.cont[i], ofst);
    }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
void InRnd(container &c, int size) {
    std::cout << "Start Rnd\n";
    while(c.len < size) {
        if ((c.cont[c.len] = InRnd()) != nullptr) {
            c.len++;
        }
    }
    std::cout << "End Rnd\n";
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void Out(container &c, std::ofstream &ofst) {
    ofst << "Container contains " << c.len << " elements." << "\n";
    for(int i = 0; i < c.len; i++) {
        ofst << i << ": ";
        Out(*c.cont[i], ofst);
    }
}

//------------------------------------------------------------------------------
// Вычисление суммы периметров всех фигур в контейнере
void sort(container &c) {
    for (int i = 0; i<c.len-1; i++){
        int i_max = i;
        for (int j = i+1; j<c.len; j++){
            if (CodesDividedByWeight(*c.cont[j]) > CodesDividedByWeight(*c.cont[i_max])){
                animal * tmp = c.cont[i_max];
                c.cont[i_max] = c.cont[j];
                c.cont[j] = tmp;
            }
        }
    }
}


