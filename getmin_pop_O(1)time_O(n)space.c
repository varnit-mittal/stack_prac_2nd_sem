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
int peek(stack *s1) //returns the top element without removing it
{
    if(isEmpty(s1))
    return INT_MIN;
    return s1->arr[s1->top];
}

void push(stack *s1, int item,stack *x) //x is auxillary stack
{
    if(isFull(s1))
    return;
    if(isEmpty(s1)==true || item<=peek(x))
    {
        x->arr[++x->top]=item;
    }
    s1->arr[++s1->top]=item;
    // printf("Item Pushed\n");
}

void pop(stack *s1,stack *x)
{
    if(isEmpty(s1))
    return;
    if(peek(s1)==peek(x))
    {
        x->arr[x->top--];
    }
    s1->arr[s1->top--];
}


int getmin(stack *x)
{
    return(peek(x));
}

int main()
{
    stack *s,*x;
    int cap;
    scanf("%d",&cap);
    s=stack_creation(cap);
    x=stack_creation(cap);
    push(s,5,x);
    push(s,10,x);
    push(s,20,x);
    printf("%d\n",getmin(x));
    push(s,2,x);
    push(s,6,x);
    push(s,4,x);
    printf("%d\n",getmin(x));
    pop(s,x);
    pop(s,x);
    printf("%d\n",getmin(x));
    push(s,2,x);
    pop(s,x);
    printf("%d\n",getmin(x));
    push(s,1,x);
    pop(s,x);
    printf("%d\n",getmin(x));
    pop(s,x);
}