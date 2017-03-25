//
// Created by Adam Johnson on 3/21/17.
//

#include <iostream>
#include "InsertionSort.h"

template <typename T>
void InsertionSort<T>::push(struct node<T>** headRef, T const &data) {
    struct node<T>* newNode = new node<int>;
    newNode->data = data;
    newNode->next = (*headRef);
    (*headRef) = newNode;
}

template <typename T>
void InsertionSort<T>::insert(struct node<T>** headRef, struct node<T>* newNode) {
    struct node<T>* current;

    if (*headRef == NULL || (*headRef)->data >= newNode->data){
        newNode->next = *headRef;
        *headRef = newNode;
    }
    else {
        current = *headRef;
        while (current->next != NULL && current->next->data < newNode->data){
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

template <typename T>
void InsertionSort<T>::sort(struct node<T>** headRef) {
    struct node<T>* sorted = NULL;
    struct node<T>* current = *headRef;
    while (current != NULL){
        struct node<T>* next = current->next;

        insert(&sorted, current);

        current = next;
    }
    *headRef = sorted;
}

template <typename T>
void InsertionSort<T>::print(struct node<T>* head) {
    struct node<T>* temp = head;

    while (temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

template <typename T>
InsertionSort<T>::~InsertionSort(){
    struct node<T>* currNode = head;
    struct node<T>* nextNode = head;
    while (nextNode){
        currNode = nextNode;
        nextNode = currNode -> next;
        if (nextNode) delete currNode;
    }
}