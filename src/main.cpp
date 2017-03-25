//
// Created by baile_000 on 3/25/2017.
//
#include <stdio.h>
#include <stdlib.h>
#include "InsertionSort.cpp"

int main()
{
    struct node<int>* a = NULL;

    InsertionSort<int> list;

    list.push(&a, 5);
    list.push(&a, 20);
    list.push(&a, 4);
    list.push(&a, 3);
    list.push(&a, 30);
    list.push(&a, 1);

    printf("Linked List before sorting \n");
    list.print(a);

    list.sort(&a);

    printf("\nLinked List after sorting \n");
    list.print(a);

    return 0;
}
