#ifndef FUNC_H
#define FUNC_H
#include <stdio.h>

typedef struct {
    char* hello;
    char* getready;
    char* correct;
    char* uncorrect;
    char* co;
    char* un;
    char* time;
    char* write;
} setting_lang;

int begin(setting_lang* l);
void print(int correct, int uncorrect, double time, setting_lang* l);
void max_len_amount_lines(int* amount, int* maxlen, FILE* f);
int getrand(int min, int max);
double wtime();
int set_lang(char lang[], FILE** f, setting_lang* l);
void language(char lang[], setting_lang* l);
void rm_last_sym(setting_lang* l);

#endif
