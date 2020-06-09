#include "ctest.h"
#include "func.h"

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