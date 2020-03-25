/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** main
*/

#include "../include/malloc.h"
#include <unistd.h>
#include <string.h>

int main(void)
{
    printf("first\n");
    char *str = malloc(sizeof(char) * 90000);
    for (int i = 0; i != 89999; i++)
        str[i] = 'a';
    str[89999] = '\0';
    printf("%p\n", str);
    free(str);
    char *str2 = malloc(sizeof(char) * 3);
    str2 = strcpy(str2, "bb");
    printf("%p\n", str2);
    free(str2);
    char *str4 = malloc(sizeof(char) * 10);
    str4 = strcpy(str4, "ccccccccc");
    printf("%p\n", str4);
    char *str5 = malloc(sizeof(char) * 10);
    str5 = strcpy(str5, "ccccccccc");
    printf("%p\n", str5);
    char *str6 = malloc(sizeof(char) * 10);
    str6 = strcpy(str6, "ccccccccc");
    printf("%p\n", str6);
    char *str7 = malloc(sizeof(char) * 10);
    str7 = strcpy(str7, "ccccccccc");
    printf("%p\n", str7);
    char *str8 = malloc(sizeof(char) * 10);
    str8 = strcpy(str8, "ccccccccc");
    printf("%p\n", str8);
    return (0);
}