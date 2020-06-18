#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>

int main()
{
    int amount = 0;
    int maxlen = -1;
    FILE* f = fopen("lang.cfg", "r");
    max_len_amount_lines(&amount, &maxlen, f);
    fclose(f);
    f = NULL;
    char* str[(amount - 2) / 2];

    char lang[4];
    while (f == NULL) {
        printf("Choose language\neng\nrus\nother\n");
        scanf("%s", lang);
        set_lang(lang, &f, str, maxlen, amount);
    }

    amount = 0;
    maxlen = -1;
    max_len_amount_lines(&amount, &maxlen, f);
    char in_word[maxlen * 2];
    char f_word[maxlen * 2];
    int str_num;
    char end[] = "end";
    char endr[] = "конец";
    int uncorrect = 0;
    int correct = 0;
    int i;
    double time_start = 0, time_end = 0;

    getchar();
    if (begin(str) == 0) {
        while (1) {
            time_start = wtime();
            str_num = getrand(0, amount - 1);
            fseek(f, 0, SEEK_SET);
            i = 0;
            while (i != str_num) {
                if (fscanf(f, "%s", f_word) != EOF) {
                    i++;
                }
            }
            printf("\"%s\"\n", f_word);
            printf("%s ", str[7]);
            scanf("%s", in_word);
            if (strcmp(f_word, in_word) == 0) {
                printf("%s\n", str[2]);
                correct++;
            } else {
                if ((strcmp(in_word, end) == 0)
                    || (strcmp(in_word, endr) == 0)) {
                    print(correct, uncorrect, time_end, str);
                } else {
                    printf("%s\n", str[3]);
                    uncorrect++;
                }
            }
            time_end = time_end + wtime() - time_start;
        }
    }

    return 0;
}
