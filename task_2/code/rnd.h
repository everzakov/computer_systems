//
// Created by Efim Verzakov on 16.10.2021.
//

#ifndef __rnd__
#define __rnd__

#include <cstdlib>
#include <ctime>

class Random {
public:
    Random(int f, int l) {
        if (f <= l) {
            first = f;
            last = l;
        } else {
            first = l;
            last = f;
        }
        // системные часы в качестве инициализатора
        srand(static_cast<unsigned int>(time(0)));
    }

    // Генерация случайного числа в заданном диапазоне
    int Get() { return rand() % (last - first + 1) + first; }

private:
    int first;
    int last;
};

#endif // __rnd__
