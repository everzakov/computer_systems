//
// Created by Efim Verzakov on 16.10.2021.
//

#ifndef __animal__
#define __animal__

#include <fstream>
#include "rnd.h"
#include "constants.h"

class Animal{
protected:
    static Random rnd3;
    static Random rnd26;
    static Random rnd2;

    char name[MAX_NAME_LEN];
    int weight;

public:

    // Деструктор обобщённого животного
    virtual ~Animal() {};
    // Ввод обобщенного животного
    static Animal *StaticIn(std::ifstream &ifst);
    // Ввод обобщенного животного
    virtual void In(std::ifstream &ifst) = 0;
    // Случайный ввод обобщенного животного
    static Animal *StaticInRnd();
    // Виртуальный метод ввода случайного животного
    virtual void InRnd() = 0;
    // Вывод обобщенного животного
    virtual void Out(std::ofstream &ofst) = 0;
    // Вывод случайного животного в файл
    virtual void OutInFile(std::ofstream &ofst) = 0;
    // Вычисление целевой функции животного
    double CodesDividedByWeight();

};
#endif // __animal__
