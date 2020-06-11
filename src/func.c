#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

int begin()
{
    printf("Keyboard Ninja. Напишите \"ENTER\" для начала игры.\nЧтобы "
           "закончить напишите \"end\"\n");
    getchar();
    __fpurge(stdin);
    int tik = 0;
    printf("Приготовьтесь\n");
    while (1) {
        if (tik < 3) {
            printf("%d...\n", 3 - tik);
        } else {
            printf("RUN!\n");
            break;
        }
        sleep(1);
        tik++;
    }
    sleep(1);
    system("clear");
    return 0;
}

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

void print(int correct, int uncorrect, double time)
{
    printf("Correct words: %d\nUncorrect words: %d\nTime: %lf\n",
           correct,
           uncorrect,
           time);
    exit(0);
}

void max_len_amount_lines(int* amount, int* maxlen, FILE* f)
{
    char ch;
    int i = 0;
    while (1) {
        ch = fgetc(f);
        if ((ch == '\n') || (ch == EOF)) {
            if (*maxlen < i)
                *maxlen = i;
            i = 0;
            if (ch == EOF)
                break;
            ++*amount;
        } else
            i++;
    }
    fseek(f, 0, SEEK_SET);
}

int getrand(int min, int max)
{
    srand(time(NULL));
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}
