//
// Created by Adam Johnson on 3/21/17.
//

#ifndef IT279GROUPPROJECT2_INSERTIONSORT_H
#define IT279GROUPPROJECT2_INSERTIONSORT_H

template <typename T>
struct node {
    T data;
    node* next;
};

template <typename T>
class InsertionSort {

public:
    void push(struct node<T>** headRef, T const& data);
    void insert(struct node<T>** headRef, struct node<T>* newNode);
    void sort(struct node<T>** headRef);
    void print(struct node<T>* head);

    ~InsertionSort();

private:
    struct node<T>* head = 0;
    int listLength = 0;

};


#endif //IT279GROUPPROJECT2_INSERTIONSORT_H
