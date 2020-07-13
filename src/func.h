#ifndef FUNC_H
#define FUNC_H
#include <stdio.h>
#include <stddef.h>

int main();
int begin(char* str[]);
void print(int correct, int uncorrect, double time, char* str[]);
void max_len_amount_lines(int* amount, int* maxlen, FILE* f);
int get_rand(int min, int max);
double wtime();
int set_lang(char lang[], FILE** f, char* str[], int maxlen, int amount);
void language(char lang[], char* str[], int maxlen, int amount);
int rm_last_sym(char* str[], int amount);
void give_name_playlist(char name[], size_t max_name);
void check_playlist(char name[], size_t max_name);
void give_words_playlist(FILE*** f);
void delete_all_playlist(FILE**** f, char name_playlist[]);
int rand_eng_char();
int rand_rus_char(int* buf_1, int* buf_2);

#endif
