//
// Created by Efim Verzakov on 16.10.2021.
//

#ifndef __beast__
#define __beast__
#include "animal.h"

class Beast: public Animal{
public:
    virtual ~Beast() {};
    // Ввод зверя из файла
    virtual void In(std::ifstream &ifst);
    // Виртуальный метод ввода случайного зверя
    virtual void InRnd();
    // Вывод зверя
    virtual void Out(std::ofstream &ofst);
    // Вывод случайного зверя в файл
    virtual void OutInFile(std::ofstream &ofst);

private:
    enum type{PREDATORS, HERBIVORES, INSECTIVORES} t;
};

#endif // __beast__
