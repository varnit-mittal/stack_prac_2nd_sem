#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct arr_queue{
    int front,rear,size;
    unsigned capacity;
    int *arr;
} arr_q1;

arr_q1 *create(unsigned capacity)
{
    arr_q1 * que=(arr_q1 *)(malloc(sizeof(arr_q1)));
    que->capacity=capacity;
    que->front=que->size=0;
    que->rear=-1;
    que->arr=(int *)(malloc(sizeof(int)*(que->capacity)));
    return que;
}

/*
Enqueue = adds an element to the end of the queue
Dequeue= removes the elements from the queue
Peek or front = data at the front node without deleting it
rear= data at the rear end without deleting it
isFull - validates if the queue is full
isNull - checks if the queue is empty
*/

