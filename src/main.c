#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>

int main()
{
    FILE* f = fopen("words.txt", "r");
    if (f == NULL) {
        return 1;
    }

    int amount = 0;
    int maxlen = -1;
    max_len_amount_lines(&amount, &maxlen, f);
    char in_word[maxlen];
    char f_word[maxlen];
    char run[4];
    int str_num;
    char end[4] = "end";
    int uncorrect = 0;
    int correct = 0;
    int i;
    double time_start = 0, time_end = 0;

    if (begin(run) == 0) {
        while (1) {
            time_start = wtime();
            str_num = getrand(0, amount);
            fseek(f, 0, SEEK_SET);
            i = 0;
            while (i != str_num) {
                if (fscanf(f, "%s", f_word) != EOF) {
                    i++;
                }
            }
            printf("\"%s\"\n", f_word);
            printf("Write this word ");
            scanf("%s", in_word);
            if (strcmp(f_word, in_word) == 0) {
                printf("Слово верно\n");
                correct++;
            } else {
                if (strcmp(in_word, end) == 0) {
                    print(correct, uncorrect, time_end);
                } else {
                    printf("Слово неверно\n");
                    uncorrect++;
                }
            }
            time_end = time_end + wtime() - time_start;
        }
    }

    return 0;
}
