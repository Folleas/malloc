/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** additional
*/

#include "../include/malloc.h"

mem_block_t *best_fit(mem_block_t *head, size_t size)
{
    mem_block_t *blocks = head;
    mem_block_t *tmp = NULL;

    if (!blocks)
        return (NULL);
    while (blocks != NULL) {
        if (blocks->size >= size && blocks->free) {
            if (!tmp)
                tmp = blocks;
            else if (blocks->size < tmp->size)
                tmp = blocks;
            tmp->free = false;
        }
        blocks = blocks->next;
    }
    return (tmp);
}

size_t page_alloc(size_t size)
{
    size_t nb_page = 0;

    while (nb_page <= size) {
        nb_page += PAGE_SIZE;
    }
    return (nb_page);
}

mem_block_t *create_page(mem_block_t *head, size_t old_size)
{
    mem_block_t *new_block = sbrk(0);
    size_t size = page_alloc(old_size) + sizeof(mem_block_t);

    if (sbrk(size) == (void *) - 1)
        return (NULL);
    new_block->address = (void *)((long)new_block + sizeof(mem_block_t));
    new_block->free = false;
    new_block->size = old_size;
    new_block->next = NULL;
    if (head != NULL) {
        head->next = new_block;
    }
    new_block->prev = head;
    return (new_block);
}

void split_block(mem_block_t *block, size_t size)
{
    mem_block_t *new_block = (mem_block_t *)((long)block->address + block->size);

    new_block->address = (void *)((long)new_block + sizeof(mem_block_t));
    new_block->free = true;
    new_block->size = size;
    new_block->next = (mem_block_t *)((long)block->next);
    new_block->prev = (mem_block_t *)((long)block);
    block->size = size - sizeof(mem_block_t);
    block->next = new_block;
    block->free = false;
}

size_t align_memory(size_t size)
{
    size_t tmp = 2;

    while (tmp < size) {
        tmp *= 2;
    }
    return (tmp);
}