#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Stacknode{
    int data;
    struct Stacknode* next;    
} Node;

Node * new_node(int data)
{
    Node* new=(Node *)(malloc(sizeof(Node)));
    new->data=data;
    new->next=NULL;
    return new;
}

bool isEmpty(Node *head)
{
    return !head;
}

void push(Node** head,int data)
{
    Node *new= new_node(data);
    new->next=*head;
    *head=new;
    printf("%d is pushed\n",data);
}

int pop(Node **head)
{
    Node *root=*head;
    if(isEmpty(root))
    return INT_MIN;
    int popped=root->data;
    *head=root->next;
    free(root);
    return popped;
}

int peek(Node *head)
{
    if(isEmpty(head))
    return INT_MAX;
    return head->data;
}

int main()
{
    Node * head=NULL;
    push(&head,10);
    push(&head,20);
    push(&head,30);
    push(&head,40);

    printf("%d popped element from stack\n",pop(&head));
    printf("%d top element in the stack\n",peek(head));
}