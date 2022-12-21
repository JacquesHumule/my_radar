/*
** EPITECH PROJECT, 2022
** B-CPE-110-BDX-1-1-pushswap-jacques.rathier
** File description:
** linked_list.c
*/

#include <malloc.h>
#include "linked_list.h"

int ltal(linked_list_t **head, void *new_val)
{
    linked_list_t *new_node = malloc(sizeof(linked_list_t));
    if (!new_node) return 84;
    new_node->data = new_val;
    new_node->next = *head;
    if (*head == NULL)
        new_node->len = 1;
    else
        new_node->len = (*head)->len + 1;
    *head = new_node;
    return 0;
}

int ltar(linked_list_t **head, void *new_val)
{
    linked_list_t *new_node = malloc(sizeof(linked_list_t));
    if (!new_node) return 1;
    new_node->data = new_val;
    new_node->next = NULL;
    new_node->len = 1;
    while (*head != NULL) {
        (*head)->len++;
        head = &(*head)->next;
    }
    *head = new_node;
    return 0;
}

size_t ltlen(linked_list_t *head)
{
    if (head == NULL)
        return 0;
    head->len = 1 + ltlen(head->next);
    return head->len;
}

int ltan(linked_list_t **head, void *new_val, ssize_t n)
{
    if (n < 0) n += (ssize_t) ltlen(*head) + 1;
    if (n > (ssize_t) ltlen(*head)) return 84;
    for (int i = 0; i < n; i++) {
        (*head)->len++;
        head = &(*head)->next;
    }
    linked_list_t *new_node = malloc(sizeof(linked_list_t));
    new_node->next = (*head);
    new_node->data = new_val;
    *head = new_node;
    return 0;
}

linked_list_t *ltpl(linked_list_t **head)
{
    linked_list_t *out = *head;
    *head = (*head)->next;
    return out;
}
