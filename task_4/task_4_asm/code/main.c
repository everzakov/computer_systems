#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "constants.h"


void errMessage1() {
    printf("incorrect command line!\n"
           "  Waited:\n"
           "     command -f infile outfile01 outfile02\n"
           "  Or:\n"
           "     command -n number outfile01 outfile02\n");
}

void errMessage2() {
    printf("incorrect qualifier value!\n"
           "  Waited:\n"
           "     command -f infile outfile01 outfile02\n"
           "  Or:\n"
           "     command -n number outfile01 outfile02\n");
}


int main(int argc, char* argv[]) {
    unsigned char cont[maxSize];
    int len = 0;

    printf("intSize = %d\n", intSize);
    printf("charSize = %d\n", charSize);
    printf("boolSize = %d\n", boolSize);

    printf("MAX_NAME_LEN = %d\n", MAX_NAME_LEN);
    printf("MIN_WEIGHT = %d\n", MIN_WEIGHT);
    printf("nameSize = %d\n", nameSize);

    printf("LEN_TO_PRINT = %d\n", LEN_TO_PRINT);

    printf("beastSize = %d\n", beastSize);
    printf("PREDATORS = %d\n", PREDATORS);
    printf("HERBIVORES = %d\n", HERBIVORES);
    printf("INSECTIVORES = %d\n", INSECTIVORES);

    printf("birdSize = %d\n", birdSize);

    printf("fishSize = %d\n", fishSize);
    printf("RIVER = %d\n", RIVER);
    printf("SEA = %d\n", SEA);
    printf("LAKE = %d\n", LAKE);

    printf("animalSize = %d\n", animalSize);
    printf("FISH = %d\n", FISH);
    printf("BIRD = %d\n", BIRD);
    printf("BEAST = %d\n", BEAST);

    printf("Size of container = %d\n", sizeof(cont));

    if(argc != 5) {
        errMessage1();
        return 1;
    }

    printf("Start\n");
    if(!strcmp(argv[1], "-f")) {
        FILE* ifst = fopen(argv[2], "r");
        fprintf(stdout, "InContainer Start:\n");
        InContainer(cont, &len, ifst);
        fprintf(stdout, "InContainer End:\n");
    }
    else if(!strcmp(argv[1], "-n")) {
        int size = atoi(argv[2]);
        if((size < 1) || (size > 10000)) {
            printf("incorrect numer of figures = %d. Set 0 < number <= 10000\n",
                   size);
            return 3;
        }
        // системные часы в качестве инициализатора
        srand((unsigned int)(time(0)));
        // Заполнение контейнера генератором случайных чисел
        fprintf(stdout, "InRnd Start:\n");
        InRndContainer(cont, &len, size);
        fprintf(stdout, "InEnd Start:\n");
    }
    else {
        errMessage2();
        return 2;
    }
    fprintf(stdout, "Filled container:\n");
    OutContainer(cont, len, stdout);

    fprintf(stdout, "Out in File Start:\n");
    FILE* ofst1 = fopen(argv[3], "w");
    fprintf(ofst1, "Filled container:\n");
    OutContainer(cont, len, ofst1);
    fclose(ofst1);
    fprintf(stdout, "Out in File End:\n");

    // The 2nd part of task
    fprintf(stdout, "Out in File Start:\n");
    FILE* ofst2 = fopen(argv[4], "w");
    fprintf(stdout, "Sort Start:\n");
    sort(cont, len);
    fprintf(stdout, "Sort End:\n");
    fprintf(ofst1, "Sorted container:\n");
    OutContainer(cont, len, ofst1);
    fclose(ofst2);

    fprintf(stdout, "Out in File End:\n");


    //ClearContainer(&c);
    printf("Stop\n");
    return 0;
}
