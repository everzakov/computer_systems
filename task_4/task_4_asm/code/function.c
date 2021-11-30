//
// Created by Efim Verzakov on 29.11.2021.
//
#include <stdio.h>

#include "extdata.h"
// Целевая функция для обощённого животного
double CodesDividedByWeight(void *a){
  double sum = 0;
  for (int i = 0; i<MAX_NAME_LEN-1; i++){
    sum+=*((char *)(a+i*charSize));
  }
  return sum/(*((int*)(a+MAX_NAME_LEN*charSize)));
}