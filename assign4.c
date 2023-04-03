#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include<limits.h>
typedef struct LRUCache
{
    int key;
    int val;
    struct LRUCache *next;
} lru;

void swapNodes(lru **head_ref, int y)
{
    lru *p = *head_ref;
    lru *q = *head_ref;
    int j = 0;
    if (p != NULL && p->next != NULL)
    {
        while (p->next != NULL)
        {
            if (p->next->key == y)
            {
                j = 1;
                break;
            }
            p = p->next;
        }
        if (j == 1)
        {
            lru *a = p->next->next;
            lru *b = p->next;
            p->next = a;
            b->next = q;
            *head_ref = b;
        }
    }
}

int push(lru **head, int key, int val)
{
    lru *p = *head;
    if (p != NULL && p->key == key)
    {
        (*head)->val = val;
        return 0;
    }
    if (p == NULL)
    {
        lru *new = (lru *)(malloc(sizeof(lru)));
        new->key = key;
        new->val = val;
        new->next = NULL;
        *head = new;
        return 1;
    }
    if (p != NULL && p->key != key)
    {
        lru *new = (lru *)(malloc(sizeof(lru)));
        new->key = key;
        new->val = val;
        new->next = p;
        *head = new;
        return 1;
    }
}
void del_at_end(lru *head)
{
    lru *p = head;
    if (p != NULL && p->next != NULL)
    {
        lru *q = p->next;
        while (q->next != NULL)
        {
            p = p->next;
            q = p->next;
        }
        p->next = NULL;
        free(q);
    }
}

int get(lru *head, int key)
{
    if (!head)
        return -1;
    if (head->key == key)
        return head->val;
    else
        return -1;
}
int main()
{
    char *str = malloc(sizeof(char) * 20);
    scanf("%s", str);
    int cap;
    scanf("%d", &cap);
    int store = 0;
    int n;
    scanf("%d", &n);
    int i;
    lru *stack = NULL;
    int arr[n];
    for (i = 0; i < n; i++)
    {
        char *inp = malloc(sizeof(char) * 20);
        scanf("%s", inp);
        if (strcmp(inp, "put") == 0)
        {
            int key, val;
            scanf("%d %d", &key, &val);
            if (stack != NULL && stack->next != NULL)
                swapNodes(&stack, key);
            if (push(&stack, key, val))
            {
                arr[i] = INT_MIN;
                store++;
            }
            else
                arr[i] = INT_MIN;
            if (store > cap)
            {
                store--;
                del_at_end(stack);
            }
        }
        if (strcmp(inp, "get") == 0)
        {
            int key;
            scanf("%d", &key);
            if (stack != NULL && stack->next != NULL)
                swapNodes(&stack, key);
            arr[i] = get(stack, key);
        }
    }
    for (i = 0; i < n; i++)
    {
        if (arr[i] == INT_MIN)
            printf("null ");
        else
            printf("%d ", arr[i]);
    }
    printf("\n");
}