/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** utils
*/

#include "../include/malloc.h"

void *realloc(void *ptr, size_t size)
{
    if (!ptr)
        return (malloc(size));
    return (malloc(size));
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    (void)nmemb;
    if (!ptr)
        return (malloc(size));
    return (malloc(size));
}
