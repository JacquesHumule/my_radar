/*
** EPITECH PROJECT, 2022
** push_swap
** File description:
** linked_list_3.c
*/

#include "linked_list.h"

int ltir(linked_list_t **head, linked_list_t *list)
{
    list->next = NULL;
    while (*head != NULL) {
        (*head)->len++;
        head = &(*head)->next;
    }
    *head = list;
    return 0;
}
