#include "ctest.h"
#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Примечание для первых двух тестов:
   Файл words.txt содержит 3 строчки:
   First
   Second
   Third */

/* В этом тесте мы проверяем количество
   строк, которая найдёт функция в файле */
CTEST(numbers_suite, correct_file_1)
{
    FILE* f = fopen("words1.txt", "r");
    int amount = 0;
    int maxlen = -1;
    max_len_amount_lines(&amount, &maxlen, f);
    int correct_amount = 3;
    ASSERT_EQUAL(correct_amount, amount);
}

/* В этом тесте мы проверяем работу
   функции в нахождении количества
   символов в самом большом слове файла */
CTEST(numbers_suite, correct_file_2)
{
    FILE* f = fopen("words1.txt", "r");
    int maxlen = -1;
    int amount = 0;
    max_len_amount_lines(&amount, &maxlen, f);
    int correct_maxlen = 6;
    ASSERT_EQUAL(correct_maxlen, maxlen);
}

/* В этом тесте мы проверяем работу
   функции в нахождении количества
   символов в самом большом слове пустого файла */
CTEST(numbers_suite, empty_file_3)
{
    FILE* f = fopen("words2.txt", "r");
    int maxlen = -1;
    int amount = 0;
    max_len_amount_lines(&amount, &maxlen, f);
    int correct_maxlen = 0;
    ASSERT_EQUAL(correct_maxlen, maxlen);
}

/* В этом тесте мы проверяем количество
   строк, которая найдёт функция в пустом файле */
CTEST(numbers_suite, empty_file_4)
{
    FILE* f = fopen("words2.txt", "r");
    int amount = 0;
    int maxlen = -1;
    max_len_amount_lines(&amount, &maxlen, f);
    int correct_amount = 0;
    ASSERT_EQUAL(correct_amount, amount);
}

/* Проверка функции удаленияпоследнего элемента строки */
CTEST(last_symbol, correct_string)
{
    const int correct_result = 0;
    int result;
    char* str[2];
    str[0] = malloc(4);
    str[0] = "sd";
    str[1] = malloc(4);
    str[1] = "ds";
    result = rm_last_sym(str, 2);
    ASSERT_EQUAL(correct_result, result);
}

/* Проверка функции установки локализации
    Установка английского языка */
CTEST(language, eng)
{
    int amount = 0;
    int maxlen = -1;
    char lang[4] = "eng";
    int result = 0;
    int const correct_result = 13;
    FILE* f = fopen("lang.cfg", "r");
    max_len_amount_lines(&amount, &maxlen, f);
    char* str[(amount - 2) / 2];
    language(lang, str, maxlen, amount);
    for (int i = 0; i < (amount - 2) / 2; i++) {
        if (strlen(str[i]) > 1) {
            result++;
        }
    }
    ASSERT_EQUAL(correct_result, result);
}

/* Проверка функции установки локализации
        Установка русского языка */
CTEST(language, rus)
{
    int amount = 0;
    int maxlen = -1;
    char lang[4] = "rus";
    int result = 0;
    int const correct_result = 13;
    FILE* f = fopen("lang.cfg", "r");
    max_len_amount_lines(&amount, &maxlen, f);
    char* str[(amount - 2) / 2];
    language(lang, str, maxlen, amount);
    for (int i = 0; i < (amount - 2) / 2; i++) {
        if (strlen(str[i]) > 1) {
            result++;
        }
    }
    ASSERT_EQUAL(correct_result, result);
}

/* Проверка функции открытия файла со словами выбранного языка
        Установка английского языка */
CTEST(set_lang, eng)
{
    const int correct_result = 2;
    int result;
    int maxlen = -1;
    int amount = 0;
    char lang[4] = "eng";
    FILE* f = fopen("lang.cfg", "r");
    max_len_amount_lines(&amount, &maxlen, f);
    fclose(f);
    char* str[(amount - 2) / 2];
    f = NULL;
    result = set_lang(lang, &f, str, maxlen, amount);
    ASSERT_EQUAL(correct_result, result);
}

/* Проверка функции открытия файла со словами выбранного языка
        Установка русского языка */
CTEST(set_lang, rus)
{
    const int correct_result = 1;
    int result;
    int maxlen = -1;
    int amount = 0;
    char lang[4] = "rus";
    FILE* f = fopen("lang.cfg", "r");
    max_len_amount_lines(&amount, &maxlen, f);
    fclose(f);
    char* str[(amount - 2) / 2];
    f = NULL;
    result = set_lang(lang, &f, str, maxlen, amount);
    ASSERT_EQUAL(correct_result, result);
}
