#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

//assuming all elements are positive and negative
typedef struct Stack{
    int top;
    int capacity;
    int *arr;
    int min;
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
    if(isEmpty(s1))
    {
        s1->min=item;
        s1->arr[++s1->top]=item;
    }
    else if(item<=s1->min)
    {
        s1->arr[++s1->top]=2*item-s1->min;
        s1->min=item;
    }
    else
    s1->arr[++s1->top]=item;
}
int peek(stack *s1) //returns the top element without removing it
{
    int t=s1->arr[s1->top];
    return (t<=s1->min)? s1->min:t;
}

void pop(stack *s1)
{
    if(isEmpty(s1))
    return;
    int t=s1->arr[s1->top];
    if(t<=s1->min)
    {
        int res=s1->min;
        s1->min=2*s1->min-t;
        s1->arr[s1->top--];
    }
    else
    {
        s1->arr[s1->top--];
    }
}


int getmin(stack *s)
{
    return s->min;
}

int main()
{
    stack *s=stack_creation(8);
    push(s,5);
    push(s,10);
    printf("%d\n",getmin(s));
    push(s,20);
    push(s,-1);
    printf("%d\n",getmin(s));
    // push(s,6);
    push(s,4);
    printf("%d\n",getmin(s));
    pop(s);
    pop(s);
    printf("%d\n",getmin(s));
    push(s,2);
    printf("%d\n",getmin(s));
    pop(s);
    push(s,1);
    printf("%d\n",getmin(s));
    pop(s);
    pop(s);
    printf("%d\n",getmin(s));
}

