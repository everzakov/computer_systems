//
// Created by Efim Verzakov on 16.10.2021.
//

#ifndef __fish__
#define __fish__
#include "animal.h"

class Fish: public Animal{
public:
    virtual ~Fish() {};
    // Ввод рыбы из файла
    virtual void In(std::ifstream &ifdt);
    // Виртуальный метод ввода случайной рыбы
    virtual void InRnd();
    // Вывод рыбы
    virtual void Out(std::ofstream &ofst);
    // Вывод случайной рыбы в файл
    virtual void OutInFile(std::ofstream &ofst);

private:
    enum place {RIVER, SEA, LAKE} p;
};

#endif // __fish__
