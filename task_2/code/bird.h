//
// Created by Efim Verzakov on 16.10.2021.
//

#ifndef __bird__
#define __bird__
#include "animal.h"

class Bird: public Animal{
public:
    virtual ~Bird() {};
    // Ввод птицы из файла
    virtual void In(std::ifstream &ifst);
    // Виртуальный метод ввода случайной птицы
    virtual void InRnd();
    // Вывод птицы
    virtual void Out(std::ofstream &ofst);
    // Вывод случайной птицы в файл
    virtual void OutInFile(std::ofstream &ofst);

private:
    bool flyRelationship;
};
#endif // __bird__
