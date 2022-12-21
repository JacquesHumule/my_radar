/*
** EPITECH PROJECT, 2022
** push_swap
** File description:
** linked_list_2.c
*/

#include <stdlib.h>
#include "linked_list.h"

linked_list_t *ltpr(linked_list_t **head)
{
    while ((*head)->next) {
        (*head)->len--;
        head = &(*head)->next;
    }
    linked_list_t *out = *head;
    *head = NULL;
    return out;
}

linked_list_t *ltpn(linked_list_t **head, ssize_t n)
{
    if (n < 0) n += (ssize_t) ltlen(*head) + 1;
    if (n > (ssize_t) ltlen(*head) - 1) return NULL;
    for (int i = 0; i < n - 1; i++) {
        (*head)->len--;
        head = &(*head)->next;
    }
    linked_list_t *out = (*head)->next;
    (*head)->next = (*head)->next->next;
    return out;
}

int ltswap(linked_list_t **head, int a, int b)
{
    int len = ltlen(*head);
    if (a < 0) a += len + 1;
    if (b < 0) b += len + 1;
    if (a >= len || b >= len || a == b) return 84;
    if (a > b) return ltswap(head, b, a);
    linked_list_t *rst = *head;
    for (int i = 0; i < a; i++) head = &(*head)->next;
    linked_list_t **alt = &(*head);
    linked_list_t *ano = *head;
    linked_list_t *ant = (*head)->next;
    head = &rst;
    for (int i = 0; i < b; i++) head = &(*head)->next;
    linked_list_t *bnt = (*head)->next;
    *alt = *head;
    (*head)->next = ant;
    if (a != 0) head = &rst;
    for (int i = 0; i < b; i++) head = &(*head)->next;
    *head = ano;
    ano->next = bnt;
    return 0;
}

int ltfree(linked_list_t *list, void func(void *))
{
    if (list != NULL) {
        if (func != NULL)
            func(list->data);
        ltfree(list->next, func);
        free(list);
    }
    return 0;
}

int ltil(linked_list_t **head, linked_list_t *list)
{
    list->next = *head;
    if (*head == NULL)
        list->len = 1;
    else
        list->len = (*head)->len;
    *head = list;
    return 0;
}
