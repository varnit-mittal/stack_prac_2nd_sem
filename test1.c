#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}Node;

void insert(Node **head,int i)
{
    Node *new=(Node *)(malloc(sizeof(Node)));
    new->data=i;
    new->next=*head;
    *head=new;
}

void traverse(Node *head)
{
    Node *new=(Node *)(malloc(sizeof(Node)));
    new=head;
    while(new)
    {
        printf("%d ",new->data);
        new=new->next;
    }
    printf("\n");
}

Node *itt_rev(Node *head)
{
    if(head &&head->next)
    {
        Node *prev=NULL,*current=head,*new=NULL;
        while(current)
        {
            new=current->next;
            current->next=prev;
            prev=current;
            current=new;
        }
        head=prev;
    }
    return head;
}

int count2(Node *head)
{
    Node *p=head;
    if(!p)
    return 0;
    else
    return 1+count2(p->next);
}