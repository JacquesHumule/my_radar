/*
** EPITECH PROJECT, 2022
** task01
** File description:
** function that swaps the content of two integers, whose addresses are given
** as a parameter
*/

void my_swap(int *a, int *b)
{
    int buf = *a;
    *a = *b;
    *b = buf;
}
