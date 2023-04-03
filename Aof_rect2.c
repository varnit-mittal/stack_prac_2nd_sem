#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Stack
{
    int top;
    int capacity;
    int *arr;
} stack;

bool isFull(stack *s1)
{
    return s1->top == s1->capacity - 1;
}

bool isEmpty(stack *s1)
{
    return s1->top == -1;
}

stack *stack_creation(int capacity)
{
    stack *s1 = (stack *)(malloc(sizeof(stack)));
    s1->capacity = capacity;
    s1->top = -1;
    s1->arr = (int *)(malloc(sizeof(int) * capacity));
    return s1;
}

void push(stack *s1, int item)
{
    if (isFull(s1))
        return;
    s1->arr[++s1->top] = item;
    // printf("Item Pushed\n");
}

void pop(stack *s1)
{
    if (isEmpty(s1))
        return;
    s1->arr[s1->top--];
}

int peek(stack *s1) // returns the top element without removing it
{
    if (isEmpty(s1))
        return INT_MIN;
    return s1->arr[s1->top];
}

void prev_smaller(int arr[], int a[], int n)
{
    stack *s = stack_creation(n);
    int i;
    for (i = 0; i < n; i++)
    {
        while (isEmpty(s) == false && a[peek(s)] >= a[i])
            pop(s);
        arr[i] = isEmpty(s) ? -1 : peek(s);
        push(s, i);
    }
}

void next_smaller(int arr[], int a[], int n)
{
    stack *s = stack_creation(n);
    int i;
    for (i = n - 1; i >= 0; i--)
    {
        while (isEmpty(s) == false && a[peek(s)] >= a[i])
            pop(s);
        arr[i] = isEmpty(s) ? -1 : peek(s);
        push(s, i);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    int max = 0, i;
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int *b1 = malloc(sizeof(int) * n);
    int *b2 = malloc(sizeof(int) * n);
    next_smaller(b2, a, n);
    prev_smaller(b1, a, n);
    for (i = 0; i < n; i++)
    {
        int k = b2[i] - b1[i] - 1;
        if(b2[i]==-1 && b1[i]==-1)
        {
            b2[i]=1;
            b1[i]=1;
            k=n;
        }
        if(b2[i] == -1)
        {
            b2[i] = n - i;
            k = b2[i] + i - 1 - b1[i];
        }
        if (b1[i] == -1)
        {
            b1[i] = i + 1;
            k = b1[i] + b2[i] - i - 1;
        }
        // printf("%d\n",k)
        int area = a[i] * (k);
        if (max < area)
            max = area;
    }
    printf("%d\n", max);
}