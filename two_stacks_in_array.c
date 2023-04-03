#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct two_stacks{
    int top1,top2;
    int *arr;
    int cap;
} stack;

stack * create(int capacity)
{
    stack *s=(stack *)(malloc(sizeof(stack)));
    s->top1=-1;
    s->top2=capacity;
    s->cap=capacity;
    s->arr=(int *)(malloc(sizeof(int)*s->cap));
    return s;
}

bool isFull(stack *s)
{
    if(s->top1 < s->top2 -1)
    return false;
    return true;
}

void push1(stack *s, int data)
{
    if(isFull(s))
    return;
    s->arr[++s->top1]=data;
}

void push2(stack *s, int data)
{
    if(isFull(s))
    return;
    s->arr[--s->top2]=data;
}

int pop1(stack *s)
{
    s->top1--;
}

int pop2(stack *s)
{
    s->top2++;
}

