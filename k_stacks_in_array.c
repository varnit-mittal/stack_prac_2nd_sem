#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct k_stacks{
    int *arr,*top,*next;
    int k,free,cap;
} stack;

bool isFull(stack *s){
    if(s->free==-1)
    return true;
    return false;
}

bool isEmpty(stack *s,int key)
{
    if(s->top[key-1]==-1)
    return true;
    return false;
}

void create(stack *s, int n, int k)
{
    s->cap=n;
    s->k=k;
    s->arr=malloc(sizeof(int)*n);
    s->next=malloc(sizeof(int)*n);
    s->top=malloc(sizeof(int)*k);
    s->free=0;
    int i;
    for(i=0;i<k;i++)
    s->top[i]=-1;
    int m=1;
    for(i=0;i<n-1;i++)
    {
        s->next[i]=m;
        m++;
    }
    s->next[i]=-1;
}

void push(stack *s,int ele, int key)
{
    if(isFull(s))
    return;
    int i=s->free;
    s->free=s->next[i];
    s->next[i]=s->top[key-1];
    s->top[key-1]=i;
    s->arr[i]=ele;
}

void pop(int key,stack *s)
{
    if(isEmpty(s,key))
    return;
    int i=s->top[key-1];
    s->top[key-1]=s->next[i];
    s->next[i]=s->free;
    s->free=i;
}

int main()
{
    stack *s=(stack *)(malloc(sizeof(stack)));
    int n;
    int k;
    printf("Enter the size of array and number of nodes you want to insert");
    scanf("%d %d",&n,&k);
    create(s,n,k);
    printf("Enter no. of operation you want to perform ");
    int f;
    scanf("%d",&f);
    int i=0;
    for(;i<f;i++)
    {
        char *str=malloc(sizeof(char)*10);
        printf("Enter Command ");
        scanf("%s",str);
        if(strcmp(str,"push")==0)
        {
            printf("Enter value of key and element to insert ");
            int key,ele;
            scanf("%d %d",&key,&ele);
            push(s,ele,key);
        }
        if(strcmp(str,"pop")==0)
        {
            printf("Enter value of key ");
            int key;
            scanf("%d",&key);
            pop(key,s);
        }
    }
}