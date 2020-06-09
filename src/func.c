#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>

int begin(char run[4])
{
    while (strcmp(run, "run") != 0) {
        printf("Keyboard Ninja. Напишите \"run\" для начала игры.\nЧтобы "
               "закончить напишите \"end\"\n");
        scanf("%s", run);
    }
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
    printf("Correct words: %d\nUncorrect words: %d\nTime: %lf\n", correct, uncorrect, time);
    exit(0);
}
