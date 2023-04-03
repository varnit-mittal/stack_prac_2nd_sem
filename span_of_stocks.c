#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Stack{
    int top;
    int capacity;
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

stack * stack_creation(int capacity)
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
    // printf("Item Pushed\n");
}

void pop(stack *s1)
{
    if(isEmpty(s1))
    return;
    s1->arr[s1->top--];
}

int peek(stack *s1) //returns the top element without removing it
{
    if(isEmpty(s1))
    return INT_MIN;
    return s1->arr[s1->top];
}

int main()
{
    int n;
    stack *s =(stack *)(malloc(sizeof(stack)));
    scanf("%d",&n);
    s=stack_creation(n);
    int i;
    int arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",arr+i);
    }
    push(s,0);
    for(i=0;i<n;i++)
    {
        while(isEmpty(s)==false && arr[peek(s)]<=arr[i])
        pop(s);
        isEmpty(s)?printf("%d ",i+1):printf("%d ",i-peek(s));
        push(s,i);
    }
    printf("\n");
}
