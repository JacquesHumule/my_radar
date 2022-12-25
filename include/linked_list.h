/*
** EPITECH PROJECT, 2022
** B-CPE-110-BDX-1-1-pushswap-jacques.rathier
** File description:
** linked_list.h
*/

#ifndef LINKED_LIST_
    #define LINKED_LIST_
    #include <stddef.h>
    #include <stdlib.h>
    #define LT_NEXT(list) list = list->next

typedef struct linked_list_s {
    char *data;
    size_t len;
    struct linked_list_s *next;
} linked_list_t;

size_t ltlen(linked_list_t *head);
int ltal(linked_list_t **head, void *new_val);
int ltar(linked_list_t **head, void *new_val);
int ltfree(linked_list_t *list, void func(void *));
int ltan(linked_list_t **head, void *new_val, ssize_t n);
int ltswap(linked_list_t **head, int a, int b);
linked_list_t *ltpn(linked_list_t **head, ssize_t n);
linked_list_t *ltpl(linked_list_t **head);
linked_list_t *ltpr(linked_list_t **head);
int ltil(linked_list_t **head, linked_list_t *list);
int ltir(linked_list_t **head, linked_list_t *list);
int ltin(linked_list_t **head, linked_list_t *list, ssize_t n);


#endif //LINKED_LIST_
