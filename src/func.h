#ifndef FUNC_H
#define FUNC_H
#include <stdio.h>

int begin();
void print(int correct, int uncorrect, double time);
void max_len_amount_lines(int* amount, int* maxlen, FILE* f);
int getrand(int min, int max);
double wtime();

#endif
