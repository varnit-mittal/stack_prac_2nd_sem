#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<limits.h>

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

int area(int a[],int n)
{
    int *b1 = malloc(sizeof(int) * n);
    int *b2 = malloc(sizeof(int) * n);
    int max=0,i;
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
    return max;
}

void histogram(int r, int c,int a[][c])
{
    int i,j;
    int **h=(int **)(malloc(sizeof(int *)*(r+1)));
    int max=0;

    h[0]=calloc(c,sizeof(int));

    for(i=0;i<r;i++)
    {
        h[i+1]=calloc(c,sizeof(int));
        for(j=0;j<c;j++)
        {
            if(a[i][j]!=0)
            {
                h[i+1][j]=h[i][j]+a[i][j];
            }
            else
            {
                h[i+1][j]=0;
            }
            // printf("%d ",h[i+1][j]);
        }
        int ar=area(h[i+1],c);
        if(max<ar)
        max=ar;
    }
    printf("%d\n",max);
}

int main()
{
    int r,c;
    scanf("%d %d",&r,&c);
    int arr[r][c];
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    histogram(r,c,arr);
}
