#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>

int main()
{
    typedef struct {
        char name[20];
    } type;
    char run[4];
    type worrd;
    char i = 0;
    char word[20];
    char end[10] = "end";
    int uncorrect = 0;
    int correct = 0;
    FILE* f = fopen("words.txt", "r");
    if (begin(run) == 0) {
        while (fscanf(f, "%s", worrd.name) != EOF) {
            printf("\"%s\"\n", worrd.name);
            printf("Write this word ");
            scanf("%s", word);
            if (strcmp(worrd.name, word) == 0) {
                printf("Слово верно\n");
                correct++;
            } else {
                if (strcmp(word, end) == 0) {
                    print(correct, uncorrect);
                } else {
                    printf("Слово неверно\n");
                    uncorrect++;
                }
            }
            i++;
        }
        print(correct, uncorrect);
    }
    return 0;
}
