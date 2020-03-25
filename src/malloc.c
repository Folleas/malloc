/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** malloc
*/

#include "../include/malloc.h"

static mem_block_t *list = NULL;

void *malloc(size_t s)
{
    mem_block_t *new_block;
    mem_block_t *tmp = list;
    size_t size = align_memory(s);

    if (!list) {
        if (!(new_block = create_page(NULL, size)))
            return (NULL);
        list = new_block;
    }
    else {
        new_block = best_fit(list, size);
        if (!new_block)
            if (!(new_block = create_page(list, size + sizeof(mem_block_t))))
                return (NULL);
        else {
            new_block->free = false;
            if ((new_block->size + size) > sizeof(mem_block_t))
                split_block(new_block, size + sizeof(mem_block_t));
        }
    }
    return (new_block->address);
}

void *calloc(size_t nmemb, size_t size)
{
    char *tmp = malloc(nmemb * size);

    if (tmp) {
        for (size_t i = 0; i != nmemb; i++) {
            tmp[i] = '\0';
        }
    }
    return (tmp);
}

void free(void *ptr)
{
    mem_block_t *tmp = list;

    if (!ptr)
        return;
    while (tmp) {
        if (tmp->address == ptr) {
            tmp->free = true;
        }
        tmp = tmp->next;
    }
}