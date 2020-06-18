#ifndef FUNC_H
#define FUNC_H
#include <stdio.h>

int main();
int begin(char* str[]);
void print(int correct, int uncorrect, double time, char* str[]);
void max_len_amount_lines(int* amount, int* maxlen, FILE* f);
int getrand(int min, int max);
double wtime();
int set_lang(char lang[], FILE** f, char* str[], int maxlen, int amount);
void language(char lang[], char* str[], int maxlen, int amount);
void rm_last_sym(char* str[], int amount);
void give_name_playlist(char name[30]);
void give_words_playlist(FILE*** f);
void delete_all_playlist(FILE**** f, char name_playlist[30]);

#endif
