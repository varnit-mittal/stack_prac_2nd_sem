#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Stack{
    int top;
    unsigned capacity;
    int *arr;
}stack;

bool isFull(stack *s1)
{
    return s1->top==s1->capacity-1;
}

bool isEmpty(stack *s1)
{
    return s1->top==-1;
}

stack * stack_creation(unsigned capacity)
{
    stack *s1=(stack *)(malloc(sizeof(stack)));
    s1->capacity=capacity;
    s1->top=-1;
    s1->arr=(int *)(malloc(sizeof(int)*capacity));
    return s1;
}

void push(stack *s1, int item)
{
    if(isFull(s1))
    return;
    s1->arr[++s1->top]=item;
    printf("Item Pushed\n");
}

int pop(stack *s1)
{
    if(isEmpty(s1))
    return INT_MIN;
    return s1->arr[s1->top--];
}

int peek(stack *s1) //returns the top element without removing it
{
    if(isEmpty(s1))
    return INT_MIN;
     return s1->arr[s1->top];
}

int main()
{
    stack *s1=stack_creation(100);
    // printf("%d"/,s1->top);
    push(s1,10);
    push(s1,15);
    push(s1,20);
    push(s1,30);
    printf("%d popped from the stack\n",pop(s1));
    printf("%d popped from the stack\n",pop(s1));
    printf("%d popped from the stack\n",pop(s1));
    printf("%d popped from the stack\n",pop(s1));
}