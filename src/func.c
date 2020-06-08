#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int begin(char run[4])
{
    while (strcmp(run, "run") != 0) {
        printf("Keyboard Ninja. Напишите \"run\" для начала игры.\nЧтобы "
               "закончить напишите \"end\"\n");
        scanf("%s", run);
    }
    return 0;
}

void print(int correct, int uncorrect)
{
    printf("Correct words: %d\nUncorrect words: %d\n", correct, uncorrect);
    exit(0);
}
