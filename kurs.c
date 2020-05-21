#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int print(int correct, int uncorrect)
{
    printf("Correct words: %d\nUncorrect words: %d\n", correct, uncorrect);
    exit(0);
}

int main()
{
    struct words {
        char name[20];
    };
    struct words worrd;
    char i = 0;
    char word[20];
    char end[10] = "end";
    int uncorrect = 0;
    int correct = 0;
    FILE* f = fopen("words.txt", "r");
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
    return 0;
}
