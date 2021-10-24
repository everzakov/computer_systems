//
// Created by Efim Verzakov on 16.10.2021.
//

#ifndef __container__
#define __container__
#include "animal.h"
class Container {
public:
    Container();
    ~Container();

    // Ввод содержимого контейнера из указанного потока
    void In(std::ifstream &ifst);
    // Случайный ввод содержимого контейнера
    void InRnd(int size);
    // Вывод содержимого контейнера в указанный поток
    void Out(std::ofstream &ofst);
    // Вывод содержимого контейнера в файл
    void OutInFile(std::ofstream &ofst);
    // Вычисление целевой функции для всех животных в контейнере
    double CodesDividedByWeight();
    // Сортировка контейнера
    void Sort();

private:
    void Clear();    // Очистка контейнера от данных
    int len; // текущая длина
    Animal* cont[10000];
};

#endif // __container__
